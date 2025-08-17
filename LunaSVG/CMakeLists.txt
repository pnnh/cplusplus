cmake_minimum_required(VERSION 3.28)
project(LunaSVGExamples)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE on)

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(lunasvg CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE lunasvg::lunasvg)