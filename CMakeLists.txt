cmake_minimum_required(VERSION 3.15)
project(ExactMatchCodeClone)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(detector
    src/main.cpp
)

target_include_directories(detector PRIVATE src)