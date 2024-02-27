cmake_minimum_required(VERSION 3.21.2)
project(cmake)
set(CMAKE_CXX_STANDARD 20) # Project wide C++ standard
add_compile_options(-Wall -Wextra -Werror -pedantic -std=c++20 -Wold-style-cast)

# Output directories
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_subdirectory(libyaka)

add_executable(hello_yaka src/main.cc)
target_link_libraries(hello_yaka yaka)
