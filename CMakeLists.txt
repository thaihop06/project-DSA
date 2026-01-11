cmake_minimum_required(VERSION 3.10)
project(BloomFilterDSA)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(bloom
    src/main.cpp
    src/ds/bloom_filter.cpp
    src/app/menu.cpp
)
