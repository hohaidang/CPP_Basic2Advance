cmake_minimum_required(VERSION 3.5)
project(main)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

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

# src la noi giu source code de tinh benchmark
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# bm_main is a main function de goi nhung ham trong src de tinh benchmark
add_executable(g_benchmark bm_main.cpp)
target_link_libraries(g_benchmark benchmark::benchmark)


add_executable(adder bm_adder.cpp)
target_link_libraries(adder benchmark::benchmark)