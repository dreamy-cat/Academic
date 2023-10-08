cmake_minimum_required(VERSION 3.5)

project(Weather_Sensors_and_Charts LANGUAGES C)

#GCC compiler flags and settings.
set(CMAKE_C_FLAGS "-Wall -Wextra -O0 -std=c11")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

#MS compiler flags and settings.
# -Od - needs to replace manualy.
#set(CMAKE_C_FLAGS "/Qspectre -Wall -wd4710")

aux_source_directory(. SOURCES)
add_executable(Weather_Sensors_and_Charts ${SOURCES})
