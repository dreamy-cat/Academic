#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include <time.h>

//  "Как я провёл лето в деревне!". Версия 32-бита. :)

//  Все графики выводятся в консоль, соотношение сторон 2/3 по шрифту или по вкусу. Шрифт желательно растровый.
//  Размеры буфера экрана как удобней, но по умолчанию 128*32(4кб). Ширина консоли примерно на 160 или больше.
//  Внимание, если трубуется изменение буффера экрана по горизонтали, то не забыть изменить ширину вывода в 'print_screen'.
//  Или можно просто раскоментировать более медленный, посимвольный вывод. Ограничения по динамической памяти 1Гб.
//  Если требуется освободить память и выгрузить все устройства, то в меню глобальных настроек выбрать 0.

//  Во всех приборах при загрузке производится попытка найти названия полей структуры на второй строчке, сразу после названия.
//  Если есть хоть один параметр и дата-время, то данные по прибору загружаются в память, иначе просто остается активным.
//  Параметры считаются совпавшими, если есть вхождение ключевого названия поля, например "weather_temp" или "bme280_temp"
// поля содержат ключевое слово "temp", что будет итерпретироваться как температура, загружается только первый параметр.
// Если требуется более точное совпадение, то необходимо чуть изменить алгоритм и добавить все возможные варианты
// обозначения параметра в строчные константы ниже с поиском.

//  Предполагается, что лог-файлы данных с датчиков не перезаписываются в случайные позиции, а все замеры дописываются
// в конец файла, после чего, файл либо удаляется, либо архивируется или перемещается и создается заново свежий, т.к.
// при анализе файла отметки о начале и конце считывания сохраняются для текущего состояния файла.

//  График как есть, если записей меньше чем точек, то каждую выводим с интервалом. Если записей больше, то возможен вывод
// в точку и её окрестность, с учетом целочисленного или математического округления. При очень больших данных
// возможы искажения отображения т.к. отсутствуют механизмы корректировки погрешности, а целочисленные построения
// требуют большей алгоритмической сложности с перебором данных о погоде.
//  Если часть данных не существует, то слева или справа остаются свободные пространства.

//  При вычислении усредненного значения по часам, будет выведено столько точек, сколько возможно. Также
//стоит учитывать, что усредненное за час или более значение выравнивается слева, т.е. усредненное между 15-16 часов,
//будет отображено на графике точкой в 15-00. Можно дополнить в будущем чтобы учитывалась ширина интервала и/или по центру.

//  По данным. "Эффективная температура" - термин, не совпадает с тем что по смыслу. Это параметр характеризующий светимость
// небесного тела или другого объекта, вместо этого используем термин "температура ощущения", как в "The Long Dark".

//  Приборы по списку на выгрузку CSV, только те которые сработали и используются в программе:
// Роса-1 и 2; Hydra-L-1; Опорный барометр 1; Паскаль-1. Полные данные в отдельной директории.

//  Определения и макросы, в основном для статичной памяти и контроля выходов за пределы параметров.
//  Максимальное количество приборов, выбрано малое число для отладки, но в теории, может быть до 1Гб суммарных данных.
//  Данный параметр обязательно должен быть меньше или равным именам файлов, заданным в 'file_names'.
#define DEVICE_MAX 0x05
//  Ширирна и высота виртуального экрана для консольного рисования графиков. Если будут изменения, то заглянуть в 'print_screen'.
#define SCR_WIDTH 0x80
#define SCR_HEIGHT 0x20
//  Максимальный размер буффера для текстового сообщения или для строчных преобразований.
#define TEXT_MAX 0x400
//  Максимальное количество полей данных, пока 10 из-за цифрового меню, но в теории может быть очень большим.
#define FIELDS_MAX 0x0A

//  В резервной области структуры также расположим вычисляемые данные, более правильное решение это вынести отдельно,
// в динамическую память, если не трубуется последущее использование.
struct weather {                                                // Точность данных по округлению по правилам математики.
    struct tm timestamp;                                        // Дата и время измерения.
    float temperature;                                          // Температура в цельсиях.
    unsigned short pressure;                                    // Давление в миллиметрах ртутного столба.
    unsigned char humidity;                                     // Влажность воздуха в процентах.
    unsigned int illuminance;                                   // Освещенность в люксах.
    unsigned short color_temperature;                           // Цветовая температура в кельвинах.
    float feels_like;                                           // "Эффективная температура" - в задании или "ощущается".
    char reserved[8];                                           // Резерв и выравнивание структуры по параграфам(16 байт).
};

// Перечисления для удобства использования и улучшения читабельности кода.
enum weather_data { w_timestamp, w_temperature, w_pressure, w_humidity, w_illuminance,
                    w_color_temperature, w_feels_like, w_reserved };
enum chart_type { ch_none = 0, ch_points = 1, ch_columns = 2, ch_gradient = 3, ch_lines = 4 };

// Константы, ограничения и названия. Имена полей, регистр не учитывается, ключевое слово может присутствовать как часть.
const char* chart_names[] = { "none", "points", "columns", "gradient", "lines" };
const char* data_fields[] = { "date", "temp", "pressure", "humidity", "light_lux", "color_temp" };
const char* data_names[] = { "Date and time", "Temperature", "Pressure", "Humidity", "Illuminance",
                             "Color temperature", "Feels like" };
const unsigned int data_fields_size = sizeof(data_names) / sizeof(char*);
const unsigned int data_fields_load = sizeof(data_fields) / sizeof(char*);
const char date_time_format[] = "%Y-%m-%d %H:%M:%S";            // Формат даты и времени соответствующий в файле.
const char* file_names[] = { "Rosa-1.csv", "Rosa-2.csv", "Hydra-L.csv", "Oporniy_barometer-1.csv", "Pascal-1.csv" };
const unsigned int pencil_colors = 5;                           // Всего условных цветов или градаций черного.
const char pencil[] = { 32, 176, 177, 178, 219 };               // Коды таблицы ASCII для рисования в буффере.
const char pencil_axis[] = { 179, 180, 193, 194, 196, 197 };    // Прямые и углы для графиков.
const unsigned short color_temp_min = 1700;                     // Горящая спичка.
const unsigned short color_temp_max = 27000;                    // Ясное солнечное небо.
const unsigned char humidity_min = 0, humidity_max = 100 ;      // Влажность в процентах, от 0 до 100%.
const unsigned int illuminance_min = 0;                         // Минимальная освещенность стремящаяся к нулю.
const unsigned int illuminance_max = 100000;                    // Наибольшая солнечная освещенность при чистом небе.
const unsigned short pressure_min = 641;                        // Данные по пределам давления взяты из Вики.
const unsigned short pressure_max = 816;                        // Не учитываются замеры в ураганах.
const float temperature_min = -89.2;                            // Минимальная зафиксированная температура на планете.
const float temperature_max = +56.7;                            // Максимальная зафиксированная температура на планете.
const unsigned int weather_size = sizeof(struct weather);       // Вспомогательная константа размера структуры погоды.

//  Ограничения календаря и времени, можно будет добавить проверку на корректность.
const unsigned int sec_per_min = 60, sec_per_hour = 3600, min_per_hour = 60, hours_per_day = 24;
const unsigned int months_per_year = 12;                        // Стандартные месяца, високосный год расчитывается.
const unsigned int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//  Максимальное количество записей, допустимое для 32-бит - 1Гб по пределу памяти для всех приборов.
static const unsigned int global_data_max = INT_MAX / 2 / sizeof(struct weather);
// Структура не обязательна, в следующий раз без неё, лучше было реализовать структуру "устройства".
struct debug_setup {                                            // Вспомогательная структура для отладки(дополнительно).
    unsigned int memory;                                        // Предела выделения динамической памяти.
    struct tm t_first, t_last;                                  // Глобальный период для отображения и обработки.
    unsigned int avaraged_hours;                                // Усредненное количество часов.
    unsigned int devices, dev_active[DEVICE_MAX];               // Количество устройств и установка активных устройств.
    struct tm dev_load_t[DEVICE_MAX * 2];                       // Время для загрузки данных начальная и конечная.
    unsigned int fields, fields_active[FIELDS_MAX];             // Выбранные поля для отображения.
    int is_feels_like;                                          // Флаги.
    float like_hot, like_cold;                                  // Границы ощущения холода и жары, а между ними норма.
    enum chart_type g_chart;                                    // Глобальная установка типа отрисовки.
};

// Сценарии и установки для тестирования программы для ускорвения и отображения результатов.
const unsigned int debug_setups = 6;
char debug_file_name[] = "debug__.txt";                         // Шаблон для файла автоматического тестирования и вывода.
const char* debug_setups_info[] = {
    ("[A] 4 devices and 64k memory, 2 hours range points. First device fill exact wide screen as records, seconds and points. "
    "Second device has no records in memory from start range, but many records after range finish, and size "
    "2 * (wide screen - offset) = 2 * (120 - 30) = 180 records. "
    "Third device has records before start and less than last second of range and wider points. "
    "Fourth device has only one record loaded."
    ),
    ("[B] 3 devices and 64k memory, 6 hours range max. Draw avaraged temperature per hour. 'Rosa-1' has only 2 hours of "
    "records data. 'Rosa-2' - full range 6 dots or hours. 'Pascal-1' - less data records than hour, but draw as is one "
    "point. All data points in lines will be aligend to left, be ready. First chart with points and second drawning "
    "lines using Bresenham algorithm, slower version."
    ),
    ("[C] 2 devices and 64k memory, 6 hours range max at evening. Draw columns of humidity as is for 'Rosa-2' from 18:00 "
    "to 23:59 of the day. A lot of weather records to load. 'Rosa-1', a few records from 16:00 to 18:00. "
    "Using integer parameters and overlay chrart devices."
    ),
    ("[D] 1 device and 32k memory. Calculate 'feels like' temperature and draw chart with gradients using only 'Rosa-1' "
    "device, 360 records. Range 6 hours to show, using global settings 'feels like cold' and 'feels like hot' "
    "temperatures for gradients. Also, print all records after calculate."
    ),
    ("[E] 1 device 'Pascal-1', 128k memory. Big data for full day 24 hours and drawing lines of temperature avaraged 6 hours. "
    "From 2023-02-21 15:00 to 2023-02-22 14:59. Warning, aligment in chart is rounded to leftier posistion."
    ),
    ("[F] 3 devices, 16k memory. Debug 'load_csv_data' function and dynamic memory with incorrect settings. "
    "'Rosa-1' - incorrect date and time for first record. "
    "'Hydra-L' - incorrect date and time for last record. "
    "'Oporniy_barometer-1' - not enough memory to load all records."
    )
};

