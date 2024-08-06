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
 * base ssl multicast receiver for ssl
 * 
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
        SSLReceiverBase(std::string group_ip_addr, uint32_t port);
        ~SSLReceiverBase();

        /**
         * listens to multicast on socket at descriptor `sockfd`
         * 
         * @see `SSL_RECV_BUFFER_SIZE` maximum size of recv buffer
         * @returns std::optional<std::string> recieved messages from `sockfd` or std::nullopt
         * 
         */
        std::optional<std::string> receive_message();

    private:
        /**
         * sets up a socket to for listening to the mutlicast group
         * 
         * @param group_ip_addr mutlicast group ip addr
         * @param port mutlicast group port
         * 
         * @returns true if socket is set up successfully
         * @throws runtime_error if socket setup fails
         * 
         * @todo change `group.imr_interface.s_addr` to `group_ip_addr` instead of `INADDR_ANY`
         */
        bool set_ssl_multicast_socket(std::string group_ip_addr, uint32_t port);
        struct sockaddr_in ssl_socket_addr;
        int sockfd = -1;
};

class SSLVisionReceiver : public SSLReceiverBase {
    public:
        SSLVisionReceiver(std::string x, uint32_t y) : 
            SSLReceiverBase(x, y) {};
        ~SSLVisionReceiver() = default;
        /**
         * returns the default addr for listening to vision-ssl
         * 
         * @returns tuple<string, uint32_t> a tuple consisting of the group ip addr and port
         */
        inline constexpr static std::tuple<std::string, uint32_t> 
        get_default_addr() {
            std::string ssl_vision_ip_addr = "224.5.23.2";
            uint32_t ssl_vision_port = 10006;
            return std::make_tuple(ssl_vision_ip_addr, ssl_vision_port);
        }
    private:
};

class SSLAutoRefReceiver : public SSLReceiverBase {
    public:
        SSLAutoRefReceiver(std::string x, uint32_t y) : 
            SSLReceiverBase(x, y) {};
        /**
         * returns the default addr for listening to autoref
         * 
         * @returns tuple<string, uint32_t> a tuple consisting of the group ip addr and port
         */
        inline constexpr static std::tuple<std::string, uint32_t> 
        get_default_addr() {
            std::string ssl_autoref_ip_addr = "224.5.23.1";
            uint32_t ssl_autoref_port = 10003;
            return std::make_tuple(ssl_autoref_ip_addr, ssl_autoref_port);
        }
    private:
};

class grSimVisionReceiver : public SSLReceiverBase {
    public:
        grSimVisionReceiver(std::string x, uint32_t y) : 
            SSLReceiverBase(x, y) {};
        /**
         * returns the default addr for listening to grSim mutlicast vision
         * 
         * @returns tuple<string, uint32_t> a tuple consisting of the group ip addr and port
         */
        inline constexpr static std::tuple<std::string, uint32_t> 
        get_default_addr() {
            std::string ssl_grsim_ip_addr = "224.5.23.2";
            uint32_t ssl_grsim_port = 10020;
            return std::make_tuple(ssl_grsim_ip_addr, ssl_grsim_port);
        }
    private:   
};

#endif //SSL_RECEIVER_H_