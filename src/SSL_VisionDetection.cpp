#include <iostream>

#include "TeamControl/SSL_Receiver.h"
#include "TeamControl/World_Model.h"

/**
 * for testing purposes
 */
int
main(int argc, char * argv[]) {
    using namespace std;
    grSimVisionReceiver ssl_grsim_receiver;
    WorldModel* world = new WorldModel();
    while(true) {
        auto packet = ssl_grsim_receiver.receive_ssl_vision();
        if(packet.has_value()) {
            world->from_ssl(packet.value());
        }
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}   