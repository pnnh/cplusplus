cmake_minimum_required(VERSION 3.28)
project(cpp-language)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 26)

set(CMAKE_VERBOSE_MAKEFILE on)

file(GLOB example_category LIST_DIRECTORIES true RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/examples/*)
foreach(category ${example_category})
    if(NOT IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${category})
        continue()
    endif()
    file(GLOB example_instance LIST_DIRECTORIES true RELATIVE ${CMAKE_SOURCE_DIR}/${category} ${CMAKE_SOURCE_DIR}/${category}/*)
    foreach(instance ${example_instance})
        if(NOT IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${category}/${instance})
            continue()
        endif()
        add_subdirectory(${CMAKE_SOURCE_DIR}/${category}/${instance})
    endforeach ()
endforeach ()

