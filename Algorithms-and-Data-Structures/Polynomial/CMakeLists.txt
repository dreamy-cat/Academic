cmake_minimum_required(VERSION 3.5)

project(Polynomial LANGUAGES C)

set(CMAKE_C_FLAGS "-std=c11 -Wall -Wextra -O0")

add_executable(Polynomial main.c)
