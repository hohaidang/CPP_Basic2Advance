# add_libary, dung de tao library cho add, division va print_result
add_library(my_math
	src/addition.cpp
	src/division.cpp)

# boi vi file header nam o folder include, khong chung folder voi src files
# co 2 cach
# 1 la include "../include/<file_name>"
# 2 la noi cho CMake biet la header file nam o dau bang lenh target_include_directories
#target_include_directories(my_math PUBLIC include)
target_include_directories(my_math PUBLIC
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)


# install/copy addition.h va division.h vao /usr/local/include/my_math
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/addition.h ${CMAKE_CURRENT_SOURCE_DIR}/include/division.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/my_math)

# install/copy my_math.a to usr/local/lib/my_math
install(TARGETS my_math DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/my_math)

# De cmd find_package() co the tim duoc library, thi ta can phai copy file <lib_name>-config.cmake vao cung 1 ffolder voi lib.a
# muc FILE my_math-config.cmake la de thay doi ten cua file config output thanh my_math-config.cmake
install(EXPORT my_math FILE my_math-config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/my_math)
