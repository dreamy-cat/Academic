﻿# Задание 4. Демонстрационное тестирование 2024, никаких гарантий, всё как есть! :)
# Автор: Alexander BitsCode. Лицензия: Creative Commons.
# Архив: https://www.youtube.com/@BitsCode/. Исходный код: https://github.com/dreamy-cat/Academic.
# Дополнительно: алгоритм Хаффмана, префиксное дерево и не забыть реализовать самим на ассемблере распаковку 'GIF'.

# Задание решается карандашом, главное правило - не один код, не может быть началом другого, т.е. условие Фано или префиксный код.
# Подробнее можно посмотреть на Вики, но главное внимательность, не обсчитаться в битах и не просмотреть короткую комбинацию.
# Удобней всего анализировать последовательности, подбирая сначала самые короткие варианты и пробегая по исходным данным, 
# определять "закрыт путь" по этой комбинации или можно продолжать, если хотя бы существует противоречие с одной буквой или данными,
# то вариант отбрасывается и берётся следующий. Кодом применяются простые строковые операции и увеличение двоичного кода.

print('    Задание 4. Демонстрационное тестирование 2024, никаких гарантий, всё как есть! :)\n')

print('    По каналу связи передаются сообщения, содержащие только восемь букв: А, Б, В, Г, Д, Е, Ж и З.'
      ' Для передачи используется двоичный код удовлетворяющий условию Фано. Кодовые слова для некоторых '
      'букв известны: А - 000, Б - 001, В - 0101, Г - 0100, Д - 011, Е - 101. Какое наименьшее количество '
      'двоичных знаков потребуется для кодирования двух оставшихся букв? '
      'В ответе запишите суммарную длину кодовых слов для букв: Ж, З.')
print('    Решение карандашом: прежде всего стоит посмотреть на общие длины исходных кодов и проверить '
      'занятые и свободные комбинации. По возрастанию: 0 и 1 заняты сразу; 00, 01, 10 заняты, '
      'а 11 код свободен и "пути" открыты. Есть смысл 110 и 111 закрывать оба кода с длинной три. '
      'Или предположить 11 - буква Ж, а буква З - 100 свободный 3 битный  код. Т.е. результат: 3 + 2 = 5 бит.')

def AvailCodes(tree : list, level : int, isOut : bool):
    # Вычисление всех доступных кодов, заданного уровня или длины двоичных кодов.
    code = ['0'] * level; avail = []; codesMax = 0x01 << level; i = 0
    if (isOut):
        print('\nОпределяем все доступные коды длины', level, 'из', codesMax, 'возможных комбинаций для дерева:', tree)
    # Перебираем все возможные варианты.
    while (i < codesMax):                                   
        codeTxt = ''.join(code); isExist = False; j = 0
        if (isOut):
            print('Следующий код:', codeTxt, end=': ')
        # Сравниваем не только начало, но возможное продолжение битового кода, иначе дерево некорректно.
        while (not isExist and j < len(tree)):
            if (tree[j].startswith(codeTxt) == True or codeTxt.startswith(tree[j]) == True):
                isExist = True
            else:
                j += 1
        # Если код удовлетворяет условию Фано, то сохраняем его в список.
        if (isExist == False):
            if (isOut):
                print('не является началом или продолжением имеющихся кодов, добавляем в список доступных.')
            avail += [codeTxt]
        else:
            if (isOut):
                print('является началом или продолжением', tree[j], 'и не удовлетворяет условию Фано.')
        # Итерация кода по возрастанию, начиная с самого правого разряда.
        k = len(code) - 1
        while True:
            if (code[k] == '0'):
                code[k] = '1'
                break
            else:
                code[k] = '0'
            # Проверки на отрицательное число нет, но исходим из верного перамерта 
            k -= 1
        i += 1
    return avail

# Решение кодом, демонстрационный вариант, через строковые переменные, можно выбрать.
tree = [ '000', '001', '0101', '0100', '011', '101' ]
charsAll = 8; charsDef = len(tree); isOpen = False
# Решение кодом, вариант 59682, ответ 8 бит.
#tree = [ '00', '1000', '111', '1001', '01', '110' ] 
#charsAll = 8; charsDef = len(tree); isOpen = False
# Решение кодом, вариант 27263, учета частоты нет, ответ: 19 бит и наш расклад 16 бит.
#tree = [ '000', '01', '1101', '111', '0010', '100' ]
#charsAll = 9; charsDef = len(tree); isOpen = True

print('\nРешение демонстрационного варианта кодом, определить наименьшие возможные коды не заданных букв.\n')
print('Всего исходных данных букв(параметыов):', charsAll, 'из них определено префиксным кодом:', charsDef)
print('Исходные префиксные коды:', tree)
if (isOpen):
    print('В решении необходимо учесть "открытость" оставшихся кодов, т.е. увеличиваем буквы на +1.')
    charsAll += 1
