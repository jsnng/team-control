#ifndef SSL_DETECTIONFRAME_H_
#define SSL_DETECTIONFRAME_H_

#include <vector>
#include <optional>

namespace ssl {
namespace protobuf {
namespace detection {

/**
* protobuf message `SSL_DetectionFrame`
* @see src/TeamControl/protobuf/ssl_vision_detection.proto
*/
class SSL_DetectionFrame {
    private:
        struct SSL_DetectionBall {
            float                   condidence;
            std::optional<uint32_t> area;
            float                   x;
            float                   y;
            std::optional<float>    z;
            float                   pixel_x;
            float                   pixel_y;
        };

        struct SSL_DetectionRobot {
            float                   condidence;
            std::optional<uint32_t> robot_id;
            float                   x;
            float                   y;
            std::optional<float>    orientation;
            float                   pixel_x;
            float                   pixel_y;
            std::optional<float>    height;
        };
        
        uint32_t        frame_number;
        double          t_capture;
        double          t_sent;
        uint32_t        camera_id;
        std::vector<struct SSL_DetectionBall*>    balls;
        std::vector<struct SSL_DetectionRobot*>   robots_yellow;
        std::vector<struct SSL_DetectionRobot*>   robots_blue;

    public:
        SSL_DetectionFrame();
        ~SSL_DetectionFrame();
};

} // detection
} // protobuf
} // tc
#endif // SSL_DETECTIONFRAME_H_ 