#include <iostream>

#include "ssl_vision_detection.pb.h"
#include "ssl_vision_wrapper.pb.h"

#include "TeamControl/SSL_Receiver.h"

/**
 * for testing purposes
 */
int
main(int argc, char * argv[]) {
    using namespace std;
    SSL_WrapperPacket new_ssl_wrapper_packet;
    auto ssl_grsim_addr = grSimVisionReceiver::get_default_addr();
    grSimVisionReceiver ssl_grsim_receiver(std::get<0>(ssl_grsim_addr), std::get<1>(ssl_grsim_addr));
    while(true) {
        uint32_t in_buffer_size = sizeof(char) * 65536;
        void * in_buffer = new char[65536];
        auto len = ssl_grsim_receiver.recv(&in_buffer, in_buffer_size);
        if(len.has_value()) {
            len.emplace();
            new_ssl_wrapper_packet.ParseFromArray(in_buffer, len.value());
        }
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}   