// Данные в порядке заполнения всех параметров программы для тестов, можно и по тексту.
// Формат: память, глобальное время и часы, устройство, первая и последняя дата загрузки,
const struct debug_setup debug_setups_data[] = {                // Отладочный сценарий A.
    {   .memory = 0x10000, .avaraged_hours = 0, .devices = 4, .fields = 1,
        .g_chart = ch_points, .is_feels_like = 0, .like_cold = 0.0, .like_hot = 25.0,
        .dev_active = { 0, 1, 2, 3 }, .fields_active = { w_temperature },
        .t_first = {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00 },
        .t_last =  {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 17, .tm_min = 00, .tm_sec = 00 },
        .dev_load_t = { {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 17, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 30, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 18, .tm_min = 23, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 14, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 16, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 01, .tm_sec = 00},
                      },
    },                                                          // Отладочный сценарий B.
    {   .memory = 0x10000, .avaraged_hours = 1, .devices = 3, .fields = 1, .g_chart = ch_points,
        .is_feels_like = 0, .like_cold = 18.5, .like_hot = 20.0,
        .dev_active = { 0, 1, 4 }, .fields_active = { w_temperature },
        .t_first = {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00 },
        .t_last =  {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 21, .tm_min = 00, .tm_sec = 00 },
        .dev_load_t = { {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 17, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 21, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 16, .tm_min = 00, .tm_sec = 00},
                      }
    },                                                          // Отладочный сценарий C.
    {   .memory = 0x10000, .avaraged_hours = 0, .devices = 2, .fields = 1,
        .g_chart = ch_columns, .is_feels_like = 0, .like_cold = 18.5, .like_hot = 20.0,
        .dev_active = { 1, 0 }, .fields_active = { w_humidity },
        .t_first = {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00 },
        .t_last =  {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 23, .tm_min = 59, .tm_sec = 59 },
        .dev_load_t = { {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 17, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 23, .tm_min = 59, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 16, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 18, .tm_min = 00, .tm_sec = 00},
                      }
    },                                                          // Отладочный сценарий D.
    {   .memory = 0x8000, .avaraged_hours = 0, .devices = 1, .fields = 1,
        .g_chart = ch_gradient, .is_feels_like = 1, .like_cold = 18.5, .like_hot = 20.0,
        .dev_active = { 1 }, .fields_active = { w_feels_like },
        .t_first = {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00 },
        .t_last =  {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 21, .tm_min = 00, .tm_sec = 00 },
        .dev_load_t = { {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 20, .tm_min = 49, .tm_sec = 00},
                      }
    },                                                          // Отладочный сценарий E.
    {   .memory = 0x20000, .avaraged_hours = 6, .devices = 1, .fields = 1,
        .g_chart = ch_lines, .is_feels_like = 0, .like_cold = 18.5, .like_hot = 20.0,
        .dev_active = { 4 }, .fields_active = { w_temperature },
        .t_first = {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00 },
        .t_last =  {.tm_year = 123, .tm_mon = 1, .tm_mday = 22, .tm_hour = 14, .tm_min = 59, .tm_sec = 59 },
        .dev_load_t = { {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 22, .tm_hour = 14, .tm_min = 59, .tm_sec = 59},
                  }
    },                                                          // Отладочный сценарий F.
    {   .memory = 0x400, .avaraged_hours = 0, .devices = 3, .fields = 1, .g_chart = ch_points,
        .is_feels_like = 0, .like_cold = 18.5, .like_hot = 20.0,
        .dev_active = { 0, 2, 3 }, .fields_active = { w_temperature },
        .t_first = {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00 },
        .t_last =  {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 21, .tm_min = 00, .tm_sec = 00 },
        .dev_load_t = { {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 19, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 17, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 18, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 15, .tm_min = 00, .tm_sec = 00},
                        {.tm_year = 123, .tm_mon = 1, .tm_mday = 21, .tm_hour = 16, .tm_min = 00, .tm_sec = 00},
                  }
    }
};

//  Глобальные данные для программы.
static int is_debug = 0;                                        // Флаг автоматической отладки с выводом в файлы.
static char screen[SCR_HEIGHT][SCR_WIDTH];                      // Буффер виртуального текстового экрана.
static struct weather* data[DEVICE_MAX];                        // Основные данные реализованы динамически, с предупреждением.
static unsigned int data_max_size = 0x10000;                    // Текущее значение предела записей для отладки и/или загрузок.
static unsigned int data_sizes[DEVICE_MAX];                     // Сколько записей по факту считано для каждого прибора.
static unsigned int data_total = 0;                             // Всего записей загруженных в память.
static int devices[DEVICE_MAX];                                 // Устройства по индексу имен файлов, которые загружены.
static unsigned int devices_loaded = 0;                         // Общее колчичество загруженных приборов.
static int devices_active[DEVICE_MAX];                          // Выбранные устройства для функций.
static unsigned int devices_act_size = 0;                       // Общее количество выбранных приборов.
static struct tm devices_timestamp[DEVICE_MAX * 2];             // Пары загруженных интервалов для данных.
static unsigned int fields_loaded[DEVICE_MAX];                  // Количество загруженных полей.
static int fields_selected[FIELDS_MAX];                         // Выбранные поля данных для отображения.
static unsigned int fields_sel_size = 0;                        // Количество выбранных полей для отображения.
// Порядковый номер полей: (0) - время; (-1) - не существует, FIELDS_MAX - параметр уже рассчитан.
static int fields_index[DEVICE_MAX][FIELDS_MAX];
static struct tm first, last;                                   // Активный времянной интервал.
unsigned int chart_hours = 0;                                   // Среднее количество часов для графиков.
enum chart_type global_chart = ch_points;                       // Глобальный тип отрисовываемого графика.
float feels_like_cold = 0.0, feels_like_hot = 30.0;             // Границы ощущения холода и жары, а между ними норма.
static char text[TEXT_MAX];                                     // Общий текст для кода по ходу всей программы.

//  Функции и программа в порядке не требующим дополнительных объявляений функций. ;)

void clear_screen(char c, int is_debug)
{   // Функция очистки буфера виртуального экрана заданным символом. Циклами или через адрес по вкусу.
    // Если флаг отладки, то заполнить буфер всеми "цветами", кроме 0-го. Можно по классике, прямоугольниками.
    if (is_debug)
        for (unsigned int i = 0, k = 1; i < SCR_HEIGHT; ++i)
            for (unsigned int j = 0; j < SCR_WIDTH; ++j)
                screen[i][j] = pencil[k + j / ((SCR_WIDTH / (pencil_colors - 1)))];
    else
        for (unsigned int i = 0; i < SCR_HEIGHT; ++i)
            for (unsigned int j = 0; j < SCR_WIDTH; ++j)
                screen[i][j] = c;
}

void print_screen(void)
{   // Функция вывода буфера в консоль. Переход на следующую строку после экрана.
    for (unsigned int i = 0; i < SCR_HEIGHT; ++i)               // Быстрый вывод через форматированную строку,
        printf("%.128s\n", screen[i]);                          //но требуется ручная подстановка параметра поля строки.
    /*
    for (unsigned int i = 0; i < SCR_HEIGHT; ++i) {
        for (unsigned int j = 0; i < SCR_WIDTH; ++j)
                putchar(scr_addr[i][j]);                        // Более медленный но также рабочий вывод.
        printf("\n");                                           // Раскоментировать, если требуется менять постоянно ширину.
    }
    */
}

unsigned int print_line(int x1, int y1, int x2, int y2, char color)
{   // Функция рисования прямой в виртуальном экране. На вход координаты точек, на выходе количество отрисованных точек.
    if (x1 < 0 || x1 >= SCR_WIDTH || y1 < 0 || y1 >= SCR_HEIGHT ||
            x2 < 0 || x2 >= SCR_WIDTH || y2 < 0 || y2 >= SCR_HEIGHT) {
        printf("Error draw line, coordinates of points incorrect: [%d, %d] and [%d, %d].\n", x1, y1, x2, y2);
        return 0;
    }
    unsigned int points = 0;
    if (x1 == x2 && y1 == y2) {
        screen[y1][x1] = color;
        return (++points);
    }
    int size_x = abs(x1 - x2), size_y = abs(y1 - y2);
    int crt, crt_offs, offs_y, offs_x;
    if (size_x >= size_y) {                                     // Или можно более компактно через дополнительные переменные.
        crt = (size_y + 1) / (size_y + 1);
        crt_offs = (size_y + 1);
    } else {
        crt = (size_x + 1) / (size_x + 1);
        crt_offs = (size_x + 1);
    }
    if (x2 > x1)                                                // Определяем горизонтальные и вертикальные смещения.
        offs_x = +1;
    else if (x2 < x1)
        offs_x = -1;
    else
        offs_x = 0;
    if (y2 > y1)
        offs_y = +1;
    else if (y2 < y1)
        offs_y = -1;
    else
        offs_y = 0;
    while ((offs_x == 1 && x1 <= x2) || (offs_y == 1 && y1 <= y2) ||
           (offs_x == -1 && x1 >= x2) || (offs_y == -1 && y1 >= y2)) {
        screen[y1][x1] = color;
        crt += crt_offs;
        if (size_x >= size_y) {                                 // Можно было бы и ускорить, ну ладно, в библиотеку.
            if (crt >= size_x + 1) {
                y1 += offs_y;
                crt -= (size_x + 1);
            }
            x1 += offs_x;
        } else {
            if (crt >= size_y + 1) {
                x1 += offs_x;
                crt -= (size_y + 1);
            }
            y1 += offs_y;
        }
        points++;
    }
    return points;
}

