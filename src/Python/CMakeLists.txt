find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
set (SRCS
    Model.cpp
)

add_library(py ${SRCS})
target_include_directories(py PRIVATE ${Python3_INCLUDE_DIRS})