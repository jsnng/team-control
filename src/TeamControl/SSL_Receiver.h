#ifndef SSL_RECEIVER_H_
#define SSL_RECEIVER_H_

#include <string>
#include <vector>
#include <optional>
#include <tuple>
#include <functional>
#include <netdb.h>

#include <netinet/in.h>

#define SSL_RECV_MAX_BUFFER_SIZE 2048

class SSLReceiverBase {
    public:
        SSLReceiverBase(std::string, uint32_t);
        ~SSLReceiverBase();

        void set_ssl_addr(std::string, uint32_t);
        // inline virtual std::tuple<std::string, uint32_t> get_default_addr() {
        //     throw std::bad_function_call();
        // };
        // inline virtual void listen() {
        //     throw std::bad_function_call();
        // };
        std::string receive_message();

    private:
        struct sockaddr_in ssl_socket_addr;
        int sockfd = -1;
};

class SSLVisionReceiver : public SSLReceiverBase {
    public:
        SSLVisionReceiver(std::string x, uint32_t y) : 
            SSLReceiverBase(x, y) {};
        ~SSLVisionReceiver() = default;
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
        inline constexpr static std::tuple<std::string, uint32_t> 
        get_default_addr() {
            std::string ssl_grsim_ip_addr = "224.5.23.2";
            uint32_t ssl_grsim_port = 10020;
            return std::make_tuple(ssl_grsim_ip_addr, ssl_grsim_port);
        }
    private:   
};

#endif //SSL_RECEIVER_H_