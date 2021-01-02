cmake_minimum_required(VERSION 3.0.0)

project(Caculator_Project)

# add_subdirectory co nghia la trong moi cai subdirectory duoc add se co 1 file CMakeLists.txt rieng
# CMkae se tu vao subdirectory va kiem file CMakeLists.txt
add_subdirectory(my_math_dir)
add_subdirectory(my_print_dir)

add_executable(caculator
		main.cpp)

# dung de link library my_math va my_print
target_link_libraries(caculator my_math my_print)
