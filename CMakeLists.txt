cmake_minimum_required(VERSION 3.13)
project(sentencepiece_proxy CXX)
add_compile_options(-std=c++17)
include_directories(~/sentencepiece/src)
link_directories(/usr/local/lib)
add_library(sentencepiece_proxy SHARED sentencepiece_proxy.cpp)
target_link_libraries(sentencepiece_proxy sentencepiece)