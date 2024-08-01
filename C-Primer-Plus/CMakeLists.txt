cmake_minimum_required(VERSION 3.5)

project(C-Primer-Plus LANGUAGES C)

# Compile with GCC or MSVS tools, x86 recommended, some warnings remains as is.
# Выбор компилятора по вкусу, по-умолчанию все настройки остаются как есть, рекомендуется 32 бита.
# Проверено на GCC и MSVS, минимальные предупреждения должны остатся для демонстрации языковых конструкций.

# GCC compiler flags and settings, uncomment to some extra output.
# Флаги для компилятора GCC, раскоментировать если требуется дополнительный вывод.
#set(CMAKE_C_FLAGS "-Wall -Wextra -O0")

# MSVS compiler flags and settings, uncomment for some extra output.
# Флаги компилятора MSVS, раскоментировать если требуется дополнительный вывод.
#set(CMAKE_C_FLAGS "/Qspectre -Wall -wd4710")

aux_source_directory(. SOURCES)
add_executable(C-Primer-Plus ${SOURCES})
