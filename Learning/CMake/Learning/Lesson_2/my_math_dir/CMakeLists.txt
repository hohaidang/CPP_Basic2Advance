# add_libary, dung de tao library cho add, division va print_result
add_library(my_math
	src/addition.cpp
	src/division.cpp)

# boi vi file header nam o folder include, khong chung folder voi src files
# co 2 cach
# 1 la include "../include/<file_name>"
# 2 la noi cho CMake biet la header file nam o dau bang lenh target_include_directories
target_include_directories(my_math PUBLIC include)