else:
    print('В решении добавления новых кодов не предусмотрено, можно закрывать последовательности.')
print('Считается, что одинаковых кодов изначально нет и она решаема и с проверкой пути только до следующего уровня.')
print('Решаем задание постепенным увеличением размера кода и простым перебором его вариантов с учётом исходных данных.\n')
codeLen = 1; codeLenMax = 3; newBits = 0
while (charsDef < charsAll):
    codeAvail = AvailCodes(tree, codeLen, True); i = 0
    print('\nДобавляем коды с учетом числа оставшихся букв и открытости пути из возможных:', codeAvail)
    # Добавить 2 кода: 11 + 100 = 5 бит. По хорошему нужно искать минмиум.
    # Добавить 3 кода: 11, следа: 100 - не хватет, 1000 и 1001 = 10 бит. 100 + 111 + 110 = 9 бит.
    while (i < len(codeAvail) and charsDef < charsAll):
        print('\nКод: ', codeAvail[i], ', предположим что код добавлен, анализируем дальнейшие пути, глубина (+1).', sep='')
        subTree = AvailCodes(tree, codeLen + 1, False)
        addTree = tree + [codeAvail[i]]
        addCodeAvail = AvailCodes(addTree, codeLen + 1, False)
        charsRem = charsAll - charsDef
        # Определяем наиболее оптимальный вариант с учетом горизонта только следующего уровня.
        print('Свободно на следующем уровне без добавления кода: ', len(subTree), ', с добавлением: ',
              len(addCodeAvail), ', букв: ', charsRem, sep='')
        if (charsRem <= len(codeAvail)):
            print('Код допустим, т.к. свободных кодов достаточно для оставшихся букв.')
            tree.append(codeAvail[i])
            charsDef += 1; newBits += len(codeAvail[i])
        elif (charsRem - len(codeAvail) - i <= len(addCodeAvail)):
            print('Код допустим, т.к. его добавление оставляет пространство кодов на следующем уровне.')
            tree.append(codeAvail[i])
            charsDef += 1; newBits += len(codeAvail[i])
        else:
            # Или можно использовать более краткое условие выше, но так видно какое именно решение принято.
            print('Код пропускаем, т.к. закрытие "пути" приведет к увеличению на горизонте (+1).')
        print('Всего:', charsDef, 'букв определено из', charsAll, end=' искомых.\n')
        i += 1
    print('Все комбинации в пределах длины кода', codeLen, 'обработаны, увеличиваем до', codeLen + 1, end='.\n\n')
    codeLen += 1
print('\nВсе определенные коды: ', tree, ', всего новых бит: ', newBits, sep='', end='.\n')

#   Дополнительные примеры решение только текстом. Два с отдельными буквами, два со словами и одно с неиспользуемым сигналом.

#   №13351, задание где присутствуют обычно только буквы, но здесь цвета, ответ: 110.
#   Для кодирования растрового рисунка, напечатанного с использованием шести красок, применили неравномерный двоичный код.
#   Для кодирования цветов используются кодовые слова: белый - 0; черный - 10; красный - 1110; зеленый - 11111; 
# фиолетовый - 11110 и синий - неопределен. Укажите кратчайшее кодовое слово для кодирования синего цвета, при котором код
# будет удовлетворять условию Фано. Если таких кодов несколько, укажите код с наименьшим числовым значением.
#   Решение: сразу можно отметить, что т.к. 0 и 10 заняты, значит уже ход комбинациям совпадения - закрыт, 00,
# 000 и т.д. невозможны, как и не возможны 101 или 100 и т.д. Далее, четыре единицы заняты все, также используется 1110, 
# т.е. 11100 тоже закрыто. Пять цифр или бит, заняты всё возможные и 0 и 1. Остается 110 как неиспользуемый и краткий.

#   №10406, задание где присутствуют просто буквы, но в ответ требуется сумма бит все неизвестных букв, ответ: 18 бит.
#   По каналу связи передаются только сообщения, содержащие только буквы А, Б, В, Г, Д, Е. Для передачи используется 
# неравномерный двоичный код, удовлетворяющий условию Фано; для букв А, Б, В используются такие кодовые слова: А - 1, 
# Б - 010, В - 001.
#   Какова наименьшая возможная суммарная длина всех кодовых слов?
#   Решение: в данном задании необходимо определить все оставшиеся буквы Г, Д, Е и сложить количество бит в них.
# Сразу определяем закрытые "пути", это всё что начинается с 1, т.к. она занята А и все последующие невозможны, например 10.
# 01 и 00 также невозможны т.к. использованы уже более длинные коды. Первые краткие биты это 000 и 011. Но тогда не хватит
# на один символ, а пути будут закрыты. Следовательно оставим 011 для Г. А 000 расширим, т.е. Д - 0001 и Е - 0000.
# В итоге сумма букв А-Е составит 1 + 3 + 3 + 3 + 4 + 4 = 18 бит всего требуется для этого варианта.

