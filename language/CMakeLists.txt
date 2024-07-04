cmake_minimum_required(VERSION 3.28)
project(cpp-language)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 26)

set(CMAKE_VERBOSE_MAKEFILE on)

FILE(GLOB stream_examples RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/stream/*)
FOREACH (child ${stream_examples})
    ADD_SUBDIRECTORY(${child})
ENDFOREACH () 