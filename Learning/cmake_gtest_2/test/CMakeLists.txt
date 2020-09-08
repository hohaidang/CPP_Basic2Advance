cmake_minimum_required(VERSION 3.0)

set(This ExampleTests) 

set(Sources
    ExampleTests.cpp
)

add_executable(${This} ${Sources})

# linking with gtest_main of google test
# also link with cmake_gtest outside
target_link_libraries(${This} PUBLIC
    gtest_main
    cmake_gtest
)

add_test(
    NAME ${This}
    COMMAND ${This}
)