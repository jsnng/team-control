#include "SSL_Receiver.h"

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>

#if defined(__unix__) || defined(__APPLE__)
#include <fcntl.h>
#endif

SSLReceiverBase::SSLReceiverBase(std::string group_ip_addr, uint32_t port) {
    std::cerr << "ip_addr: " << group_ip_addr << " port: " << port << std::endl;
    if(!open_ssl_multicast_socket(group_ip_addr, port)) {
        throw std::runtime_error("Error opening socket.");
    }
}

bool
SSLReceiverBase::open_ssl_multicast_socket(
    std::string group_ip_addr,
    uint32_t port) {

    // create a socket, issue ::setsockopt() for timeout/broadcasting
    // and bind it.

    if(sockfd > 0) throw std::runtime_error("Error: socket already in use.");
    sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) throw std::runtime_error("Error opening socket.");

    set_sock_timeout(1, 0);
    const int opt = 1;
    if(::setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(int)) < 0)
        throw std::runtime_error("Error setting socket SO_REUSEADDR option.");
    if(::setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(int)) < 0)
        throw std::runtime_error("Error setting socket SO_BROADCAST option.");

    ::memset(&ssl_socket_addr, 0, sizeof(ssl_socket_addr));
    ssl_socket_addr.sin_family = AF_INET;
    ssl_socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ssl_socket_addr.sin_port = htons(port);

    if(::bind(sockfd, reinterpret_cast<sockaddr*>(&ssl_socket_addr), sizeof(sockaddr_in)) < 0) {
        ::close(sockfd);
        throw std::runtime_error("Error binding to socket: ");
    }
    
    // mutlicast join operation by issuing ::setsockopt().
    // refer to linux socket documentation (see man ip 7) because
    // struct `ip_mreq` has two forms for IP_ADD_MEMBERSHIP.

    struct ip_mreq group;
    if(::inet_pton(AF_INET, group_ip_addr.c_str(), &(group.imr_multiaddr)) < 0) {
        ::close(sockfd);
        throw std::runtime_error( "Error: group_ip_addr invalid.");
    }
    group.imr_interface.s_addr = INADDR_ANY;
    if(::setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group, sizeof(ip_mreq)) < 0) {
        ::close(sockfd);
        throw std::runtime_error("Error setting socket to IP_ADD_MEMBERSHIP option.");
    }
    return true;
}

bool
SSLReceiverBase::set_sock_timeout(uint32_t in_seconds, uint32_t in_microseconds) {
    struct timeval timeout;
    timeout.tv_sec = in_seconds;
    timeout.tv_usec = in_microseconds;
    
    if(::setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeval)) < 0) {
        throw std::runtime_error("Error setting socket SO_RCVTIMEO option.");
    }
    return true;
}

std::optional<std::string>
SSLReceiverBase::receive_message() {
    char buffer[SSL_RECV_BUFFER_SIZE];
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);

    ssize_t recv_bytes = recvfrom(sockfd, buffer, SSL_RECV_BUFFER_SIZE, 0, reinterpret_cast<sockaddr*>(&from_addr), &from_len);
    std::cerr << recv_bytes << std::endl;
    if(recv_bytes > SSL_RECV_BUFFER_SIZE) {
        std::cerr << "Error: Received packet too large" << std::endl;
        return std::nullopt;
    }
    if(recv_bytes > 0) {
        buffer[recv_bytes] = '\0';
        return std::string(buffer);
    }
    #if defined(__APPLE__)
    else if(errno != EAGAIN) {
        std::cerr << "No message received. Error: " << strerror(errno) << std::endl;
        return std::nullopt;
    }
    #endif 
    return std::nullopt;
}

SSLReceiverBase::~SSLReceiverBase() {
    if(sockfd == -1) {
        std::cerr << "Error: `sockfd` is invalid" << std::endl;
        return;
    }
    ::shutdown(sockfd, SHUT_RDWR);
    ::close(sockfd);
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
//         std::cerr << message.value() << std::endl;
//     }
//     return EXIT_SUCCESS;
// }