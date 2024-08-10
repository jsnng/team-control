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
    // SSLVisionSender* ssl_grsim_sender = new SSLVisionSender();
    
    while(true) {
        uint32_t in_buffer_len = sizeof(byte[65535]);
        byte* in_buffer = new (nothrow)byte[65536];
        if(in_buffer == nullptr) std::cerr << "in_buffer failed\n";
        auto recvbytes = ssl_grsim_receiver->recv(&in_buffer, in_buffer_len);
        // if(recvbytes.has_value()) {
        //     recvbytes.emplace();
        //     new_ssl_wrapper_packet.ParseFromArray(in_buffer, recvbytes.value());
        // }
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
} 