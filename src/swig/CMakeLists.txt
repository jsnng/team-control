find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

set(Python3_ROOT_DIR "/opt/homebrew/Cellar/python@3.11/3.11.9_1/Frameworks/Python.framework/Versions/3.11/")
find_package (Python3 COMPONENTS Interpreter Development)
include_directories(${Python3_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_SWIG_FLAGS "")
set_source_files_properties(World.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(World.i PROPERTIES SWIG_FLAG "-includeall")
set_source_files_properties(${swig_generated_file_fullname}
                             PROPERTIES COMPILE_OPTIONS "-lpython;-dynamiclib")
swig_add_library(world_model LANGUAGE python SOURCES World.i World.cpp)
target_link_libraries(world_model PRIVATE ssl_world_model)
target_link_libraries(world_model PRIVATE ssl_vision_protobuf)
target_link_libraries(world_model PRIVATE ${Python3_LIBRARIES})
target_include_directories(world_model PRIVATE ${Python3_INCLUDE_DIRS})
