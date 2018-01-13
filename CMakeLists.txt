cmake_minimum_required(VERSION 3.8)
project(yuandao)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)

include_directories(src/comps/args)

add_executable(yuandao ${SOURCE_FILES})