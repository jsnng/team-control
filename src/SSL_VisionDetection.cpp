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
    // #pragma omp parallel if (n > limit) default (none) \
    //     shared() private ()
    while(true) {
        auto packet = ssl_grsim_receiver.receive_message();
        if(packet.has_value()) {
            // #pragma omp for nowait
            auto input = packet.emplace();
            new_ssl_wrapper_packet.ParseFromString(input);
        }
        // #pragma omp barrier
    }
    google::protobuf::ShutdownProtobufLibrary();
    return EXIT_SUCCESS;
}   