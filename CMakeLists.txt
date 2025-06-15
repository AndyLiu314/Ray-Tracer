cmake_minimum_required(VERSION 3.10.0)
project(Ray-Tracer VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Ray-Tracer main.cpp)
target_include_directories(Ray-Tracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})