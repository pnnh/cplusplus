cmake_minimum_required(VERSION 3.28)
project(algorithm_transform)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE on)

add_executable(algorithm_transform main.cpp)

# Find Boost
cmake_policy(SET CMP0167 NEW)
find_package(Boost REQUIRED COMPONENTS filesystem iostreams)
if (Boost_FOUND)
    message(STATUS "Boost found")
    target_include_directories(algorithm_transform PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_directories(algorithm_transform PUBLIC ${Boost_LIBRARY_DIRS})
endif ()