unsigned int is_dev_active(int dev)
{   // Является ли устройство активным, если да, то возвращается его индекс в списке, иначе DEVICE_MAX.
    unsigned int idx = 0;
    while (idx < devices_act_size && devices_active[idx] != dev)
        ++idx;
    if (idx < devices_act_size && devices_active[idx] == dev)
        return idx;
    else
        return DEVICE_MAX;
}

unsigned int is_dev_loaded(int dev)
{   // Загружено ли заданное устройство в память, если да, то возвращается его индекс, иначе DEVICE_MAX.
    unsigned int idx = 0;
    while (idx < devices_loaded && devices[idx] != dev)
        ++idx;
    if (idx < devices_loaded && devices[idx] == dev)
        return idx;
    else
        return DEVICE_MAX;
}

int is_field_floating(enum weather_data field)
{   // Определяем, является-ли поле параметром с плавающей точкой или иным, сравнение возможно со многими полями.
    const enum weather_data fp_fields[] = { w_temperature, w_feels_like };
    const int fp_fields_size = sizeof(fp_fields) / sizeof(int);
    int idx = 0;                                                // Параметры здесь или вынести вверх программы.
    while (idx < fp_fields_size)
        if (field == fp_fields[idx++])
            return 1;
    return 0;
}

int weather_read_field(unsigned int dev, unsigned int idx, unsigned int field, int* data_i, float* data_f)
{   // Вспомогательная функция возвращает данные из структуры по устройству, индексу и полю.
    // Данные по-умолчананию зануляются, для более удобного сложения после.
    if (dev >= DEVICE_MAX || field >= FIELDS_MAX || data_i == NULL || data_f == NULL || fields_index[dev][field] == -1) {
        printf("\nError reading weather field. Device, record index, field or addresses are incorrect.\n");
        return -1;
    }
    *data_i = 0; *data_f = 0.0;                                 // Параметр который не возвращается, будет 0 для оптимизации.
    switch (field) {
    case w_temperature:
        *data_f = data[dev][idx].temperature;
        break;
    case w_pressure:
        *data_i = data[dev][idx].pressure;
        break;
    case w_humidity:
        *data_i = data[dev][idx].humidity;
        break;
    case w_illuminance:
        *data_i = data[dev][idx].illuminance;
        break;
    case w_color_temperature:
        *data_i = data[dev][idx].color_temperature;
        break;
    case w_feels_like:
        *data_f = data[dev][idx].feels_like;
        break;
    default:
        printf("Warning read field, field is timestamp or incorrect.\n");
    }
    return 0;
}

unsigned int print_field_chart(unsigned int field, enum chart_type type)
{   // Построение графика в экран, по глобальному интервалу, выбранным активным устройствам и одному полю.
    // Если выбрано несколько устройств, максимально может быть до 4 или по количеству градиентов вывода.
    // Все устройства перед выводом должны быть загружены обязательно в память, чтобы данные были определенными.
    // Возвращает количество записей или усредненных записей, которые были отображены в заданном интервале.
    // Если интервал усредненного значения не выходит на полный час-сутки, то считается сколько есть.
    // Если хотя бы одна точка на графике возможна к отображению в интервале, то вывод происходит.
    // Перед выводом вируальный экран по-умолчанию - очищается.
    if (devices_act_size == 0 || fields_sel_size == 0 ||  devices_act_size >= pencil_colors) {
        printf("\nNo active devices or fields. Choose devices, fields in loaded data and repeat. "
               "Or active devices is more than possible gradients(%u), set something on/off.\n", pencil_colors);
        return 0;
    }
    if ((global_chart == ch_none) || (global_chart > ch_lines) ||
            (global_chart == ch_gradient && !(field == w_temperature || field == w_feels_like))) {
        printf("\nChart type '%s' with field is unsupported or none, change type in global settings.\n",
               chart_names[global_chart]);
        return 0;
    }
    for (unsigned int k = 0, dev; k < devices_act_size; ++k) {  // Проверка, загружен ли прибор в память.
        dev = devices_active[k];
        if (is_dev_loaded(dev) == DEVICE_MAX) {
            printf("\nError draw chart, active device %u - '%s' is not loaded, press (re)load in main menu and retry.\n",
                   dev, file_names[dev]);
            return 0;
        }
    }
    clear_screen(' ', 0);
    printf("\nDraw chart '%s' using %u devices, '%s' selected field and global time settings, avaraged hours %u.\n",
           chart_names[global_chart], devices_act_size, data_names[field], chart_hours);
    const unsigned int tab_left = 7, date_txt_size = 19;        // Отступы для вывода параметров под ширину 128, как удобней.
    const unsigned int y_all_steps = 6;                         // Удобнее подобрать интервалы делящиеся по размерам экрана.
    unsigned int i, j, points = 0;                              // Рисуем оси координат для графика.
    for (i = 0; i < SCR_HEIGHT; ++i)
        screen[i][tab_left] = pencil_axis[0];
    for (j = tab_left + 1; j < SCR_WIDTH - 1; ++j)
        screen[i - 2][j] = pencil_axis[4];
    screen[i - 1][j] = pencil_axis[2];
    screen[i - 2][j] = pencil_axis[1];
    int  y_size = SCR_HEIGHT - 2, x_size = SCR_WIDTH - tab_left - 1;
    printf("Working screen size for chart %u horizontal and %u vertical chars.\n", x_size, y_size);
    float min_f_val = +INFINITY, max_f_val = -INFINITY, f_value = 0.0, f_field_size = 0.0;
    int min_d_val = INT_MAX, max_d_val = 0, d_value, d_field_size = 0;
    for (unsigned int k = 0, dev; k < devices_act_size; ++k) {
        dev = devices[k];                                       // Минимальное и максимальное по всем устройствам.
        for (i = 0; i < data_sizes[dev]; ++i) {
            weather_read_field(dev, i, field, &d_value, &f_value);
            if (is_field_floating(field)) {                     // Дополнить, если будут еще не целые параметры.
                if (min_f_val > f_value)
                    min_f_val = f_value;
                if (max_f_val < f_value)
                    max_f_val = f_value;
            } else {                                            // С целочисленными параметрами аналогично.
                if (min_d_val > d_value)
                    min_d_val = d_value;
                if (max_d_val < d_value)
                    max_d_val = d_value;
            }
        }
        f_field_size = max_f_val - min_f_val;                   // Минимальное расхождение должно быть 0.01 * 2.
        d_field_size = max_d_val - min_d_val;                   // Или аналогично с целыми числами, только мин и макс.
        if ((is_field_floating(field) && fabs(max_f_val - min_f_val) < 0.02) ||
                (!is_field_floating(field) && abs(max_d_val - min_d_val) < 2)) {
            printf("Minimum and maximum values are equal, cant' draw chart.\n");
            return 0;
        }           
    }
    // Рисуем основание графика и подставляем интервалы времени и парамтров.
    float y_f_step = (float)(fabs(max_f_val - min_f_val) / (float)y_all_steps);
    int y_pos = 1, y_d_step = y_size / (y_all_steps) + 1;
    // printf("%d - %d\n", y_size, y_d_step);
    for (i = 0, f_value = max_f_val, d_value = max_d_val; i < y_all_steps; ++i) {
        if (is_field_floating(field)) {
            snprintf(text, TEXT_MAX, "%+7.2f", f_value);
            f_value -= y_f_step;
        } else {
            snprintf(text, TEXT_MAX, "%+-8d", d_value);
            d_value -= y_d_step;
        }
        for (j = 0; j < tab_left; ++j)
            screen[y_pos][j] = text[j];
        if (i == 0)
            screen[y_pos - 1][j] = pencil_axis[3];
        else if (i == y_all_steps - 1) {
            screen[y_pos - 1][j] = pencil_axis[5];
            screen[y_pos][j] = pencil_axis[2];                  // Или вывод даты на виртуальный экран в функцию.
            strftime(text, TEXT_MAX, date_time_format, &first);
            int j_start;
            for (j_start = j; j < date_txt_size + tab_left; ++j)
                screen[y_pos][j + 1] = text[j - j_start];
            strftime(text, TEXT_MAX, date_time_format, &last);
            j_start = SCR_WIDTH - date_txt_size - 1;
            for (j = j_start; j < j_start + date_txt_size; ++j)
                screen[y_pos][j] = text[j - j_start];
        } else
            screen[y_pos - 1][j] = pencil_axis[1];
        y_pos += y_d_step;
    }
    // Основной цикл анализа всех активных устройств, с учетом заданных глобальных параметров.
    for (unsigned int k = 0, dev; k < devices_act_size; ++k) {
        dev = devices[k];
        if (type != ch_gradient)
            printf("Drawing device '%s' with color '%c'.\n", file_names[dev], pencil[pencil_colors - k - 1]);
        else
            printf("Drawing device '%s' with gradients: '%c' - cold, '%c' - normal and '%c' hot.\n",
                   file_names[dev], pencil[1], pencil[2], pencil[3]);
        int range_size = 0, first_data = -1, last_data = -1;
        struct tm timestamp;                                    // Определяем количество записей в интервале вывода.
        time_t f_time = mktime(&first), l_time = mktime(&last), d_time = 0;
        for (j = 0; j < data_sizes[dev] && d_time <= l_time; ++j) {
            timestamp = data[dev][j].timestamp;
            d_time = mktime(&timestamp);
            // printf("%d\n", data_sizes[dev]);
            if (first_data == -1 && d_time >= f_time && d_time <= l_time) {
                printf("First record index using time is %d, seconds %ld.\n", j, d_time);
                first_data = j;
            }
            if (first_data >= 0 && last_data == -1)
                range_size++;
            if (last_data == -1 && d_time >= l_time) {          // Можно с учетом начала, но оставим для информации.
                printf("Last record index using time is %d, seconds %ld.\n", j, d_time);
                last_data = j;
            }
        }
        if (!range_size) {
            printf("Data range size %u, nothing to draw for this device.\n", range_size);
            continue;                                           // Дополнительно, можно и через флаг.
        } else if (first_data != -1 && last_data == -1)
            last_data = first_data + range_size - 1;
        f_time = mktime(&data[dev][first_data].timestamp);
        l_time = mktime(&data[dev][last_data].timestamp);
        printf("First timestamp index in data from %d to %d, range size %d or %ld seconds.\n",
               first_data, last_data, range_size, l_time - f_time);
        unsigned int index_step = 1;                            // Шаг индекса с учетом или без него усредненного значения.
        if (range_size > x_size) {                              // Если данных больше чем возможая ширина графика.
            index_step = range_size / x_size + (range_size % x_size > 0);
            // Для оптимизации, после подумать удалить.
            printf("Range size is wider than screen horizontal, step for data indexes is about %u.\n", index_step);
        } else
            printf("Range size is narrower or equal than screen horizontal, step for data indexes is %u.\n", index_step);
        if (is_field_floating(field))
            printf("Minimum %.3f and %.3f maximum values, values range %.3f.\n", min_f_val, max_f_val, f_field_size);
        else
            printf("Minimum %d and %d maximum values, values range %d.\n", min_d_val, max_d_val, d_field_size);
        // Вычисляем дополнительные параметры для графика и временной интервал, который существует.
        double x_pos_l, x_pos_r, step_x, scale, avaraged;       // Смещения и шаги для нормального масштабирования.
        f_time = mktime(&first); l_time = mktime(&last);        // Первая и последняя по глобальным настройкам.
        time_t df_time = mktime(&data[dev][first_data].timestamp);
        time_t dl_time = mktime(&data[dev][last_data].timestamp);
        if (chart_hours > 0)                                    // Для подстраховки деления на ноль, два условия.
            if (((dl_time - df_time) / (chart_hours * sec_per_hour)) == 0)
                printf("Warning, not enough data to draw points using %u avaraged hours.\n", chart_hours);
        scale = (double)(l_time - f_time) / (double)x_size;     // Общий масштаб одного символа.
        printf("Scale in chart, 1 cell is %.2f seconds or trunc is %.2f.\n", scale, truncf(scale));
        // Округление слева работает на минимально целое число, дробная отбрасывается, проверка не делается.
        //x_pos_l = (tab_left + 1) + truncf((float)(d_time - f_time) / scale);
        // Округление слева по правилам математики, можно поэкспеременировать.
        x_pos_l = round((double)(df_time - f_time) / scale);
        printf("First diff %ld seconds, horizontal offset of first point in chart is %.2f.\n",
               d_time - f_time, x_pos_l);                       // Смещение по горизонтали относительно стартового времени.
        // Округление справа работает на максимально целое, любая дробная часть увеличивает число.
        // x_pos_r = trunc(((double)x_size - (double)(l_time - dl_time) / scale));
        // Округление справа по правилам математики.
        x_pos_r = round(((double)x_size - (double)(l_time - dl_time) / scale));
        printf("Last diff %ld seconds, horizontal offset of last point in chart is %.2f.\n",
               (l_time - dl_time), x_pos_r);                    // Дополнительный параметр, фактически для выравнивания.
        step_x = (((double)x_size - x_pos_l) - ((double)x_size - x_pos_r)) / (double)range_size;
        printf("Step horizontal for every index is %.3f, except left and right offsets.\n", step_x);
        // Основной вывод графика, по индексам исходных данных с учетом усредненных значений.
        // Пробегаем все данные, которые удалось определить, с поправкой на количество усредненных или 1.
        for (int idx = first_data, steps = 1, prev_x = -1, prev_y = -1; idx <= last_data; ++idx, steps = 1) {
            if (chart_hours) {                                  // Если необходимо усредненное значение за количество часов.
                int idx_start = idx, is_out_of_data = 0;
                df_time = mktime(&data[dev][idx].timestamp);
                time_t period_last = df_time + (long)(sec_per_hour * chart_hours);
                avaraged = 0.0;
                while ((idx_start == idx || dl_time < period_last) && idx <= last_data && !is_out_of_data) {
                    if (weather_read_field(dev, idx, field, &d_value, &f_value) == -1)
                        is_out_of_data = 1;                     // Если данные кончились, а час неполный, то считаем как есть.
                    dl_time = mktime(&data[dev][++idx].timestamp);
                    avaraged += f_value + (double)d_value;      // Сразу же прибавляем, чтобы без условия, один будет 0.
                    steps++;
                };
                f_value = (float)(avaraged / (double)(idx - idx_start));
                d_value = (int)(round(avaraged / (double)(idx - idx_start)));
            } else
                if (weather_read_field(dev, idx, field, &d_value, &f_value) == -1)
                    return 0;
            if (is_field_floating(field)) {                     // Расчет сразу или можно поэксперементировать с округленями.
                f_value = (float)(round(((f_value - min_f_val) / f_field_size * (double)(y_size - 1))));
                y_pos = (y_size - 1) - (int)f_value;
            } else {
                f_value = (float)(round(((double)(d_value - min_d_val) / (double)d_field_size * (double)(y_size - 1))));
                y_pos = (y_size - 1) - (int)f_value;
            }
            int scr_x = (int)(trunc(x_pos_l)) + tab_left + 1;
            switch (type) {                                     // Выводим градиентом прибора, по типу графика.
            case ch_none:
                printf("Type of chart is 'none', set correct setting.\n");
                return 0;
            case ch_points: {                                   // Преобразование (int) просто отбрасывает дробную часть.
                screen[y_pos][scr_x] = pencil[pencil_colors - k - 1];
                break;
            } case ch_columns: {                                // Графика столбцами, с отработкой всех приборов поверх.
                for (int c = y_pos; c < y_size; ++c, points++)
                    screen[c][scr_x] = pencil[pencil_colors - k - 1];
                break;
            } case ch_gradient: {                               // Рисование 3-мя градиентами: холодно, умеренно, жарко.
                for (int c = y_pos; c < y_size; ++c, points++) {
                    double grad = max_f_val - (double)c / (double)y_size * f_field_size;
                    if (grad < feels_like_cold) {               // Построение градиента только для температур.
                        screen[c][scr_x] = pencil[1];
                    } else if (grad > feels_like_hot) {
                        screen[c][scr_x] = pencil[3];
                    } else
                        screen[c][scr_x] = pencil[2];
                }
                break;
            } case ch_lines: {                                  // Линии между точками, только если данных меньше ширины.
                if (prev_x != -1 && prev_y != -1)
                    print_line(scr_x, y_pos, prev_x, prev_y, pencil[pencil_colors - k - 1]);
                else                                            // Если это первая, то ставим точку в любом случае.
                    screen[y_pos][scr_x] = pencil[pencil_colors - k - 1];
                prev_x = scr_x; prev_y = y_pos;
                break;
            } default:
                printf("Type of chart (%d) incorrect or unsupported.\n", type);
                return 0;
            }
            x_pos_l += (step_x * (double)steps);                // Следующая позиция с округлением математически.
            points++;
        }
       printf("Drawning records %u, and virtual points, lines or columns %u.\n\n", range_size, points);
    }
    return points;
}

