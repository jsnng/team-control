#include "SSL_Receiver.h"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <stdexcept>
#ifdef _WIN32
#include <winsock2.h>
#endif
#if defined(__unix__) || defined(__APPLE__)
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#endif


SSLReceiverBase::SSLReceiverBase(std::string_view ip_addr,  std::string_view group_addr, 
        const uint32_t port) {
    std::cerr << "SSLReceiverBase::SSLReceiverBase was called\n";
    std::cerr << "ip_addr: " << ip_addr << " group_addr: " << group_addr << " port: " << port << "\n";
    ssl_multicast_socket(ip_addr, group_addr, port);
}

void
SSLReceiverBase::ssl_multicast_socket(std::string_view ip_addr, std::string_view group_addr, 
        const uint32_t port) {

    std::cerr << "SSLReceiverBase::ssl_multicast_socket was called\n";
    // create a socket, issue ::setsockopt() for timeout/broadcasting
    // and bind it.

    #ifdef _WIN32
    WSADATA wsaData;
    if(WSASetup(0x0101, &wsaData)) {
        throw std::runtime_error("WSASetup failed.");
        return -1;
    }
    #endif

    sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) throw std::runtime_error("Error opening socket.");

    set_sock_timeout(1, 0);
    const int opt = 1;
    if(::setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(int)) < 0)
        throw std::runtime_error("Error setting socket SO_REUSEADDR option.");
    if(::setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(int)) < 0)
        throw std::runtime_error("Error setting socket SO_BROADCAST option.");
    // if(::setsockopt(sockfd, IPPROTO_IPV4, IP_PKTINFO, &opt, sizeof(int)) < 0)
    //     throw std::runtime_error("Error setting socket IP_PKTINFO option.");

    set_ssl_sock_addr(port);

    if(::connect(sockfd, reinterpret_cast<sockaddr*>(&ssl_socket_addr), sizeof(sockaddr_in)) < 0) {
        throw std::runtime_error("Error: ::connect call failed for socket");
    }
    
    // mutlicast join operation by issuing ::setsockopt().
    // refer to linux socket documentation (see man ip 7) because
    // struct `ip_mreq` has two forms for IP_ADD_MEMBERSHIP.

    struct ip_mreq group;
    if(::inet_pton(AF_INET, std::string(group_addr).c_str(), &(group.imr_multiaddr)) < 0) {
        throw std::runtime_error( "Error: group_ip_addr invalid.");
    }
    group.imr_interface.s_addr = INADDR_ANY;
    if(::setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group, sizeof(ip_mreq)) < 0) {
        throw std::runtime_error("Error setting socket to IP_ADD_MEMBERSHIP option.");
    }
}

void SSLReceiverBase::set_ssl_sock_addr(const uint32_t port) {
    std::cerr << "SSLReceiverBase::set_ssl_sock_addr was called\n";

    // refer to linux ip documentation (see man ip 3)

    ::memset(&ssl_socket_addr, 0, sizeof(ssl_socket_addr));
    ssl_socket_addr.sin_family = AF_INET;
    ssl_socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // inet_pton(AF_INET, ip_addr.c_str(), &(ssl_socket_addr.sin_addr));
    ssl_socket_addr.sin_port = htons(port);
}

void
SSLReceiverBase::set_sock_timeout(const uint32_t in_seconds, 
    const uint32_t in_microseconds) {
    std::cerr << "SSLReceiverBase::set_sock_timeout was called\n";
    struct timeval timeout;
    timeout.tv_sec = in_seconds;
    timeout.tv_usec = in_microseconds;
    
    if(::setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, 
        sizeof(timeval)) < 0) {
        throw std::runtime_error("Error setting socket SO_RCVTIMEO option.");
    }
}

std::optional<std::string>
SSLReceiverBase::receive_ssl_vision() {
    char buffer[SSL_RECV_BUFFER_SIZE];
    ssize_t buf_size = sizeof(char) * SSL_RECV_BUFFER_SIZE;
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);
    ssize_t recv_bytes = recvfrom(sockfd, buffer, buf_size, 0, 
        reinterpret_cast<sockaddr*>(&from_addr), &from_len);
    if(recv_bytes > buf_size) {
        std::cerr << "Error: Received packet too large" << std::endl;
        return std::nullopt;
    }
    if(recv_bytes > 0) [[ likely ]] {
        buffer[recv_bytes] = '\0';
        return std::string(buffer);
    }
    #if defined(__APPLE__)
    else if(errno != EAGAIN) {
        std::cerr << "No message received. Error: " << 
            strerror(errno) << std::endl;
        return std::nullopt;
    }
    #endif 
    return std::nullopt;
}

SSLReceiverBase::~SSLReceiverBase() {
    std::cerr << "SSLReceiverBase::~SSLReceiverBase was called\n";
    if(sockfd == -1) {
        std::cerr << "Error: `sockfd` is invalid" << std::endl;
        return;
    }
    #ifdef _WIN32
        WSACleanup();
    #endif
    ::shutdown(sockfd, SHUT_RDWR);
    ::close(sockfd);
}

/**
 * for testing purposes
 */
// int
// main(int argc, char * argv[]) {
//     auto ssl_grsim_addr = grSimVisionReceiver::get_default_addr();
//     grSimVisionReceiver ssl_grsim_recv(std::get<0>(ssl_grsim_addr), 
//          std::get<1>(ssl_grsim_addr));
//     while(true) {
//         auto message = ssl_grsim_recv.receive_message();
//         std::cerr << message.value() << std::endl;
//     }
//     return EXIT_SUCCESS;
// }