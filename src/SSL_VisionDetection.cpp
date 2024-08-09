#include <iostream>

#include "ssl_vision_detection.pb.h"
#include "ssl_vision_wrapper.pb.h"

#include "TeamControl/SSL_Receiver.h"
#include "TeamControl/SSL_Sender.h"

/**
 * for testing purposes
 */
int
main(int argc, char* argv[]) {
    using namespace std;
    SSL_WrapperPacket new_ssl_wrapper_packet;
    grSimVisionReceiver* ssl_grsim_receiver = new grSimVisionReceiver();
    grSimVisionSender* ssl_grsim_sender = new grSimVisionSender();
    
    while(true) {
        uint32_t in_buffer_len = sizeof(char) * 65536;
        // std::cerr << in_buffer_len << "\n";
        void* in_buffer = new char[65536];
        ::memset(in_buffer, 0, sizeof(char[65536]));
        // std::cerr << sizeof(in_buffer) << "\n";
        auto recvbytes = ssl_grsim_receiver->recv(&in_buffer, in_buffer_len);
        if(recvbytes.has_value()) {
            recvbytes.emplace();
            new_ssl_wrapper_packet.ParseFromArray(in_buffer, recvbytes.value());
        }
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
} 