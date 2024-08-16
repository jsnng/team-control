#ifndef WORLD_H_
#define WORLD_H_

#include "TeamControl/World_Model.h"

#include <optional>
#include <queue>

/**
* protobuf message `SSL_DetectionFrame`
* @see src/TeamControl/protobuf/ssl_vision_detection.proto
*/
class ball_t {
    public:
    ball_t(SSL_DetectionBall ssl_view);
    ~ball_t()=default;
    constexpr bool operator() (const ball_t& lhs, const ball_t& rhs) const {
        return (lhs.confidence < rhs.confidence);
    };
    inline void set_confidence(const float val) {
        confidence = val;
    }
    inline float get_confidence() {
        return confidence;
    }
    inline std::optional<uint32_t> set_area(const uint32_t val) {
        area = val;
    }
    inline float set_x(const float val) {
        x = val;
    }
    inline float set_y(const float val) {
        y = val;
    }
    inline float set_z(const float val) {
        z = val;
    }
    inline float set_pixel_x(const float val) {
        pixel_x = val;
    }
    inline float set_pixel_y(const float val) {
        pixel_y = val;
    }
    private:
    float                   confidence;
    std::optional<uint32_t> area;
    float                   x;
    float                   y;
    std::optional<float>    z;
    float                   pixel_x;
    float                   pixel_y;
};

class robot_t {
    public:
    robot_t(SSL_DetectionRobot ssl_view);
    ~robot_t();
    constexpr bool operator() (const robot_t& lhs, const robot_t& rhs) const {
        return (lhs.confidence < rhs.confidence);
    };
    inline void set_confidence(const float val) {
        confidence = val;
    }
    inline float get_confidence() {
        return confidence;
    }
    inline std::optional<uint32_t> set_robot_id(uint32_t val) {
        robot_id = val;
    }
    inline float set_x(float val) {
        x = val;
    }
    inline float set_y(const float val) {
        y = val;
    }
    inline float set_orientation(const float val) {
        orientation = val;
    }
    inline float set_pixel_x(const float val) {
        pixel_x = val;
    }
    inline float set_pixel_y(const float val) {
        pixel_y = val;
    }
    inline float set_height(const float val) {
        height = val;
    }
    private:
    float                   confidence;
    std::optional<uint32_t> robot_id;
    float                   x;
    float                   y;
    std::optional<float>    orientation;
    float                   pixel_x;
    float                   pixel_y;
    std::optional<float>    height;
};

class frame_t {
    private:
        uint32_t        frame_number;
        double          t_capture;
        double          t_sent;
        uint32_t        camera_id;
        std::vector<struct ball_t>    balls;
        std::vector<struct robot_t>   robots_yellow;
        std::vector<struct robot_t>   robots_blue;
    public:
        frame_t()=default;
        ~frame_t()=default;

        inline void set_frame_number(const uint32_t x) {
            frame_number = x;
        }
        inline uint32_t get_frame_number() const {
            return frame_number;
        }
        inline void set_t_capture(const double x) {
            t_capture = x;
        }
        inline double get_t_capture() const {
            return t_capture;
        }
        inline void set_t_sent(const double x) {
            t_sent = x;
        }
        inline double get_t_sent() const {
            return t_sent;
        }
        inline void set_camera_id(const uint32_t x) {
            camera_id = x;
        }
        inline uint32_t get_camera_id() {
            return camera_id;
        }
        inline void balls_append(ball_t ball) {
            balls.push_back(ball);
        }
        inline std::vector<ball_t> get_balls() {
            return balls;
        }
        inline void robots_yellow_append(robot_t robot) {
            robots_yellow.push_back(robot);
        }
        inline std::vector<robot_t> get_robots_yellow() {
            return robots_yellow;
        }
        inline void robots_blue_append(robot_t robot) {
            robots_blue.push_back(robot);
        }
        inline std::vector<robot_t> get_robots_blue() {
            return robots_blue;
        }
};

class World {
    public:
    World(WorldModel& world_model);
    ~World()=default;
    frame_t get_frame();
    std::vector<ball_t> get_balls();
    std::vector<robot_t> get_robots_yellow();
    std::vector<robot_t> get_robots_blue();
    private:
    WorldModel * world_model;
};
#endif // WORLD_H_