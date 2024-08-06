#include "World_Model.h"
#include "SSL_Receiver.h"

#include <iostream>

WorldModel::WorldModel() {
    
}

int 
main(int argc, char* argv[]) {
    auto ssl_grsim_addr = grSimVisionReceiver::get_default_addr();
    grSimVisionReceiver ssl_grsim_recv(std::get<0>(ssl_grsim_addr), std::get<1>(ssl_grsim_addr));
    while(true) {
        auto message = ssl_grsim_recv.receive_message();
        std::cerr << message.value() << std::endl;
    }
    return EXIT_SUCCESS;
}