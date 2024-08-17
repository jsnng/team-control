cmake_minimum_required(VERSION 3.28.3)

project(team-control LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
    add_compile_options(
        "$<$<COMPILE_LANGUAGE:CXX>:/DEBUG:FULL;/std:c++20>"
    )
else()
    add_compile_options(
        "$<$<COMPILE_LANGUAGE:CXX>:-std=c++20;-g;>"
    )
endif()
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
add_subdirectory(src)