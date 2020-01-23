cmake_minimum_required(VERSION 3.15)
project(Lab_2_convex_hull_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_2_convex_hull_ main.cpp)
target_link_libraries(Lab_2_convex_hull_ -lOpenGL32 -lfreeGLUT -lglu32)