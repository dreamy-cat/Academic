cmake_minimum_required(VERSION 3.5)

project(Rational-Numbers LANGUAGES C)

set(CMAKE_C_FLAGS "-std=c11 -Wall -Wextra -O0")
aux_source_directory(. SOURCES)
add_executable(Rational-Numbers ${SOURCES})