void print_weather(unsigned int dev, unsigned int idx, int is_next_line)
{   // Вывод в текстовом виде всех полей структуры weather из данных прибора с индексом по массиву.
    // Прибор по прямому индексу, т.е. которые загружены.
    if (dev > devices_loaded || idx >= data_sizes[dev]) {
        printf("Warning, device %u incorrect or index %u weather data is out of range %u actual data.\n",
               dev, idx, data_sizes[dev]);
        return;
    }
    printf("Weather device '%s' at %u index and address [%p]:\n", file_names[dev], idx, &data[dev][idx]);
    printf("Parameter:\t\tValue:\n");
    // Все данные в записи, в том числе и рассчитанные.
    strftime(text, TEXT_MAX, date_time_format, &data[dev][idx].timestamp);
    if (fields_index[dev][w_timestamp] != -1)
        printf("%s:\t\t%s;\n", data_names[w_timestamp], text);
    if (fields_index[dev][w_temperature] != -1)
        printf("%s:\t\t%.2f;\n", data_names[w_temperature], data[dev][idx].temperature);
    if (fields_index[dev][w_pressure] != -1)
        printf("%s:\t\t%hd;\n", data_names[w_pressure], data[dev][idx].pressure);
    if (fields_index[dev][w_humidity] != -1)
        printf("%s:\t\t%d;\n", data_names[w_humidity], data[dev][idx].humidity);
    if (fields_index[dev][w_illuminance] != -1)
        printf("%s:\t\t%u;\n", data_names[w_illuminance], data[dev][idx].illuminance);
    if (fields_index[dev][w_color_temperature] != -1)
        printf("%s:\t%hd;\n", data_names[w_color_temperature], data[dev][idx].color_temperature);
    printf("%s:\t\t%.2f;\n", data_names[w_feels_like], data[dev][idx].feels_like);
    if (is_next_line)                                           // Флаг переноса на следующую строку.
        printf("\n");
}

void print_all_records(void)
{   // Вывод всех данных, в активных приборах выбранных пользователем в глобальных данных.
    if (!devices_act_size) {
        printf("\nNo active devices was chosen. Reload data and choose in menu active device(s).\n");
        return;
    }                                                           // Выводятся все поля, включая расчетные.
    printf("\nAll loaded data records for %u devices:\n", devices_act_size);
    for (unsigned int i = 0; i < devices_act_size; ++i) {
        unsigned int dev = devices_active[i];
        printf("\nDevice %u, '%s', records %u:\n\n", dev, file_names[dev], data_sizes[dev]);
        for (unsigned int idx = 0; idx < data_sizes[dev]; ++idx)
            print_weather(dev, idx, (idx < data_sizes[dev] - 1));
    }
}

