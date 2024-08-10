#include "SSL_Sender.h"
#include <iostream>

SSLSenderBase::SSLSenderBase(const std::string group_ip_addr, const uint32_t port) {
    std::cerr << "ip_addr: " << group_ip_addr << " port: " << port << '\n';
    open_multicast_socket();
    set_sockaddr_in(htonl(INADDR_BROADCAST), port);
}