cmake_minimum_required(VERSION 3.5)

project(Theory-C LANGUAGES C)

set(CMAKE_C_FLAGS "-Wall -Wextra")
aux_source_directory(. SOURCES)
aux_source_directory(./Extra SOURCES)
add_executable(Theory-C ${SOURCES})
