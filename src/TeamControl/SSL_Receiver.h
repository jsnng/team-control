#ifndef SSL_RECEIVER_H__
#define SSL_RECEIVER_H__

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
        SSLReceiverBase(std::optional<std::string>, std::optional<uint32_t>);
        ~SSLReceiverBase();

        void set_server_addr(std::string, uint32_t);
        void set_socket_options();
        inline virtual std::tuple<std::string, uint32_t> get_default_addr() {
            throw std::bad_function_call();
        };
        inline virtual void listen() {
            throw std::bad_function_call();
        };
        std::optional<std::string> receive_message();

    private:
        struct sockaddr_in server_addr;
        int sockfd = -1;
};

class SSLVisionReceiver : public SSLReceiverBase{
    public:
        SSLVisionReceiver(
            std::optional<std::string> server_ip_addr, 
            std::optional<uint32_t> server_port) :
        SSLReceiverBase(server_ip_addr, server_port) {};
        ~SSLVisionReceiver() = default;
        inline constexpr std::tuple<std::string, uint32_t> 
        get_default_addr() {
            std::string ssl_vision_ip_addr = "224.5.23.2";
            uint32_t ssl_vision_port = 10006;
            return std::make_tuple(ssl_vision_ip_addr, ssl_vision_port);
        }
    private:
};

class SSLAutoRefReceiver : public SSLReceiverBase {
    public:
        SSLAutoRefReceiver(
            std::optional<std::string> server_ip_addr, 
            std::optional<uint32_t> server_port) :
        SSLReceiverBase(server_ip_addr, server_port) {};
        inline constexpr std::tuple<std::string, uint32_t> 
        get_default_addr() {
            std::string ssl_autoref_ip_addr = "224.5.23.1";
            uint32_t ssl_autoref_port = 10003;
            return std::tuple<std::string, uint32_t>(ssl_autoref_ip_addr, ssl_autoref_port);
        }
    private:
};

class grSimVisionReceiver : public SSLReceiverBase {
    
};

#endif //SSL_RECEIVER_H__