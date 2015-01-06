project(academic)
cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)
aux_source_directory(./labs_0x00 SRC_LIST)
aux_source_directory(./labs_0x01 SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})
