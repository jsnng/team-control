# get_filename_component(protobuf_dir ${CMAKE_CURRENT_LIST_FILE} PATH)

find_package(protobuf CONFIG REQUIRED)

set (PROTO_FILES
    ssl_gc_common.proto
    ssl_gc_game_event.proto
    ssl_gc_geometry.proto
    ssl_gc_referee_message.proto
    ssl_vision_detection.proto
    ssl_vision_geometry.proto
    ssl_vision_wrapper.proto
)
add_library(protobuf ${PROTO_FILES})
target_include_directories(protobuf INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(protobuf
    PUBLIC
        protobuf::libprotobuf
        protobuf::libprotoc
)
# protobuf_generate_cpp(TARGET protobuf LANGUAGE cpp)
protobuf_generate(TARGET protobuf)
