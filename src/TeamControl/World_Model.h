#ifndef WORLD_MODEL_H_
#define WORLD_MODEL_H_

#include "ssl_vision_detection.pb.h"
#include "ssl_vision_wrapper.pb.h"
#include <forward_list>

class WorldModel {
    public:
        WorldModel();
        ~WorldModel() = default;
        void from_ssl(std::string packet);
    private:
        std::deque<SSL_DetectionFrame> detection; // doubly linked list for storing detection frames
        SSL_GeometryData geometry; // current geometry data
        SSL_WrapperPacket ssl_wrapperpacket;
};

#endif // WORLD_MODEL_H_