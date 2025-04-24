cmake_minimum_required(VERSION 3.10)
project(SortBenchmark)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_package(Threads REQUIRED)

add_executable(benchmark_runner src/benchmark_runner.cpp src/sort_algorithms.cpp)

target_link_libraries(benchmark_runner Threads::Threads)
