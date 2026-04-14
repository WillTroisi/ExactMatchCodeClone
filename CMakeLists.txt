cmake_minimum_required(VERSION 3.15)
project(ExactMatchCodeClone)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/main.cpp
)

set(HEADERS
    include/src/detector.hpp
    include/src/parser.hpp
    include/src/normalize.hpp
)
add_executable(detector src/main.cpp)

target_include_directories(detector PRIVATE include/src)