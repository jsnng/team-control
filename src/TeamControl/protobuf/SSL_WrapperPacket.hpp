#ifndef SSL_WRAPPERPACKET_HPP
#define SSL_WRAPPERPACKET_HPP

#include "SSL_GeometryData.hpp"
#include "SSL_DetectionFrame.hpp"

namespace tc {
namespace protobuf {

class SSL_WrapperPacket {
    private:
        detection::SSL_DetectionFrame*  detection;
        geometry::SSL_GeometryData*     geometry;
    public:
        SSL_WrapperPacket();
        ~SSL_WrapperPacket();
};

} // namespace protobuf
} // namespace tc
#endif // SSL_WRAPPERPACKET_HPP__ 