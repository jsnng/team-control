cmake_minimum_required(VERSION 3.30.1)

project(team-control LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
"$<$<COMPILE_LANGUAGE:CXX>:-std=c++20;-g;>"
)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
add_subdirectory(src)