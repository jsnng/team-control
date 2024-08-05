#include "SSL_Receiver.h"

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

#if defined(__unix__) || defined(__APPLE__)
#include <fcntl.h>
#endif

SSLReceiverBase::SSLReceiverBase(std::string group_ip_addr, uint32_t port) {
    std::cerr << "ip_addr: " << group_ip_addr << " port: " << port << std::endl;
    set_ssl_addr(group_ip_addr, port);
}

void
SSLReceiverBase::set_ssl_addr(
    std::string group_ip_addr,
    uint32_t port) {
    sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        std::cerr << "Error opening socket. " << std::endl;
        exit(EXIT_FAILURE);
    }

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if(::setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        std::cerr << "Error setting socket SO_RCVTIMEO option." << std::endl;
        exit(EXIT_FAILURE);
    }

    const int opt = 1;
    if(::setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        std::cerr << "Error setting socket SO_REUSEADDR option." << std::endl;
        exit(EXIT_FAILURE);
    }
    if(::setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt)) < 0) {
        std::cerr << "Error setting socket SO_BROADCAST option." << std::endl;
        exit(EXIT_FAILURE);
    }

    ::memset(&ssl_socket_addr, 0, sizeof(ssl_socket_addr));
    ssl_socket_addr.sin_family = AF_INET;
    ssl_socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ssl_socket_addr.sin_port = htons(port);

    if(::bind(sockfd, reinterpret_cast<sockaddr*>(&ssl_socket_addr), sizeof(ssl_socket_addr)) < 0) {
        ::close(sockfd);
        std::cerr << "Error binding to socket: " << std::endl;
        exit(EXIT_FAILURE);
    }
    
    struct ip_mreq group;
    if(::inet_pton(AF_INET, group_ip_addr.c_str(), &(group.imr_multiaddr)) < 0) {
        std::cerr << "Error: group_ip_addr invalid." << std::endl;
        exit(EXIT_FAILURE);
    }
    group.imr_interface.s_addr = INADDR_ANY;
    if(::setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group, sizeof(group)) < 0) {
        std::cerr << "Error setting socket to IP_ADD_MEMBERSHIP option." << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::string
SSLReceiverBase::receive_message() {
    char buffer[SSL_RECV_MAX_BUFFER_SIZE];
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);

    ssize_t recv_bytes = recvfrom(sockfd, buffer, SSL_RECV_MAX_BUFFER_SIZE, 0, reinterpret_cast<sockaddr*>(&from_addr), &from_len);
    std::cerr << recv_bytes << std::endl;
    if(recv_bytes > SSL_RECV_MAX_BUFFER_SIZE) {
        std::cerr << "Received packet too large";
        return "";
    }
    if(recv_bytes > 0) {
        buffer[recv_bytes] = '\0';
        return std::string(buffer);
    } 
    else if(errno != EAGAIN) {
        std::cerr << "No message received. Error: " << strerror(errno) << std::endl;
    }
    return "";
}

SSLReceiverBase::~SSLReceiverBase() {
    if(sockfd == -1) {
        std::cerr << "sockfd is invalid" << std::endl;
        return;
    }
    ::shutdown(sockfd, SHUT_RDWR);
    ::close(sockfd);
}

int
main(int argc, char * argv[]) {
    // auto ssl_autoref_addr = SSLAutoRefReceiver::get_default_addr();
    // SSLAutoRefReceiver ssl_autoref_recv(std::get<0>(ssl_autoref_addr), std::get<1>(ssl_autoref_addr));

    auto ssl_grsim_addr = grSimVisionReceiver::get_default_addr();
    grSimVisionReceiver ssl_grsim_recv(std::get<0>(ssl_grsim_addr), std::get<1>(ssl_grsim_addr));
    while(true) {
        auto message = ssl_grsim_recv.receive_message();
        std::cerr << message << std::endl;
    }


    return EXIT_SUCCESS;
}