cmake_minimum_required(VERSION 3.5)

project(C_Binary_Search_Tree C)

# GCC compiler flags and settings. Флаги и настройки для компилятора GCC.
# set(CMAKE_C_FLAGS "-Wall -Wextra -O0 -std=c11")

# Link flags for static build. Флаги для статической сборки.
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

#MS compiler flags and settings.
# -Od - needs to replace manualy.
#set(CMAKE_C_FLAGS "/Qspectre -Wall -wd4710")

aux_source_directory(. SOURCES)
add_executable(C_Binary_Search_Tree ${SOURCES})
