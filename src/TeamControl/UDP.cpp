#include "UDP.h"
#include <sys/socket.h>
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>

#if defined(__unix__) || defined(__APPLE__)
#include <fcntl.h>
#endif

bool
UDP::open_multicast_socket() {

    // create a socket, issue ::setsockopt() for timeout/broadcasting
    // and bind it.
    #ifdef _WIN32
    WSADATA wsaData;
    if(WSASetup(0x0101, &wsaData)) {
        throw std::runtime_error("WSASetup failed.");
        return -1
    }
    #endif

    if(sockfd > 0) throw std::runtime_error("Error: socket already in use.");
    sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) throw std::runtime_error("Error opening socket.");

    set_sock_timeout(1, 0);
    const int opt = 1;
    if(::setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(int)) < 0)
        throw std::runtime_error("Error setting socket SO_REUSEADDR option.");
    if(::setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(int)) < 0)
        throw std::runtime_error("Error setting socket SO_BROADCAST option.");
    return true;
}

bool
UDP::set_sockaddr_in(std::string ip_addr, uint32_t port) {
    ::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_aton(ip_addr.c_str(), &addr.sin_addr);
}

bool
UDP::set_sockaddr_in(char* ip_addr, uint32_t port) {
    ::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_aton(ip_addr, &addr.sin_addr);
}

bool
UDP::set_sockaddr_in(in_addr_t ip_addr, uint32_t port) {
    ::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ip_addr;
    addr.sin_port = htons(port);
}

void 
UDP::send(const void * out_buffer, const sockaddr_in* out_addr) {
    sendto(sockfd, out_buffer, sizeof(out_buffer), 0,
        reinterpret_cast<sockaddr*>(&out_addr), sizeof(out_addr));
}

bool
UDP::join_mutlicast_group(std::string group_ip_addr) {
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
UDP::set_sock_timeout(uint32_t in_seconds, uint32_t in_microseconds) {
    struct timeval timeout;
    timeout.tv_sec = in_seconds;
    timeout.tv_usec = in_microseconds;
    
    if(::setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeval)) < 0) {
        throw std::runtime_error("Error setting socket SO_RCVTIMEO option.");
    }
    return true;
}

std::optional<int>
UDP::recv(void* buffer, int size) const {
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);

    std::cout << sizeof(buffer) << "\n";

    auto recvbytes = recvfrom(sockfd, buffer, size, 0, reinterpret_cast<sockaddr*>(&from_addr), &from_len);
    std::cerr << recvbytes << std::endl;
    if(recvbytes > size) {
        std::cerr << "Error: Received packet too large" << std::endl;
        return std::nullopt;
    }
    if(recvbytes > 0) {
        return recvbytes;
    }
    #if defined(__APPLE__)
    else if( errno != EAGAIN) {
        std::cerr << "No message received. Error: " << strerror(errno) << '\n';
        return std::nullopt;
    }
    #endif 
    return std::nullopt;
}

UDP::~UDP() {
    #ifdef _WIN32
        WSACleanup();
    #endif
    if(sockfd == -1) {
        std::cerr << "Error: `sockfd` is invalid" << '\n';
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
//         std::cerr << message.value() << '\n';
//     }
//     return 0;
// }