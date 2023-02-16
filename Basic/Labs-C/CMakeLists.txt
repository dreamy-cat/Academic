project(Labs-C)
cmake_minimum_required(VERSION 2.8)

# Enable to see code generated, using GCC.
# set(CMAKE_C_FLAGS "-Wall -Wextra")

# Enable if using MSVC compiler.
set(CMAKE_C_FLAGS "-Od -Wall -wd4710")

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

# Some tasks compile and works fine, but mostly just for theory.
add_definitions(-DDANGER_CODE)
# If building to UNIX-like OS, enable some system dependent tasks, not work for Windows.
add_definitions(-DUNIX_DISABLE)

# Change for the other platforms, if needed.
# target_link_libraries(${PROJECT_NAME} -lwinpthread)
# target_link_libraries(${PROJECT_NAME} -lpthread)
