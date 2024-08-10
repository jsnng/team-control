#ifndef SSL_RECEIVER_H_
#define SSL_RECEIVER_H_

#include <string>
#include <vector>
#include <optional>
#include <tuple>
#include <functional>
#include <netdb.h>

#include <netinet/in.h>

#define SSL_RECV_BUFFER_SIZE 2048

/**
 * base multicast receiver for ssl
 */
class SSLReceiverBase {
    public:
        /**
         * SSLReceieverBase constructor
         * 
         * @param group_ip_addr mutlicast group ip addr
         * @param port mutlicast group port
         * @throws runtime_error @see SSLReceiverBase::set_ssl_multicast_socket()
         * 
         */
        SSLReceiverBase(std::string const ip_addr, const std::string group_addr, const uint32_t port);
        ~SSLReceiverBase();
        /**
         * listens to multicast on socket at descriptor `sockfd`
         * 
         * @see `SSL_RECV_BUFFER_SIZE` maximum size of recv buffer
         * @returns std::optional<std::string> recieved messages from `sockfd` or std::nullopt
         * 
         */
        std::optional<std::string> receive_ssl_vision();
        /**
         * sets the socket timeout option
         * 
         * @param in_seconds timeout time in seconds
         * @param in_microseconds timeout time in microseconds
         * @note setting `in_seconds` and `in_microseconds` to 0 results in no timeout
         * 
         * @throws runtime_error if socket timeout options fail to apply
         */
        void set_sock_timeout(const uint32_t in_seconds, const uint32_t in_microseconds);
        /**
         * sets up a socket to for listening to the mutlicast group
         * 
         * @param group_ip_addr mutlicast group ip addr
         * @param port mutlicast group port
         * 
         * @throws runtime_error if socket setup fails
         * 
         * @todo change `group.imr_interface.s_addr` to `group_ip_addr` instead of `INADDR_ANY`
         */
        void ssl_multicast_socket(const std::string ip_addr, const std::string group_addr, const uint32_t port);
        void set_ssl_sock_addr(const uint32_t port);
    protected:
        struct sockaddr_in ssl_socket_addr; // for handling internet addresses
        int sockfd = -1; // file descriptor that socket() returned
};

class SSLVisionReceiver : public SSLReceiverBase {
    public:
        SSLVisionReceiver(const std::string x = "0.0.0.0", const std::string y = "224.5.23.2", 
                const uint32_t z = 10006) : 
            SSLReceiverBase(x, y, z) {};
    private:
};

class SSLAutoRefReceiver : public SSLReceiverBase {
    public:
        SSLAutoRefReceiver(const std::string x = "", const std::string y = "224.5.23.1", 
                const uint32_t z = 10003) : 
            SSLReceiverBase(x, y, z) {};
};

class grSimVisionReceiver : public SSLReceiverBase {
    public:
        grSimVisionReceiver(const std::string x = "0.0.0.0", const std::string y = "224.5.23.2", 
                const uint32_t z = 10020) : 
            SSLReceiverBase(x, y, z) {};
};

#endif //SSL_RECEIVER_H_