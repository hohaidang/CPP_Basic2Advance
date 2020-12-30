cmake_minimum_required(VERSION 3.10)

project (Tutorial)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(MathFunctions)

add_executable(Tutorial tutorial.cpp) # file to execute

target_link_libraries(Tutorial PUBLIC MathFunctions)

target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )