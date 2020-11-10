cmake_minimum_required(VERSION 2.8)

cmake_policy(SET CMP0048 NEW) # pass policy of cmake
# set project name
project(Tutorial VERSION 1.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Turn ON compiler switch for using mathlibrary
option(USE_MATHLIB "USING MATHLIB" ON)

# generate TutorialConfig.hpp for compiler switch
configure_file(TutorialConfig.hpp.in TutorialConfig.hpp)

# add the math library, name should be the same as name of folder
# MathLib will be built as a dynamic library .a
if(USE_MATHLIB)
    add_subdirectory(MathLib)
    list(APPEND EXTRA_LIBS MathLib)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathLib")
endif()


# configure_file(source.hpp)
# cmake will automatically find the compiler and build the source.cpp
# add the executable
add_executable(Tutorial main.cpp)

# link to mathlib
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})


# Binary tree to search for include files 
# this one will find all of the header file, in binay out directory
target_include_directories(Tutorial PUBLIC 
                           "${PROJECT_SOURCE_DIR}"
                            ${EXTRA_INCLUDES}
                          )