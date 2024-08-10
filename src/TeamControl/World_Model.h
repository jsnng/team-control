#ifndef WORLD_MODEL_H_
#define WORLD_MODEL_H_

#include "ssl_vision_detection.pb.h"
#include "ssl_vision_wrapper.pb.h"
#include <forward_list>

class WorldModel {
    public:
        WorldModel();
        ~WorldModel() = default;
        
    private:
        std::forward_list<SSL_DetectionFrame>* ssl_vision_detection_frames;
        SSL_GeometryData* ssl_vision_geometry_data;
};

#endif // WORLD_MODEL_H_