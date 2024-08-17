if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

find_package(Protobuf CONFIG REQUIRED)

set (PROTO_FILES
    ssl_gc_common.proto
    ssl_gc_game_event.proto
    ssl_gc_geometry.proto
    ssl_gc_referee_message.proto
    ssl_vision_detection.proto
    ssl_vision_geometry.proto
    ssl_vision_wrapper.proto
)
add_library(ssl_vision_protobuf ${PROTO_FILES})
target_include_directories(ssl_vision_protobuf INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(ssl_vision_protobuf
    PUBLIC
        protobuf::libprotobuf
        protobuf::libprotoc
)
# protobuf_generate_cpp(TARGET protobuf LANGUAGE cpp)
protobuf_generate(TARGET ssl_vision_protobuf)
