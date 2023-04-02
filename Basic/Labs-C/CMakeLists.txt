project(Labs-C)
cmake_minimum_required(VERSION 3.5)

# Enable to see code generated, using GCC.
# set(CMAKE_C_FLAGS "-Wall -Wextra")

# Enable if using MSVC compiler.
set(CMAKE_C_FLAGS "-O0 -Wall -wd4710")

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
