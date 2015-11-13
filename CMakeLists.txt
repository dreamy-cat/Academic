project(academic)
cmake_minimum_required(VERSION 2.8)

#Needs for some tasks from chapter 11, 12, 15.
#set(CMAKE_CXX_FLAGS "-Wa,-alh")

#C++11
#set(CMAKE_CXX_FLAGS "-std=c++11")

aux_source_directory(. SRC_LIST)
aux_source_directory(./labs_0x00 SRC_LIST)
aux_source_directory(./labs_0x01 SRC_LIST)
aux_source_directory(./labs_0x02 SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