#   №38938, подобный тип заданий будет требовать уже анализа слов(а),  ответ: 15 бит с учетом оставшегося алфавита.
#   Все заглавные буквы русского алфавита закодированы неравномерным двоичным кодом, в котором никакое кодовое слово не
# является началом другого кодового слова. Это условие обеспечивает возможность однозначной расшифровки закодированных
# сообщений. Кодовые слова для некоторых букв известны: П - 00, Е - 01, Н - 110. Какое наименьшее количество двоичных
# знаков может содержать код слова "ПАНАМА"?
#   Решение: сначала крактий анализ данного слова. Посмотреть какие буквы уже есть и каких не хватает в исходных данных.
# "П" и "Н" определены и используются. "Е" - не используется, но занимает место в коде. "А" и "М" не определены, но
# используются. Т.к. по условию мы должны использовать минимально возможное количество бит, то наиболее часто встречаемые
# буквы, желательно закодировать более коротким кодом. Коды 00 и 01 заняты т.е. все "пути" дальше 001 или 011 невозможны.
# Комбинация 11 невозможна, иначе заблокируется 110. Первый краткий код это 10, и путь дальше открыт и можно использовать
# для двух букв 3-битный код или закрыть оставшуюся комбинацию для 3 бит, это 111, но по условию у нас тогда оставшийся
# алфавит невозможен. Т.е. А - 10, а М - 1110 минимум. В итоге слово "ПАНАМА" будет весить: 2 + 2 + 3 + 2 + 4 + 2 = 15 бит.

#   №39233, подобный тип заданий требует уже анализ слов(а), ответ: 14 бит с учётом оставшегося алфавита.
#   Все заглавные буквы русского алфавита закодированы неравномерным двоичным кодом, в котором никакое кодовое слово не
# является началом другого кодового слова. Это условие обеспечивает возможность однозначной расшифровки закодированных
# сообщений. Кодовые слова для некоторых букв известны: М - 11, Л - 10, У - 001. Какое наименьшее количество двоичных
# знаков может содержать код слова "МОЛОКО".
#   Решение: сначала краткий анализ самого слова. Посмотреть какие буквы уже имеются и какие отсутвуют. 
# "М" и "Л" - определены и есть в слове, встречаются по одному разу. "У" - опеределна, но не встречается в слове, т.е.
# занимает код. "О" и "К" - не определены, но ипользуюся 3 и 1 раз соответственно. Т.е. "О" есть смысл кодировать короче.
# По кодам, стартовые 11 и 10 начинаются с единицы, и "пути" дальше закрыты, 111 или 101 невозможны. Первый краткий
# код 01 - два бита лучше для "О". К остается минимальный в 000, как дополнение 001. Но при этой ситуации, закрывются
# "пути" для остального алфавита. Поэтому, для К уже придется брать 4 бита, это 0000 или 0001. 
# Полная сумма слова: 2 + 2 + 2 + 2 + 4 + 2 = 14 бит.

#   №48425, задание с неиспользуемыми сигналами и заданным словом, ответ: 19 бит с алфавитом.
#   Все заглавные буквы русского алфавита закодированы неравномерным двоичным кодом, в которм никакое кодовое слово не
# является началом другого кодового слова. Это условие обеспечивает возможность однозначной расшифровки зкодированных
# сообщений. Известны кодовые слова некоторых букв: Я - 00, Н - 011, З - 111. Какое наименьшее число двоичных знаков
# может содержать код слово "БАРАБАН"?
#   Решение: анализируем слово и буквы в нём. Какие буквы уже закодированы и испоьзуются, а какие нет.
# "Я" - не используется, но занимает код и нуль или все пути по двум нулям и далее невозможны. "Н" один раз встречается и
# закодировано. "З" - не используется и занимает 111 и далее. Плюс остальной алфавит, т.е. необходимо оставить выход.
# Самый короткий вариант 01, 11, 10 - подходит только последний, первые два уже существуют. Логично установить "А" - 10,
# т.к. встречается 3 раза. "Б" - два раза, из 010 есть ход. Оставшуюся "Р" - 1110 чтобы оставить путь для остальных.
# Всего в слове: 3 + 2 + 4 + 2 + 3 + 2 + 3 = 19 бит.
