project(academic)
cmake_minimum_required(VERSION 2.8)

#Needs for some tasks from chapter 11, 12, 15.
#set(CMAKE_CXX_FLAGS "-Wa,-alh")
set(CMAKE_CXX_FLAGS "-Wall")

# Other version of GCC.
#set(CMAKE_CXX_COMPILER "/usr/local/bin/c++")
#set(CMAKE_LIBRARY_PATH "/usr/local/lib64")

set(CMAKE_CXX_FLAGS "-std=c++14")

aux_source_directory(. SRC_LIST)
aux_source_directory(./labs_0x00 SRC_LIST)
aux_source_directory(./labs_0x01 SRC_LIST)
aux_source_directory(./labs_0x02 SRC_LIST)
aux_source_directory(./labs_0x04 SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

