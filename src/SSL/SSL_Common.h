#ifndef SSL_COMMON_H_
#define SSL_COMMON_H_

#include <vector>
#include <cassert>

namespace ssl {
namespace protobuf {

enum class Team : int {
    Unknown = 0,
    Yellow  = 1,
    Blue    = 2
};

enum class Division : int {
    DivUnknown = 0,
    DivA       = 1,
    DivB       = 2
};

struct RobotId {
    uint32_t    id;
    Team        Team;
};

std::string to_string(const Team&) noexcept;
std::string to_string(const Division&) noexcept;

} // protobuf
} // tc
#endif // SSL_COMMON_H_