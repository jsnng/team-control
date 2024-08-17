set (SRCS
    # AutoRef.cpp
    SSL_Receiver.cpp
    World_Model.cpp
)

add_library(ssl_world_model ${SRCS})
target_link_libraries(ssl_world_model PUBLIC ssl_vision_protobuf)