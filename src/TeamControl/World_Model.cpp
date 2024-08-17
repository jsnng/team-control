#include "World_Model.h"
#include "SSL_Receiver.h"

#include <iostream>

void WorldModel::from_protobuf(std::string packet) {
    ssl_wrapperpacket.ParseFromString(packet);

    std::cerr << ssl_wrapperpacket.DebugString() << '\n';

    if(ssl_wrapperpacket.has_detection()) [[likely]] {
        SSL_DetectionFrame* frame = new SSL_DetectionFrame();
        frame->CopyFrom(ssl_wrapperpacket.detection());
        detection.push_front(*frame);
    }
    if(ssl_wrapperpacket.has_geometry()) [[unlikely]] {
        geometry.CopyFrom(ssl_wrapperpacket.geometry());
    }
}

SSL_DetectionFrame WorldModel::get_current_frame() {
    if(detection.empty()) {
        throw std::runtime_error("(deque) WorldModel.detection is empty!");
    }
    return detection.front();
}

std::vector<SSL_DetectionBall> WorldModel::get_balls() {
    SSL_DetectionFrame current_frame = get_current_frame();
    if(current_frame.balls_size() <= 0) {
        return std::vector<SSL_DetectionBall>();
    }
    std::vector<SSL_DetectionBall> balls;
    std::copy(current_frame.balls().begin(), current_frame.balls().end(), std::back_inserter(balls));
    return balls;
}

std::vector<SSL_DetectionRobot> WorldModel::get_robots_yellow() {
    SSL_DetectionFrame current_frame = get_current_frame();
    if(current_frame.robots_yellow_size() <= 0) {
        return std::vector<SSL_DetectionRobot>();
    }
    std::vector<SSL_DetectionRobot> robots_yellow;
    std::copy(current_frame.robots_yellow().begin(), current_frame.robots_yellow().end(), std::back_inserter(robots_yellow));
    return robots_yellow;
}

std::vector<SSL_DetectionRobot> WorldModel::get_robots_blue() {
    SSL_DetectionFrame current_frame = get_current_frame();
    if(current_frame.robots_blue_size() <= 0) {
        return std::vector<SSL_DetectionRobot>();
    }
    std::vector<SSL_DetectionRobot> robots_blue;
    std::copy(current_frame.robots_blue().begin(), current_frame.robots_blue().end(), std::back_inserter(robots_blue));
    return robots_blue;
}

std::deque<SSL_DetectionFrame> WorldModel::get_frames() {
    return detection;
}