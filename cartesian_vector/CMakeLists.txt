cmake_minimum_required(VERSION 3.26)
project(cartesian_vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cartesian_vector
        format_numerical_data.cc
        formatted_vector.cc
        state_saver.cc
        vector.cc
        vector_test.cc)
