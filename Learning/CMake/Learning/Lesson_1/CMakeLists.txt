cmake_minimum_required(VERSION 3.0.0)

project(Caculator_Project)

# add_libary, dung de tao library cho add, division va print_result
add_library(my_math
	    addition.cpp
	    division.cpp)

add_library(my_print
     	    print_result.cpp)

add_executable(caculator
		main.cpp)

# dung de link library my_math va my_print
target_link_libraries(caculator my_math my_print)
