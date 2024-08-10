#include <iostream>

#include "ssl_vision_detection.pb.h"
#include "ssl_vision_wrapper.pb.h"

#include "TeamControl/SSL_Receiver.h"
#include "TeamControl/World_Model.h"

/**
 * for testing purposes
 */
int
main(int argc, char * argv[]) {
    using namespace std;
    SSL_WrapperPacket new_ssl_wrapper_packet;
    grSimVisionReceiver ssl_grsim_receiver;
    // #pragma omp parallel if (n > limit) default (none) 
    //     shared() private ()
    while(true) {
        auto packet = ssl_grsim_receiver.receive_ssl_vision();
        if(packet.has_value()) {
            // #pragma omp for nowait
            // std::cout << packet.value() << '\n';
            new_ssl_wrapper_packet.ParseFromString(packet.value());

            std::cout << new_ssl_wrapper_packet.DebugString() << '\n';
        }
        // #pragma omp barrier
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}   