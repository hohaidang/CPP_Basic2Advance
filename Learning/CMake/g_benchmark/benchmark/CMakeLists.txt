cmake_minimum_required(VERSION 3.5)
project(main)

include(FetchContent)

# Externally provided libraries
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG master) # need master for benchmark::benchmark

FetchContent_MakeAvailable(
        googletest
        googlebenchmark)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_executable(g_benchmark bm_main.cpp)
target_link_libraries(g_benchmark benchmark::benchmark)