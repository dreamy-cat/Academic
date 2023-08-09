cmake_minimum_required(VERSION 3.5)

project(C-Primer-Plus LANGUAGES C)

#GCC compiler flags and settings.
#set(CMAKE_C_FLAGS "-Wall -Wextra -O0")

#MS compiler flags and settings.
# -Od - needs to replace manualy.
set(CMAKE_C_FLAGS "/Qspectre -Wall -wd4710")
aux_source_directory(. SOURCES)
add_executable(C-Primer-Plus ${SOURCES})
