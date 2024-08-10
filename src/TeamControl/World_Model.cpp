#include "World_Model.h"
#include "SSL_Receiver.h"

#include <iostream>
#include <deque>

WorldModel::WorldModel() {
    // detection = new std::deque<SSL_DetectionFrame>();
    // geometry = new SSL_GeometryData();
}

void WorldModel::from_ssl(std::string packet) {
    ssl_wrapperpacket.ParseFromString(packet);
    if(ssl_wrapperpacket.has_detection()) [[likely]] {
        SSL_DetectionFrame* frame = new SSL_DetectionFrame();
        frame->CopyFrom(ssl_wrapperpacket.detection());
        detection.push_front(*frame);
    } else if(ssl_wrapperpacket.has_geometry()) {
        geometry.CopyFrom(ssl_wrapperpacket.geometry());
    }
}