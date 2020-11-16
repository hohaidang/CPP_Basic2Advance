cmake_minimum_required(VERSION 3.0.2)
project(myproj VERSION 1.0)

add_subdirectory(glog) 

add_executable(myapp main.cpp)
target_link_libraries(myapp glog::glog)

