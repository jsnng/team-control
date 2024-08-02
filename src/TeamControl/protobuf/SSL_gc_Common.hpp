#ifndef SSL_GC_COMMON_HPP__
#define SSL_GC_COMMON_HPP__

#include <vector>

namespace tc {
namespace protobuf {

enum class Team : int {
    UNKNOWN = 0,
    YELLOW  = 1,
    BLUE    = 2
};

enum class Division : int {
    DIV_UNKNOWN = 0,
    DIV_A       = 1,
    DIV_B       = 2
};

struct RobotId {
    uint32_t    id;
    Team        Team;
};

} // protobuf
} // tc
#endif // SSL_GC_COMMON_HPP__