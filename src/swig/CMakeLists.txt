find_package(SWIG required)
set_source_files_properties("World_Model.i" properties SWIG_FLAG "-threads")

set(Swig_SRC
    "World.cpp"
)

swig_add_module("world_model" python "World_Model.i" ${Swig_SRC})
set_source_files_properties(${swig_generated_file_fullname} properties compile_flags "-g;-std=c++20")
swig_link_libraries("World_Model" ${PYTHON_LIBRARIES})