void print_fields_tab(void)
{   // Вывод таблицы найденных и загруженных полей данных во всех файлах и их порядковых индексов.
    if (!devices_loaded) {
        printf("\nNo devices was loaded to memory, table with indexes is empty.\n");
        return;
    }                                                           // Выводятся только загружаемые поля.
    printf("\nAll %u devices founded and loaded data fields at indexes or ';' counter.\n", devices_loaded);
    printf("File:\t\t\tTimestamp:\tTemperature:\tPressure:\tHumidity:\tIlluminance:\tColor temperature:\n");
    for (unsigned int dev = 0, dev_idx; dev < devices_loaded; ++dev) {
        dev_idx = devices[dev];
        printf("%-24s", file_names[dev_idx]);
        for (unsigned int field = 0; field < data_fields_load ; ++field)
            if (fields_index[dev_idx][field] != -1)
                printf("yes [%u]\t\t", fields_index[dev_idx][field]);
            else
                printf("no\t\t");
        printf("\n");
    }
}

int string_to_time(const char src[], struct tm* date_time, const char fmt[])
{   // Вспомогательная функция конвертации строки в структуру даты и времени по заданному формату.
    // Возвращает 0 если строка полностью подходит под формат или индекс первого не совпадающего символа.
    // Проверка на ошибку в дате по календарю или во времени не осуществляется, можно будет дополнить.
    // const int max_seconds = 59, max_minutes = 59, max_hours = 23, max_days = 31,
    const int start_year = 1900, start_month = 1;
    const char fmt_tab[] = "YmdHMS";    // Год-Месяц-День Час:Минута:Секунда.
    unsigned int f_idx = 0, s_idx = 0, d_size, i;
    char par_txt[TEXT_MAX];
    while (src[s_idx] != '\0' && fmt[f_idx] != '\0') {
        if (fmt[f_idx++] == '%') {
            for (i = 0; fmt_tab[i] != '\0' && fmt[f_idx] != fmt_tab[i]; ++i)
                ;
            if (fmt[f_idx] == fmt_tab[i]) {
                d_size = 0;
                while (isdigit(src[s_idx]))
                    par_txt[d_size++] = src[s_idx++];
                par_txt[d_size] = '\0';
                if (d_size == 0) {
                    printf("Error in data at index %d.\n", s_idx);
                    return s_idx;
                }
                int par = atoi(par_txt);
                switch (fmt[f_idx]) {                           // Обрабатывается по стандартному формату, можно расширить.
                case 'Y':                                       // Год.
                    date_time->tm_year = par - start_year;
                    break;
                case 'm':                                       // Месяц.
                    date_time->tm_mon = par - start_month;
                    break;
                case 'd':                                       // День месяца.
                    date_time->tm_mday = par;
                    break;
                case 'H':                                       // Часы.
                    date_time->tm_hour = par;
                    break;
                case 'M':                                       // Минуты.
                    date_time->tm_min = par;
                    break;
                case 'S':                                       // Секунды.
                    date_time->tm_sec = par;
                    break;
                }
                f_idx++;                                        // Вместе с буквой.
            } else
                printf("Unsupported parameter in date or time format, '%c'.\n", fmt[f_idx]);
        } else
            s_idx++;
    }
    if (s_idx > 0)
        return 0;
    else
        return -1;
}

void device_remove(unsigned int dev)
{   // Удаляет искомый прибор из глобальных данных, освобождает память и уплотняет индексы.
    int dev_idx = is_dev_loaded(dev);
    if (dev_idx != DEVICE_MAX) {
        free(data[dev]);
        data[dev] = NULL;
        data_total -= data_sizes[dev];
        data_sizes[dev] = 0;
        fields_loaded[dev] = 0;
        for (int i = 0; i < FIELDS_MAX; ++i)
            fields_index[dev][i] = -1;
        for (unsigned int i = dev_idx; i < devices_loaded - 1; ++i)
            devices[i] = devices[i + 1];
        devices_loaded--;
        printf("Device %u at index %d removed from memory and data, devices %u\n", dev, dev_idx, devices_loaded);
    } else
        printf("Can't remove device %u from memory, index not found in data.\n", dev);
}

unsigned int load_csv_data(const char file_name[], unsigned int dev, struct tm* first, struct tm* last)
{   // Функция чтения .csv фалйа и заполнение массива датчиков. Используем глобальные данные и параметры даты время от и до включительно.
    // Возвращает количество записей, которые удалось считать и интерпретировать. Предыдущие основные данные, если были - то освободить.
    // Загрузку в два прохода с оценкой количества памяти. Максимальная длина строки TEXT_MAX.
    // Даты не обязательны к полному соотвествию, главное чтобы интервал был корректным в файле.
    printf("\nLoad main weather data from '%s' file.\n", file_name);
    if (dev >= DEVICE_MAX || first == NULL || last == NULL || file_name == NULL) {
        printf("File name, device index or first/last data incorrect.\n");
        return 0;
    }
    if (is_dev_loaded(dev) != DEVICE_MAX) {    // Or in end.
        printf("Previous data exist, weather structures %u in heap, clear data.\n", data_sizes[dev]);
        device_remove(dev);
    }
    FILE* csv_file = fopen(file_name, "rb");
    if (!csv_file) {
        printf("Warning can't open data file '%s', check names and paths.\n", file_name);
        return 0;
    }
    printf("File '%s' exist and opened in read-only binary mode.\n", file_name);
    char c, *c_ptr, line[TEXT_MAX], data_str[TEXT_MAX];
    while ((c = fgetc(csv_file)) != '\n' && c != EOF)
        ;
    if (c != '\n') {
        printf("Can't read first line as header, check file data.\n");
        fclose(csv_file);
        return 0;
    }
    printf("Header exist, try to read parameters saved in file.\n");
    if ((c_ptr = fgets(line, TEXT_MAX, csv_file)) == NULL) {
        printf("Error reading parameters data in file.\n");
        fclose(csv_file);
        return 0;
    }
    while (*c_ptr != '\n') {                                    // Регистр в параметрах не отслеживается.
        *c_ptr = tolower(*c_ptr);
        c_ptr++;
    }
    *c_ptr = '\0'; fields_loaded[devices_loaded] = 0;
    printf("Readed line with parameters, with lower case:\n'%s'.\n", line);
    printf("Trying to find and set field indexes:\n");
    for (unsigned int i = 0, j, k; i < data_fields_load; ++i) {
        printf("%s:\t", data_fields[i]);
        if (i < 2)
            printf("\t");
        if ((c_ptr = strstr(line, data_fields[i])) != NULL) {
            strncpy_s(data_str, TEXT_MAX, line, c_ptr - line);
            for (j = 0, k = 0; data_str[j] != '\n' && data_str[j] != '\0'; ++j)
                if (data_str[j] == ';')
                    ++k;
            printf("found at %u offset, data index %d.\n", (unsigned int)(c_ptr - line), k);
            fields_index[dev][i] = k;
            fields_loaded[dev]++;
        } else {
            printf("not found, set index field to -1.\n");
            fields_index[dev][i] = -1;                          // По умолчанию если поле не найдено.
        }
    }
    if (fields_loaded[dev] < 2 || fields_index[dev][0] == -1) {
        printf("No data to load or only has date and time stamps.\n");
        fclose(csv_file);                                       // Дата и время должна быть обязательно и на первой позиции.
        return 0;
    }
    printf("Total data fields %d founded with date time stamps in (first position).\n", fields_loaded[dev]);
    int is_first = 0, is_last = 0, idx = 0;
    time_t t_first = mktime(first), t_last = mktime(last), time_data;
    fpos_t first_pos = EOF, last_pos = EOF;
    c_ptr = line;
    struct tm timestamp;
    fgetpos(csv_file, &first_pos);
    printf("Data records offset in file %llu.\n", first_pos);
    printf("Counting data with time stamps:\n");                // Общее количество записей.
    strftime(line, TEXT_MAX, date_time_format, first);
    printf("First date time: '%s'.\n", line);
    strftime(line, TEXT_MAX, date_time_format, last);
    printf("Last date time: '%s'.\n", line);
    while (c_ptr != NULL && !(is_first && is_last)) {
        if (!is_first)
            fgetpos(csv_file, &first_pos);
        if (!is_last)
            fgetpos(csv_file, &last_pos);
        // printf("C = %c\n", fgetc(csv_file));
        if ((c_ptr = fgets(line, TEXT_MAX, csv_file))) {
            if ((c_ptr = strchr(line, '\n')) != NULL)
                *c_ptr = '\0';                                  // Для вывода.
            c_ptr = strchr(line, ';');
            // printf("%p", c_ptr);
            if (c_ptr) {
                strncpy_s(data_str, TEXT_MAX, line, c_ptr - line);
                // data_str[c_ptr - line - ] = '\0';
                printf("\nData: '%s', source: '%s', size %u.\n", data_str, line, c_ptr - line);
                if ((idx = string_to_time(data_str, &timestamp, date_time_format))) {
                    printf("Error in time conversion, from index %d.\n", idx);
                    fclose(csv_file);
                    return 0;
                }
                strftime(line, TEXT_MAX, date_time_format, &timestamp);
                printf("Check timestamp: '%s', ", line);
                time_data = mktime(&timestamp);
                if (!is_first && time_data >= t_first && time_data <= t_last) {
                    printf("First timestamp founded, saving file position at %llu.\n", first_pos);
                    is_first = 1;
                    data_sizes[dev]++;
                } else if (is_first && !is_last && time_data > t_last) {
                    printf("Previous timestamp was last, saving file position at %llu.\n", last_pos);
                    is_last = 1;
                } else if (is_first && !is_last)    // add checks.
                    printf("In time range, data counter %d.\n", ++data_sizes[dev]);
                else
                    printf("just data, reading next.\n");
            } else
                printf("Timestamp incorrect, cant't find ';'.\n");
        } else
            printf("Read line error or end of data file.\n");
    }
    if (!is_first || !is_last) {
        printf("First or last weather record was not found or incorrect timestamp.\n");
        data_sizes[dev] = 0;
        fclose(csv_file);                                       // Не забываем закрывать файл.
        return 0;
    }
    if (data_sizes[dev] > (data_max_size - data_total)) {       // Размеры по записям.
        printf("\nData records in file is more than dynamic memory limit, maximum %u records.\n", data_max_size - data_total);
        data_sizes[dev] = 0;
        fclose(csv_file);
        return 0;
    }
    // Фактически загружаем данные, которые отвечают параметрам глобального интервала. Все данные корректны и без перезаписи.
    data[dev] = malloc(weather_size * data_sizes[dev]);
    printf("\nData load possible, data size %u bytes allocated at address %p.\n", weather_size * data_sizes[dev], data[dev]);
    printf("Reset position in file to first record at %lld and reading to last %lld offset record.\n", first_pos, last_pos);
    printf("Reading %u weather records and save to memory.\n", data_sizes[dev]);
    fsetpos(csv_file, &first_pos);
    for (unsigned int data_idx = 0; first_pos <= last_pos && data_idx < data_sizes[dev]; data_idx++) {
        fgets(line, TEXT_MAX, csv_file);
        fgetpos(csv_file, &first_pos);
        // printf("%llu\n", first_pos);
        if ((c_ptr = strchr(line, '\n')) != NULL)
            *c_ptr = '\0';
        printf("\nReading data to fields of weather structure positions from %llu to %llu offset:\n'%s':\n",
               first_pos, last_pos, line);
        for (unsigned int i = 0; i < fields_loaded[dev]; ++i) {
            printf("%s, ", data_fields[i]);
            if (fields_index[dev][i] != -1) {
                printf("index %d, ", fields_index[dev][i]);
                int j = 0, k = 0, par_first = 0, par_last = 0;
                while (line[j] != '\n' && line[j] != '\0' && k != fields_index[dev][i])
                    if (line[j++] == ';')                       // Посимвольное чтение строки.
                        k++;
                // printf("j = %d, k = %d.\n", j, k);
                par_first = j;
                while (line[j] != '\n' && line[j] != '\0' && line[j] != ';')
                    ++j;
                par_last = j;                                   // Следующий параметр через ";";
                strncpy_s(data_str, TEXT_MAX, &line[par_first], par_last - par_first);
                data_str[par_last - par_first] = '\0';          // Дополнительно.
                printf("parameter string '%s'. ", data_str);
                double fp = atof(data_str);
                switch (i) {                                    // Параметры с учетом пределов и преобразований.
                case w_timestamp:
                    string_to_time(data_str, &timestamp, date_time_format);
                    data[dev][data_idx].timestamp = timestamp;  // Копирование как есть, или можно по памяти.
                    printf("Just copy to structure TM in data.\n");
                    break;
                case w_temperature:
                    if (fp < (double)temperature_min || fp > (double)temperature_max)
                        printf("\nWarning, temperature out of range, using default conversion.\n");
                    data[dev][data_idx].temperature = (float)fp;
                    printf("Save temperature %.2f celsius.\n", data[dev][data_idx].temperature);
                    break;
                case w_pressure:
                    if (fp < (double)pressure_min || fp > (double)pressure_max)
                        printf("\nWarning, pressure out of range, using default conversion.\n");
                    data[dev][data_idx].pressure = (unsigned short)round(fp);
                    printf("Save rounded pressure %hu mm Hg.\n", data[dev][data_idx].pressure);
                    break;
                case w_humidity:
                    if (fp < (double)humidity_min || fp > (double)humidity_max)
                        printf("\nWarning, humidity out of range, using default conversion.\n");
                    data[dev][data_idx].humidity = (unsigned char)round(fp);
                    printf("Save rounded humidity %hu percent.\n", data[dev][data_idx].humidity);
                    break;
                case w_illuminance:
                    if (fp < (double)illuminance_min || fp > (double)illuminance_max)
                        printf("\nWarning, illuminance out of range, using default conversion.\n");
                    data[dev][data_idx].illuminance = (unsigned int)round(fp);
                    printf("Save rounded illuminance %u lux.\n", data[dev][data_idx].illuminance);
                    break;
                case w_color_temperature:
                    if (fp < (double)illuminance_min || fp > (double)illuminance_max)
                        printf("\nWarning, illuminance out of range, using default conversion.\n");
                    data[dev][data_idx].color_temperature = (unsigned short)round(fp);
                    printf("Save rounded color temperature %hu, kelvins.\n", data[dev][data_idx].color_temperature);
                    break;
                default:
                    printf("Warning, type of parameter incorrect, %d.\n", i);
                }
            } else
                printf("index not exist in data file.\n");
        }
        data[dev][data_idx].feels_like = 0.0;                   // Дополнительное обнуление, можно и без него.
    }
    devices_timestamp[dev * 2] = data[dev][0].timestamp;
    devices_timestamp[dev * 2 + 1] = data[dev][data_sizes[dev] - 1].timestamp;
    data_total += data_sizes[dev];
    printf("\nData loaded, device %u, data saved, size %u, total records %u.\n",
           dev, data_sizes[dev], data_total);
    devices[devices_loaded++] = dev;
    fclose(csv_file);
    return 0;
}

