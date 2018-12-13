cmake_minimum_required(VERSION 3.8)
project(coho)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(SUBMITTER_FILES src/submitter/main.cc)
set(GLOBAL_PROCESSER_FILES src/global_processer/main.cc)
set(WORKER_FILES src/worker/main.cc)

add_executable(global_processer ${GLOBAL_PROCESSER_FILES})
include_directories(build/thirdparty/handy/include)
link_directories(build/thirdparty/handy/lib)
target_link_libraries(global_processer libhandy.a)

add_executable(submitter ${SUBMITTER_FILES})
add_executable(worker ${WORKER_FILES})
