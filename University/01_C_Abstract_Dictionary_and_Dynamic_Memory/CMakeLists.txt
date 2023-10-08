cmake_minimum_required(VERSION 3.5)

project(Questions-C LANGUAGES C)

#set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS "-std=c11 -Wall -Wextra -O0")
aux_source_directory(. SOURCES)
add_executable(Questions-C ${SOURCES})
