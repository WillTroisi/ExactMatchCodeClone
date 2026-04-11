cmake_minimum_required(VERSION 3.15)
project(ExactMatchCodeClone)
set(CMAKE_CXX_STANDARD 20)

find_library(FAISS_LIB faiss HINTS /opt/homebrew/lib)
find_path(FAISS_HEAD faiss/IndexFlat.h HINTS /opt/homebrew/include)

add_executable(detector src/main.cpp)

target_include_directories(detector PRIVATE
    ${FAISS_HEAD}
    third_party/
    src/
)

target_link_libraries(detector PRIVATE 
    ${FAISS_LIB}
)