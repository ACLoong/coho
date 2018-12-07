cmake_minimum_required(VERSION 3.8)
project(yuandao)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/submitter/main.cc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(yuandao ${SOURCE_FILES})