#ifndef SSL_DETECTIONFRAME_HPP__
#define SSL_DETECTIONFRAME_HPP__

#include <vector>

namespace tc {
namespace protobuf {
namespace detection {

struct SSL_DetectionBall {
    private:
        float       condidence;
        uint32_t    area;
        float       x;
        float       y;
        float       z;
        float       pixel_x;
        float       pixel_y;
};

struct SSL_DetectionRobot {
    private:
        float       condidence;
        uint32_t    robot_id;
        float       x;
        float       y;
        float       orientation;
        float       pixel_x;
        float       pixel_y;
        float       height;
};

class SSL_DetectionFrame {
    private:
        uint32_t                            frame_number;
        double                              t_capture;
        double                              t_sent;
        uint32_t                            camera_id;
        std::vector<SSL_DetectionBall *>    balls;
        std::vector<SSL_DetectionRobot *>   robots_yellow;
        std::vector<SSL_DetectionRobot *>   robots_blue;
    public:
        SSL_DetectionFrame();
        ~SSL_DetectionFrame();
};

} // detection
} // protobuf
} // tc
#endif // SSL_DETECTIONFRAME_HPP__ 