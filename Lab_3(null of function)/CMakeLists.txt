cmake_minimum_required(VERSION 3.15)
project(Lab_3_null_of_function_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_3_null_of_function_ main.cpp)
target_link_libraries(Lab_3_null_of_function_ -lOpenGL32 -lfreeGLUT -lglu32)