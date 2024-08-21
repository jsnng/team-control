#include <iostream>

#include "TeamControl/AutoRef.h"
#include "TeamControl/SSL_Receiver.h"

/**
 * for testing purposes
 */
int
main(int argc, char * argv[]) {
    using namespace std;
    SSLAutoRefReceiver ssl_gc_receiver;
    AutoRef* ssl_gc_autoref = new AutoRef();
    for (;;) {
        auto packet = ssl_gc_receiver.receive_ssl_vision();
        if(packet.has_value()) {
            ssl_gc_autoref->from_protobuf(packet.value());
        }
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}   