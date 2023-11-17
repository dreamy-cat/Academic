cmake_minimum_required(VERSION 3.5)

project(CPP_Binary_Search_Tree LANGUAGES CXX)

# GCC compiler flags and settings. Флаги и настройки для компилятора GCC.
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -O0") # -S -masm=intel -fverbose-asm")

#
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "-static")

#MS compiler flags and settings.
# -Od - needs to replace manualy.
#set(CMAKE_C_FLAGS "/Qspectre -Wall -wd4710")

aux_source_directory(. SOURCES)
add_executable(CPP_Binary_Search_Tree ${SOURCES})
