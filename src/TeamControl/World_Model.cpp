#include "World_Model.h"
#include "SSL_Receiver.h"

#include <iostream>

WorldModel::WorldModel() {
    ssl_vision_detection_frames = new std::forward_list<SSL_DetectionFrame>();
    ssl_vision_geometry_data = new SSL_GeometryData();
}