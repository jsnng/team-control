#include "SSL_Common.h"

using namespace ssl::protobuf;

std::string 
to_string(const Team& t) noexcept {
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc++11-extensions"
    switch(t) {
        case Team::Yellow: return "YELLOW";
        case Team::Blue: return "BLUE";
        case Team::Unknown:
        default: return "UNKNOWN";
    };
    #pragma clang diagnostic pop
}

std::string 
to_string(const Division& t) noexcept {
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc++11-extensions"
    switch(t) {
        case Division::DivA: return "DIV_A";
        case Division::DivB: return "DIV_B";
        case Division::DivUnknown:
        default: return "DIV_UNKNOWN";
    };
    #pragma clang diagnostic pop
}

