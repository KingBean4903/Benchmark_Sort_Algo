cmake_minimum_required(VERSION 3.10)
project(SortBenchmark)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(benchmark_runner src/benchmark_runner.cpp src/sort_algorithms.cpp)
