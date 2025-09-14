add_executable(algorithm_transform main.cpp)

find_package(Boost COMPONENTS filesystem iostreams REQUIRED)
if (Boost_FOUND)
    message(STATUS "Boost found")
    target_include_directories(algorithm_transform PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_directories(algorithm_transform PUBLIC ${Boost_LIBRARY_DIRS})
endif ()