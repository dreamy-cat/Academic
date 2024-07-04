cmake_minimum_required(VERSION 3.5)

project(CPP-Programming-Language LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -O0")
# -S -masm=intel -fverbose-asm")
aux_source_directory(. SRC_DIR)
add_executable(CPP-Programming-Language ${SRC_DIR})

# Change for the other platforms, if needed.
# target_link_libraries(${PROJECT_NAME} -lwinpthread)
# target_link_libraries(${PROJECT_NAME} -lpthread)
