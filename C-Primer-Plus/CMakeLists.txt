cmake_minimum_required(VERSION 3.5)

project(C-Primer-Plus LANGUAGES C)

#GCC compiler flags and settings.
#set(CMAKE_C_FLAGS "-Wall -Wextra -O0")

#MS compiler flags and settings.
set(CMAKE_C_FLAGS "-O0 -Wall -wd4710")
aux_source_directory(. SOURCES)
add_executable(C-Primer-Plus ${SOURCES})
