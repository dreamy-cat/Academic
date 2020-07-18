project(academic)
cmake_minimum_required(VERSION 2.8)

# Enable to see code generated.
#set(CMAKE_CXX_FLAGS "-Wa,-alh")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "-O0")

set(CMAKE_CXX_FLAGS "-std=c++14")

aux_source_directory(. SRC_LIST)
aux_source_directory(./labs_0x00 SRC_LIST)
aux_source_directory(./labs_0x01 SRC_LIST)
aux_source_directory(./labs_0x02 SRC_LIST)
aux_source_directory(./labs_0x03 SRC_LIST)
aux_source_directory(./labs_0x04 SRC_LIST)
aux_source_directory(./labs_0x05 SRC_LIST)
aux_source_directory(./labs_0x06 SRC_LIST)
aux_source_directory(./labs_0x07 SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

# Some tasks compile and works fine, but mostly just for theory.
add_definitions(-DDANGER_CODE)
# If building to UNIX-like OS, enable some system dependent tasks, not work for Windows.
add_definitions(-DUNIX_DISABLE)

# Change for the other platforms, if needed.
target_link_libraries(${PROJECT_NAME} -lwinpthread)
# target_link_libraries(${PROJECT_NAME} -lpthread)
