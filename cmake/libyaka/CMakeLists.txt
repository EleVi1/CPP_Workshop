cmake_minimum_required(VERSION 3.21.2)
project(cmake)
set(CMAKE_CXX_STANDARD 20) # Project wide C++ standard
add_compile_options(-Wall -Wextra -Werror -pedantic -std=c++20 -Wold-style-cast)

add_library(yaka SHARED src/yaka.cc)

target_include_directories(yaka PUBLIC include)
