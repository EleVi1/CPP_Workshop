add_library(yaka SHARED src/yaka.cc)

target_include_directories(libyaka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(libyaka PROPERTIES libyaka.so yaka)

