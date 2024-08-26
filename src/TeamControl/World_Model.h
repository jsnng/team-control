#ifndef WORLD_MODEL_H_
#define WORLD_MODEL_H_

#include "ssl_vision_wrapper.pb.h"
#include "ssl_vision_detection.pb.h"

#include <deque>
#include <functional>

class WorldModel {
    public:
    WorldModel() =default;
    ~WorldModel() =default;
    /**
     * converts a raw input string from ssl-vision into a SSL_WrapperPacket
     * and stores it in `detection` if it is a `SSL_DetectionFrame` object or
     * `geometry` if it is a `SSL_GeometryData` object.
     * 
     * @param packet raw input string from ssl-vision
     */
    void from_protobuf(const std::string packet);
    /**
     * get last recieved `SSL_DetectionFrame` object in WorldModel.
     * @exception runtime_error if there are 0 `SSL_DetectionFrame` objects.
     */
    SSL_DetectionFrame get_current_frame();
    /**
     * get last recieved frame's `balls` list.
     * i.e., all the balls detected in the frame.
     * 
     * @returns std::vector<SSL_DetectionBall> a vector of SSL_DetectionBall objects.
     */
    std::vector<SSL_DetectionBall> get_balls();
    /**
     * get last recieved frame's `robots_yellow` list in WorldModel.
     * i.e., all the robots detected in the frame that belong to the yellow team
     * 
     * @returns std::vector<SSL_DetectionRobot> a vector of SSL_DetectionRobot objects.
     */
    std::vector<SSL_DetectionRobot> get_robots_yellow();
    /**
     * get last recieved frame's `robots_blue` list in WorldModel.
     * i.e., all the robots detected in the frame that belong to the blue team
     * 
     * @returns std::vector<SSL_DetectionRobot> a vector of SSL_DetectionRobot objects.
     */
    std::vector<SSL_DetectionRobot> get_robots_blue();
    /**
     * get all recieved frames in WorldModel.
     * @returns deque<SSL_DetectionFrame> deque of all recieved SSL_DetectionFrame.
     */
    std::deque<SSL_DetectionFrame> get_frames();
    private:
    std::deque<SSL_DetectionFrame> detection; // doubly linked list for storing detection frames
    SSL_GeometryData geometry; // current geometry data
    SSL_WrapperPacket ssl_wrapperpacket; // temporary SSL_WrapperPacket for reading
    friend class Model;
};

#endif // WORLD_MODEL_H_