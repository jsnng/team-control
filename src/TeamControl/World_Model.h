#ifndef WORLD_MODEL_H_
#define WORLD_MODEL_H_

#include <ssl/ssl_detection.h>
#include <ssl/ssl_geometry.h>
#include <forward_list>

namespace ssl_detection = ssl::protobuf::detection;
namespace ssl_geometry = ssl::protobuf::geometry;

class WorldModel {
    public:
        WorldModel();
        ~WorldModel() = default;
    private:
        std::forward_list<ssl_detection::SSL_DetectionFrame>* ssl_vision_detection_frames;
        ssl_geometry::SSL_GeometryData* ssl_vision_geometry_data;
};

#endif // WORLD_MODEL_H_