#ifndef SSL_VISION_WRAPPER_PB2
#define SSL_VISION_WRAPPER_PB2

#include "SSL_GeometryData.hpp"
#include "SSL_DetectionFrame.hpp"

class SSL_WrapperPacket {
    private:
        SSL_DetectionFrame * detection;
        SSL_GeometryData * geometry;
    public:
        SSL_WrapperPacket();
        ~SSL_WrapperPacket();
};

#endif