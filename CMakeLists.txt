project(academic)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
aux_source_directory(./labs-0x00 SRC_LIST)
aux_source_directory(./labs-0x01 SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

#include_directories ("${PROJECT_SOURCE_DIR}/labs-0x01")
#add_executable(chapter02 labs-0x01/chapter02.cpp )
#add_subdirectory(labs-0x01)
