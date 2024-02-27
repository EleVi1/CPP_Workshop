cmake_minimum_required(VERSION 3.21.2)
project(cmake)

# Output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_subdirectory(libyaka)
add_subdirectory(src)


add_executable(hello_yaka src/main.cc)
target_link_libraries(cmake libyaka)
