#include "ssl_receiver.h"
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

#if defined(__unix__) || defined(__APPLE__)
#include <fcntl.h>
#endif

SSLReceiverBase::SSLReceiverBase(
    std::optional<std::string> server_ip_addr, 
    std::optional<uint32_t> server_port) {
    if(!(server_ip_addr.has_value() || server_port.has_value())) {
        std::tuple<std::string, uint32_t> default_server_addr = get_default_addr();
        server_ip_addr = std::get<0>(default_server_addr);
        server_port = std::get<1>(default_server_addr);
    }
    set_socket_options();
    set_server_addr(server_ip_addr.emplace(), server_port.emplace());
}

void
SSLReceiverBase::set_server_addr(
    std::string server_ip_addr, 
    uint32_t server_port) {
    ::memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    in_addr ia;
    if(1 == ::inet_pton(AF_INET, server_ip_addr.c_str(), &ia)) {
    #ifdef _WIN32
        ::memcpy(&server_addr.sin_addr, &ia, sizeof(in_addr));
    #else 
        server_addr.sin_addr.s_addr = ia.s_addr;
    #endif
    }
     
    const int opt = 1;
    ::setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &opt, sizeof(opt));

    struct addrinfo *result, hints;

    ::memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = server_addr.sin_family;
    hints.ai_socktype = server_addr.sin_family;
    hints.ai_protocol = AI_PASSIVE;

    int gai_err = ::getaddrinfo(server_ip_addr.c_str(), NULL, &hints, &result);
    #ifdef _WIN32
   if(gai_err == EAI_SYSTEM) {
        std::cerr << "Error getaddrinfo failed";
        exit(EXIT_FAILURE);
    }
    #endif
    if (gai_err != 0) {
        std::cerr << "Error getaddrinfo failed";
        exit(EXIT_FAILURE);
    }
    ::freeaddrinfo(result);
}

void
SSLReceiverBase::set_socket_options() {
    sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        std::cerr << "Error opening socket. " << std::endl;
        exit(EXIT_FAILURE);
    }

    // set the socket to non-blocking
    int flags = ::fcntl(sockfd, F_GETFL, 0);
    if(flags == -1) {
        std::cerr << "Error getting socket flags." << std::endl;
        exit(EXIT_FAILURE);
    }
    if(::fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        std::cerr << "Error setting socket to non-blocking mode." << std::endl;
        exit(EXIT_FAILURE);  
    }

    const int opt = 1;
    ::setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    ::setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt));
}

std::optional<std::string> 
SSLReceiverBase::receive_message() {
    char buffer[SSL_RECV_MAX_BUFFER_SIZE];
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);

    ssize_t recv_bytes = ::recvfrom(sockfd, buffer, SSL_RECV_MAX_BUFFER_SIZE, 0, (struct sockaddr *)&from_addr, &from_len);
    if(recv_bytes > SSL_RECV_MAX_BUFFER_SIZE) {
        std::cerr << "recv_bytes exceeded buffer_size";
        return std::nullopt;
    }
    if(recv_bytes > 0) {
        buffer[recv_bytes] = '\0';
        return std::string(buffer);
    } 
    #ifdef _WIN32
    else if(errno!= WSAETIMEOUT && errno != WSAEWOULDBLOCK) {
        std::cerr << "No message received. Error: " << strerror(errno) << std::endl;
    }
    #elif defined(__unix__)
    else if(errno != EWOULDBLOCK && errno != EAGAIN) {
        std::cerr << "No message received. Error: " << strerror(errno) << std::endl;
    }
    #elif defined(__APPLE__)
    else if(errno != EAGAIN) {
        std::cerr << "No message received. Error: " << strerror(errno) << std::endl;
    }
    #endif
    return std::nullopt;
}

SSLReceiverBase::~SSLReceiverBase() {
    if(sockfd == -1) {
        return;
    }
    #ifdef _WIN32
    shutdown(sockfd, 2);
    closesocket(sockfd);
    #else
    ::shutdown(sockfd, SHUT_RDWR);
    ::close(sockfd);
    #endif
    sockfd = -1;
}

int
main(int argc, char * argv[]) {
    return EXIT_SUCCESS;
}