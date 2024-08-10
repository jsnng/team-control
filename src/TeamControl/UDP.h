#ifndef UDP_H_
#define UDP_H_

#include <string>
#include <vector>
#include <optional>
#include <tuple>
#include <functional>
#include <netdb.h>

#include <netinet/in.h>

class UDP {
   public:
        UDP()=default;
        ~UDP();
        /**
         * listens to multicast on socket at descriptor `sockfd`
         * 
         * @param buffer allocated memory to store packets
         * @param length size of allocated memory
         * 
         * @returns int sizeof bits recievedfrom `sockfd` or std::nullopt
         * 
         */
        std::optional<int> recv(void* buffer, int length) const;
        /**
         * send a packet
         * 
         * @param out_buffer data to send to out_addr
         * @param out_addr destination of data to be sent
         * 
         */
        void send(const void * out_buffer, const sockaddr_in* out_addr);
        /**
         * sets the socket timeout option
         * 
         * @param in_seconds timeout time in seconds
         * @param in_microseconds timeout time in microseconds
         * @note setting `in_seconds` and `in_microseconds` to 0 results in no timeout
         * 
         * @returns true if socket timeout option are applied correctly
         * @throws runtime_error if socket timeout options fail to apply
         */
        bool set_sock_timeout(const uint32_t in_seconds, const uint32_t in_microseconds);
        /**
         * sets up a socket
         * 
         * @returns true if socket is set up successfully
         * @throws runtime_error if socket setup fails
         * 
         */
        bool open_multicast_socket();
        /**
         * set up parameter `addr`
         * @param ip_addr ip addr of listener/sender
         * @param port port for listening/sending
         */
        bool set_sockaddr_in(std::string ip_addr, uint32_t port);
        bool set_sockaddr_in(char* ip_addr, uint32_t port);
        bool set_sockaddr_in(in_addr_t ip_addr, uint32_t port);
        inline void bind_mutlicast_socket() {
            ::bind(sockfd, reinterpret_cast<sockaddr*>(&addr), sizeof(sockaddr_in));
        }
        /**
         * joins specified mutlicast group
         * 
         * @param group_ip_addr ip address of the group
         * 
         * @return true if joining is successful.
         * @throws runtime_error if the join is unsuccessfu.
         */
        bool join_mutlicast_group(const std::string group_ip_addr);
    private:
        struct sockaddr_in addr; // for handling internet addresses
        int sockfd = -1; // file descriptor that socket() returned
};
#endif