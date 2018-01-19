project(academic)
cmake_minimum_required(VERSION 2.8)

#set(CMAKE_CXX_FLAGS "-Wa,-alh")
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_CXX_FLAGS "-std=c++14")

aux_source_directory(. SRC_LIST)
aux_source_directory(./labs_0x00 SRC_LIST)
aux_source_directory(./labs_0x01 SRC_LIST)
aux_source_directory(./labs_0x02 SRC_LIST)
aux_source_directory(./labs_0x03 SRC_LIST)
aux_source_directory(./labs_0x04 SRC_LIST)
aux_source_directory(./labs_0x05 SRC_LIST)
aux_source_directory(./labs_0x06 SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

# Change for the other platforms, if needed.
target_link_libraries(${PROJECT_NAME} -lwinpthread)
# target_link_libraries(${PROJECT_NAME} -lpthread)