void update_feels_like_temp(void)
{   // Вычисление температуры ощущения, данные располагаются в резервной области структуры.
    if (devices_act_size == 0) {
        printf("\nFeels like temperature has no active devices, select acitve devices in menu.\n");
        return;
    }
    printf("\nUpdate 'feels like' temperature in all active and loaded devices.\n");
    printf("Using, T - temperaure and H - humidity.\n"
           "Feels like = T - 0.4 * (T - 10.0) *  (1.0 - H / 100), celsius.\n");
    for (unsigned int i = 0, j; i < devices_act_size; ++i) {
        unsigned int dev = devices[i];
        printf("Calculate device %u, '%s' data, records in device %u.\n", dev, file_names[dev], data_sizes[dev]);
        if (is_dev_loaded(dev) != DEVICE_MAX &&
                fields_index[dev][w_temperature] != -1 && fields_index[dev][w_humidity] != -1) {
            fields_index[dev][w_feels_like] = FIELDS_MAX;
            for (j = 0; j < data_sizes[dev]; ++j) {             // Все данные вычисляются в double.
                double tmp = data[dev][j].temperature, hum = data[dev][j].humidity;
                data[dev][j].feels_like = tmp - 0.4 * (tmp - 10.0) * (1.0 - hum / 100.0);
            }
        } else
            printf("Active device %u, '%s' is not loaded, press '(re)load' in main menu.\n"
                   "Or fields '%s' or '%s' not exist in device, calculate impossible.\n",
                   devices[i], file_names[devices[i]], data_names[w_temperature], data_names[w_humidity]);
    }
}

void system_information(void)
{
    const int lines[12][4] = { {0, 0, 127, 0}, {127, 31, 0, 31}, {127, 0, 127, 31}, {0, 31, 0, 0},
                               {127, 31, 0, 0}, {127, 0, 0, 31}, {63, 2, 63, 12}, {64, 19, 64, 29},
                               {2, 8, 47, 15}, {2, 23, 47, 17}, {125, 8, 80, 15 }, {125, 23, 80, 17}
                            };
    printf("\nSystem inforamtion and screen test.\n");
    printf("Sizeof char %u, short %u, int %u and long long %u bytes. Address width %u bits.\n",
           sizeof(char), sizeof(short), sizeof(int), sizeof(long long), sizeof(void*) * CHAR_BIT);
    printf("Print screen buffer with all possible colors.\n");
    printf("Sizes width are %u and height %u. Raster font reccomended, see your console settings.\n\n", SCR_WIDTH, SCR_HEIGHT);
    clear_screen(pencil[1], 1);
    print_screen();
    printf("\nTesting drawing lines using Brezenham's algorithm, slower version.\n\n");
    clear_screen(pencil[0], 0);
    for (unsigned int i = 0; i < sizeof(lines) / sizeof(int*) / 4; ++i)
        print_line(lines[i][0], lines[i][1], lines[i][2], lines[i][3], pencil[4]);
    print_screen();
    // Вывести названия полей данных в структуре, их смещение и размерность.
    struct weather debug_data;
    time_t debug_time = time(NULL);
    char text[TEXT_MAX];    // Текстовый вывод.
    strftime(text, TEXT_MAX, date_time_format, localtime(&debug_time));
    printf("\nStructure weather data, size %u bytes, offsets and sizes are also in bytes, maximum records %u, 1gb limit.\n",
           sizeof(struct weather), data_max_size);
    printf("Name:\t\t\tField in file:\tUnit:\t\tType:\t\tOffset:\tSize:\tMin:\t\tMax:\t\tExample:\n");
    printf("Date and Time\t\t%-16sstructure\ttm\t\t+%u\t%u\tcalendar\tcalendar\t'%s'.\n", data_fields[w_timestamp],
           (char*)&debug_data.timestamp - (char*)&debug_data, sizeof(debug_data.timestamp), text);
    printf("Temperature\t\t%-16scelsius\t\tfloat\t\t+%u\t%u\t%.2f\t\t%+.2f\t\t%+.2f celsius.\n", data_fields[w_temperature],
           (char*)&debug_data.temperature - (char*)&debug_data, sizeof(debug_data.temperature), temperature_min, temperature_max, (float)15.07);
    printf("Pressure\t\t%-16smm Hg\t\tunsigned short\t+%u\t%u\t%hu\t\t%hu\t\t%hu mm hg.\n", data_fields[w_pressure],
           (char*)&debug_data.pressure - (char*)&debug_data, sizeof(debug_data.pressure), pressure_min, pressure_max, (unsigned short)760);
    printf("Humidity\t\t%-16spercent\t\tunsigned char\t+%u\t%u\t%hhu\t\t%hhu\t\t%hhu%%.\n", data_fields[w_humidity],
           (char*)&debug_data.humidity - (char*)&debug_data, sizeof(debug_data.humidity), humidity_min, humidity_max, (unsigned char)50);
    printf("Illuminance\t\t%-16slux\t\tunsigned int\t+%u\t%u\t%u\t\t%u\t\t%u lux.\n", data_fields[w_illuminance],
           (char*)&debug_data.illuminance - (char*)&debug_data, sizeof(debug_data.illuminance), illuminance_min, illuminance_max, 10000);
    printf("Color temperature\t%-16skelvins\t\tunsigned short\t+%u\t%u\t%hu\t\t%hu\t\t%huK.\n", data_fields[w_color_temperature],
           (char*)&debug_data.color_temperature - (char*)&debug_data, sizeof(debug_data.color_temperature),
           color_temp_min, color_temp_max, (unsigned short)3400);
    printf("Feels like temperature\t-\t\tcelsius\t\tfloat\t\t+%u\t%u\t%.2f\t\t%+.2f\t\t%+.2f celsius.\n",
           (char*)&debug_data.feels_like - (char*)&debug_data, sizeof(debug_data.feels_like),
           temperature_min, temperature_max, (float)15.07);
    printf("Reserved\t\t-\t\tundefined\tchar\t\t+%u\t%u\n",
           (char*)(&debug_data.reserved) - (char*)(&debug_data), sizeof(debug_data.reserved));
    // Общие комментарии, которые есть в начале программы, но дополнительно будут выведены.
    printf("\nSome comments and information from source code and limits for program.\n\n");
    printf("\tFor all devices while loading, we try to find fields names of weather records at second line, after title. "
           "If exist at least one parameter and timestamps, then device data will be loaded to memory, else just skip. "
           "Parameters match if it's name contain keyword or exactly word. Example. Keyword 'temp' and paramater "
           "'weather_temp' will match. And only first occurence will be loaded. If other 'find' algorithm "
           "needed, then update 'load_csv_data' function.\n");
    printf("\tLog files supposed to write only to tail. Files and doesn't overwrite records at random positions. "
           "Usually log file writes to limit size and then archived or moved and create new log file. Timestamps "
           "for first and last record saved only for current state of log. Otherwise, undefined behavior.\n");
    printf("\tAll points on charts are align to leftier positions. If range or step between is large enough, the "
           "points offset may be seems as incorrect, but it's as is because of low resolution of console output. "
           "Example, avarage temperature between 15-16 PM will draw at 15 as one point aligned left. If records "
           "less than screen width, then draw all possible points with steps. For calculations using math 'round' "
           "function, so 1.5 will be 2.0 and 1.4 will be 1.0. Uncomment in code for using 'trunc' function. With "
           "a lot of data records possible floating point errors. Integer algorithm needs more complexity.\n");
    printf("\tMaximum memory limit is 1Gb. If needed to free all memory and unload device, enter 0 or zero in "
           "global settings. If memory limit is lower than already loaded data, then setting unchanged. "
           "To output all debug setups to text file, call program with any argument.\n");
    printf("\t'Effective temperature' from source task is incorrect, because it's used for space objects, instead "
           "we using 'feels like' floating point paramater as in game 'The Long Dark'.\n");
}

