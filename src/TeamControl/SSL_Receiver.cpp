#include "SSL_Receiver.h"

#include <iostream>

SSLReceiverBase::SSLReceiverBase(std::string group_ip_addr, uint32_t port) {
    std::cerr << "ip_addr: " << group_ip_addr << " port: " << port << '\n';
    open_multicast_socket();
    set_sockaddr_in(htonl(INADDR_ANY), port);
    join_mutlicast_group(group_ip_addr);
    bind_mutlicast_socket();
}

/**
 * for testing purposes
 */
// int
// main(int argc, char * argv[]) {
//     auto ssl_grsim_addr = grSimVisionReceiver::get_default_addr();
//     grSimVisionReceiver ssl_grsim_recv(std::get<0>(ssl_grsim_addr), std::get<1>(ssl_grsim_addr));
//     while(true) {
//         auto message = ssl_grsim_recv.receive_message();
//         std::cerr << message.value() << '\n';
//     }
//     return 0;
// }s