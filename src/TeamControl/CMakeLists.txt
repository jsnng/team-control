set (SRCS
    SSL_Receiver.cpp
    World_Model.cpp
    AutoRef.h
)

add_library(ssl_tc_model ${SRCS})
target_include_directories(ssl_tc_model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ssl_tc_model PUBLIC ssl_vision_protobuf)