void device_set_active(int dev)
{   // Включение или исключение прибора из списка активных. Для улучшения структуры и читабельности.
    unsigned int i;
    for (i = 0; i < DEVICE_MAX && devices_active[i] != dev; ++i)
        ;
    if (i < DEVICE_MAX && devices_active[i] == dev) {
        while (i < DEVICE_MAX - 1) {
            devices_active[i] = devices_active[i + 1];
            ++i;
        }
        printf("Device '%s' is active, set device off, compact data to size %u.\n",
               file_names[dev], --devices_act_size);
    } else if (dev < DEVICE_MAX) {
        devices_active[devices_act_size++] = dev;
        printf("Device '%s' is inactive, set device on and add to list, new size %u.\n",
               file_names[dev], devices_act_size);
        for (i = 0; i < devices_loaded && devices[i] != dev; i++)
            ;
        if (i == devices_loaded)
            printf("Warning, device not loaded to memory don't forget to push 'load'.\n");
    } else
        printf("Device index %u is more than %u maximum device.\n", dev, DEVICE_MAX - 1);
}

void field_set_active(int field)
{   // Включение или исключение поля данных из списка активных.
    // Хотя бы один прибор должен быть активен, но не обязательно загружен.
    unsigned int i;
    if (devices_act_size == 0) {
        printf("\nNo active devices selected, select active device in main menu and retry.\n");
        return;
    }
    for (i = 0; i < FIELDS_MAX && fields_selected[i] != field; ++i)
        ;
    if (i < FIELDS_MAX && fields_selected[i] == field) {        // Осторожней здесь с порядком исполнения.
        while (i < FIELDS_MAX - 1) {
            fields_selected[i] = fields_selected[i + 1];
            ++i;
        }
        printf("\nField '%s' in list, set field to OFF, compact data to size %u.\n",
               data_fields[field], --fields_sel_size);
    } else {
        for (i = 0; i < devices_act_size && fields_index[devices_active[i]][field] == -1; ++i)
            ;
        if (i == devices_act_size)
            printf("\nField '%s' is not founded in any active device. Load and select active device with field.\n",
                   data_names[field]);
        else {
            fields_selected[fields_sel_size++] = field;
            printf("\nField '%s' founded at %d, set field to ON and add to list, new size %u.\n",
                   data_names[field], fields_index[devices_active[i]][field], fields_sel_size);
        }
    }
}

void set_global_settings(void)
{   // Функция установки глобальных настроек времени, графика и памяти.
    const unsigned int range = 2;                               // Вспомогательные данные и интервалы.
    struct tm input_date[2];                                    // Желательно добавить обнуление всех параметров.
    const char* input_txt[] = { "First", "Last", "cold", "hot" };
    printf("\nEnter first date and time in format '%s' exactly, or 'enter' to remain unchanged. "
           "Example '2023-02-21 15:00:00'.\n", date_time_format);
    for (unsigned int i = 0, j; i < range; ++i) {
        printf("%s date and time in file: ", input_txt[i]);
        for (j = 0; (text[j] = getchar()) != '\n'; ++j)         // Если не беспокоит предупреждение, то "scanf("%[^\n]", s)"
            continue;                                           // Что делает continue? ;)
        text[j] = '\0';
        printf("Entered string check '%s', ", text);
        if (j > 0) {                                            // Не очень удачная конструкция.
            if ((string_to_time(text, &input_date[i], date_time_format)) == -1) {
                printf("error conversion input date and time.\n");
                return;
            } else
                printf("date and time is correct.\n");
        } else {
            printf("date and time remain ucnhanged.\n");
            input_date[i] = (i == 0) ? first : last;
        }
    }
    if (mktime(&input_date[0]) >= mktime(&input_date[1])) {     // Дата позже должна быть после начала хотя бы на одну секунду.
        printf("First date is later or equal than last date, return to menu.\n");
        return;
    }
    first = input_date[0]; last = input_date[1];
    printf("Enter hour's arithmetic mean in charts, 0 - as is and max 24 hours as day: ");
    unsigned int input_data = 0;
    scanf("%u", &input_data);
    if (input_data > hours_per_day) {
        printf("Arithmetic hours in charts must be between 0 and 24.\n");
        return;
    }
    chart_hours = input_data;
    printf("Chart types: ");                                    // Типы отображения графиков.
    for (unsigned int i = 0; i < sizeof(chart_names) / sizeof(char*); ++i)
        printf("%u:%s ", i, chart_names[i]);
    printf("\nChoose a type for global setting: ");
    scanf("%u", &input_data);
    if (input_data > ch_lines) {
        printf("Chart type must be in range, reamain unchanged.\n");
        return;
    }
    global_chart = input_data;
    float input_float[2];
    for (unsigned int i = 0; i < range; ++i) {
        printf("Enter 'feels like %s' parameter from %+.2f to %+.2f in celsius: ",
               input_txt[range + i], temperature_min, temperature_max);
        scanf("%f", &input_float[i]);
    }
    if (input_float[0] > input_float[1] || input_float[0] < temperature_min || input_float[1] > temperature_max) {
        printf("Feels like temperatures incorrect or out of range min/max celsius.\n");
        return;
    }
    feels_like_cold = input_float[0]; feels_like_hot = input_float[1];
    unsigned int lower_limit = (data_total > 0) ? data_total : 1;
    printf("Global records limit from %u to %u in records or 0 to free all memory: ", lower_limit, global_data_max);
    scanf("%u", &input_data);
    if (input_data == 0) {                                      // Освобождаем всю динамическую память.
        if (devices_loaded == 0) {
            printf("No devices loaded to memory, nothing to free.\n");
            return;
        }
        printf("Remove all %u loaded devices from memory.\n", devices_loaded);
        for (unsigned int i = 0; i < devices_loaded; ++i)
            device_remove(devices[i]);
        return;
    }
    if (input_data > global_data_max || input_data < lower_limit)
        printf("Global records limit is out of range, remain unchanged %u.\n", global_data_max);
    else
        data_max_size = input_data;
}

