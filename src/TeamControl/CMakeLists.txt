set (SRCS
    # AutoRef.cpp
    SSL_Receiver.cpp
    World_Model.cpp
)

add_library(tc ${SRCS})
target_link_libraries(tc PUBLIC protobuf)