void exec_debug_setup(char setup)
{   // Установка настроек и данных для тестирования и исполнение функций программы.
    printf("\nSetup '%c' debug data and execute program functions.\n\n", setup);
    unsigned int si = setup - 'A', i, dev;
    if (devices_loaded > 0) {
        printf("Some devices already loaded to memory, removing and free data.\n");
        for (i = 0, dev = devices_loaded; i < dev; ++i)
            device_remove(devices[0]);
    } else
        printf("No devices loaded, nothing to free from memory.\n");
    printf("Loading setup from settings data index %u.\n", si);
    data_max_size = debug_setups_data[si].memory / weather_size;
    chart_hours = debug_setups_data[si].avaraged_hours;
    devices_act_size = debug_setups_data[si].devices;
    for (i = 0; i < devices_act_size; ++i) {                    // Устанавливаем активные устройства и интервалы для загрузки.
        devices_active[i] = debug_setups_data[si].dev_active[i];
        first = debug_setups_data[si].dev_load_t[i * 2];
        last = debug_setups_data[si].dev_load_t[i * 2 + 1];
        dev = devices_active[i];
        load_csv_data(file_names[dev], dev, &first, &last);
        devices_timestamp[i * 2] = first;
        last = devices_timestamp[i * 2 + 1] = last;          
    }
    fields_sel_size = debug_setups_data[si].fields;
    for (i = 0; i < fields_sel_size; i++)
        fields_selected[i] = debug_setups_data[si].fields_active[i];
    first = debug_setups_data[si].t_first;                      // Немного рискованный код, но для простой структуры ок.
    last = debug_setups_data[si].t_last;
    global_chart = debug_setups_data[si].g_chart;               // Остальные глобальные настройки для графиков.
    feels_like_cold = debug_setups_data[si].like_cold;
    feels_like_hot = debug_setups_data[si].like_hot;
    if (debug_setups_data[si].is_feels_like == 1)               // Для всех устройств сразу и для глобального времени.
        update_feels_like_temp();
    print_fields_tab();
    switch (setup) {
    case 'A': {                                                 // Температура 4-ех устройств ровно по ширине и со смещениями.
        for (i = 0; i < fields_sel_size; ++i)
            if (print_field_chart(fields_selected[i], global_chart) > 0)
                print_screen();
        break;
    } case 'B': {                                               // График по точкам с усреднением в час.
        if (print_field_chart(fields_selected[0], global_chart) > 0)
            print_screen();
        global_chart = ch_lines;                                // Сразу же для проверки график с построением линий.
        if (print_field_chart(fields_selected[0], global_chart) > 0)
            print_screen();
        break;
    } case 'C': {                                               // Столбцы влажности с пересечением.
        if (print_field_chart(fields_selected[0], global_chart) > 0)
            print_screen();
        break;
    } case 'D': {                                               // Температура ощущения и построение градиента.
        print_all_records();
        if (print_field_chart(fields_selected[0], global_chart) > 0)
            print_screen();
        break;
    } case 'E': {                                               // Температура за сутки линейно, с усреднением.
        if (print_field_chart(fields_selected[0], global_chart) > 0)
            print_screen();
        break;
    } case 'F': {                                               // Отладка на ошибки функции загрузки и управления памятью.
        printf("\nIn this debug setup nothing to draw, just testing loading data.\n");
        break;
    } default:
        printf("Setup debug '%c' incorrect.\n", setup);
    }
    printf("\nDebug setup '%c' complete.\n", 'A' + si);
}

int main(int argc, char* argv[])
{   // Основной код программы, если есть любой параметр командной строки, то включается режим автоматической отладки.
    printf("Reading weather sensors, some analysis and drawing charts.\n");
    if (argc >= 2) {
        printf("Program called with %d arguments:\n", argc);
        while (argc)
            printf("'%s' ", argv[--argc]);
        printf("\n");
        is_debug = 1;
    } else
        printf("Programm called without arguments, using interactive mode.\n");
    // Инициализация данных по умолчанию и заполнение минимума глобальных данных.
    for (unsigned int idx = 0; idx < DEVICE_MAX; ++idx) {
        data[idx] = NULL;
        data_sizes[idx] = 0;
        fields_loaded[idx] = 0;
        for (unsigned int field = 0; field < FIELDS_MAX; ++field) {
            fields_index[idx][field] = -1;
            fields_selected[field] = -1;
        }
        devices_active[idx] = -1;
        devices[idx] = -1;
    }
    fields_sel_size = 0;
    devices_act_size = 0;
    first.tm_hour = 15; first.tm_min = 0; first.tm_sec = 0;
    first.tm_year = 123; first.tm_mon = 01; first.tm_mday = 21;
    last.tm_hour = 17; last.tm_min = 00; last.tm_sec = 0;
    last.tm_year = 123; last.tm_mon = 01; last.tm_mday = 21;
    if (!is_debug) {                                            // Основной интерактивные режим.
        char key = ' ';
        while (key != 'X') {
            printf("\n\nWelcome to My Summer Holidays in the Countryside!\n\n");
            // printf("\nProgram status and global information.\n\n");
            printf("Device(file):\t\t\tLoaded records:\tMemory(bytes):\tActive:\tTime from:\t\t\tTime to:\n");
            for (int i = 0; i < (int)(sizeof(file_names) / sizeof(char*)); ++i) {
                printf("%-32s", file_names[i]);
                printf("%-16u%-16u", data_sizes[i], data_sizes[i] * sizeof(struct weather));
                if (is_dev_active(i) != DEVICE_MAX)
                    printf("active\t");
                else
                    printf("-\t");
                if (is_dev_loaded(i) != DEVICE_MAX) {
                    strftime(text, TEXT_MAX, date_time_format, &data[i][0].timestamp);
                    printf("'%s'\t\t", text);
                    strftime(text, TEXT_MAX, date_time_format, &data[i][data_sizes[i] - 1].timestamp);
                    printf("'%s'\n", text);
                } else
                    printf("-\t\t\t\t-\n");
            }
            printf("Total all devices:\t\t%-16u%-16u%u\tfree records: %u (%u bytes free).\n",
                   data_total, data_total * weather_size, devices_act_size, data_max_size - data_total,
                   (data_max_size - data_total) * weather_size);
            printf("\nGlobal active fields, total %u: ", fields_sel_size);
            for (unsigned int i = 0; i < fields_sel_size; ++i)
                printf("'%s' ", data_names[fields_selected[i]]);
            strftime(text, TEXT_MAX, date_time_format, &first);
            printf("\nGlobal date and time range: '%s' -> ", text);
            strftime(text, TEXT_MAX, date_time_format, &last);
            printf("'%s', arithmetic mean hours in charts %u.\n", text, chart_hours);
            printf("Global chart type '%s', 'feels like' cold %.2f and hot %.2f celsius.\n",
                   chart_names[global_chart], feels_like_cold, feels_like_hot);
            printf("\n");                                       // Главное меню и выбор.
            printf("[1] Structure of weather data and system information.\t\t\t");
            printf("[6] Set on/off data fields from weather records.\n");
            printf("[2] Fields of data exist and loaded from device's file.\t\t\t");
            printf("[7] Print chart using global settings and chart type.\n");
            printf("[3] Output weather records in all active devices.\t\t\t");
            printf("[8] Calculate 'feels like' for all active devices.\n");
            printf("[4] Set date and time glogal range, mean hours and chart type.\t\t");
            printf("[9] (Re)load all active devices to memory.\n");
            printf("[5] Set on/off active devices from list.\t\t\t\t");
            printf("[0] Load debug setup for all data and run tests.\n");
            printf("\nChoose an action or press (X) to pay respect: ");
            do {                                                // Удаляем лишние символы или коды, если они были введены.
                key = toupper(getchar());
            } while ((key < '0' || key > '9') && (key != 'X'));
            switch (key) {
            case '1': {                                         // Вывод системной информации и тестирование экрана.
                system_information();
                break;
            } case '2': {                                       // Вывод таблицы выбранных полей структуры(параметров) для вывода.
                print_fields_tab();
                break;
            } case '3': {                                       // Вывод всех записей, которые хранятся в памяти.
                print_all_records();
                break;
            } case '4': {                                       // Установка временного интервала, усредненного часа типа графика.
                key = getchar();
                set_global_settings();
                break;
            } case '5': {                                       // Выбор активных приборов для обработки.
                char dev_lim = '0' + DEVICE_MAX - 1;
                printf("\nEnter device's digit [0..%c] to set on/off: ", dev_lim);
                do {
                    key = toupper(getchar());
                } while (key < '0' || key > dev_lim);
                device_set_active(key - '0');
                break;
            } case '6': {                                       // Выбор полей данных в структуре для вывода.
                char key_lim = '0' + (char)data_fields_size - 1;
                printf("\nIndex:\tField:\n");
                for (unsigned int field = 0; field < data_fields_size; ++field)
                    printf("%u\t'%s'\n", field, data_names[field]);
                printf("Enter field's char[1..%c] to set on/off or enter to skip: ", key_lim);
                do {
                    key = toupper(getchar());
                } while (key < '1' || key > key_lim);
                field_set_active(key - '0');
                break;
            } case '7': {                                       // Вывод графиков по интревалу и параметрам.
                if (fields_sel_size > 0) {
                    for (unsigned int field = 0; field < fields_sel_size; ++field)
                        if (print_field_chart(fields_selected[field], global_chart) > 0)
                            print_screen();                     // Все выбранные поля и глобальная настройка графика.
                } else
                   printf("\nNo active fields selected, nothing to draw, select fields in main menu.\n");
                break;
            } case '8': {                                       // Вычисление температуры ощущения для всех устройств.
                update_feels_like_temp();
                break;
            } case '9': {                                       // Загрузка данных активных приборов в память.
                if (devices_act_size) {
                    printf("\nReloading all active %d devices to memory.\n", devices_act_size);
                    for (unsigned int dev = 0; dev < devices_act_size; ++dev)
                        load_csv_data(file_names[devices_active[dev]], devices_active[dev], &first, &last);
                } else
                    printf("\nNo active devices selected, nothing to (re)load.\n");
                break;
            } case '0': {                                       // Отладочные сценарии по выбору.
                char key_lim = 'A' + debug_setups - 1;
                for (unsigned int i = 0; i < debug_setups; ++i)
                    printf("\n\t%s", debug_setups_info[i]);
                printf("\n\nChoose debug setup to execute: ");
                do {
                    key = toupper(getchar());
                } while (key < 'A' || key > key_lim);
                exec_debug_setup(key);
                break;
            } case 'X': {                                       // Выход.
                printf("Exit with respect, see you in the next prog, code 0.\n");
                break;
            } default:
                printf("\nError in menu action, key '%c'.\n", key);
            }
        }
    } else {                                                    // Автоматическая отладка, все сценарии.
        printf("\nAuto debug mode, calling system info and all debug setups, saving to text files and exit.\n");
        FILE* debug_file = freopen("debug_info.txt", "w", stdout);
        if (debug_file != NULL) {
            system_information();
            fclose(debug_file);
        } else {
            printf("Can't create 'debug_info.txt' file, check disk/attributes.\n");
            return -1;
        }
        for (unsigned int i = 0; i < debug_setups; ++i) {
            debug_file_name[6] = 'a' + i;
            debug_file = freopen(debug_file_name, "w", stdout); // Переназначаем стандартный вывод в файл.
            if (debug_file == NULL) {
                printf("Can't create debug text file '%s', check disk/attributes.\n", debug_file_name);
                return -1;
            }
            printf("%s\n", debug_setups_info[i]);
            exec_debug_setup('A' + i);
            fclose(debug_file);
        }
    }
    return 0;
}
