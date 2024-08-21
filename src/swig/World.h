#ifndef WORLD_H_
#define WORLD_H_

#include "../TeamControl/World_Model.h"
#include <optional>
#include <vector>

/**
* protobuf message `SSL_DetectionFrame`
* @see src/TeamControl/protobuf/ssl_vision_detection.proto
*/
class ball_t {
    public:
    ball_t(SSL_DetectionBall view);
    ~ball_t() =default;
    constexpr bool operator() (const ball_t& lhs, const ball_t& rhs) const {
        return (lhs.confidence < rhs.confidence);
    };
    inline void set_confidence(const float val) {
        confidence = val;
    }
    inline void set_area(const uint32_t val) {
        area = val;
    }
    inline void set_x(const float val) {
        x = val;
    }
    inline void set_y(const float val) {
        y = val;
    }
    inline void set_z(const float val) {
        z = val;
    }
    inline void set_pixel_x(const float val) {
        pixel_x = val;
    }
    inline void set_pixel_y(const float val) {
        pixel_y = val;
    }
    inline float get_confidence() {
        return confidence;
    }
    inline std::optional<uint32_t> get_area() {
        return area;
    }
    inline float get_x() {
        return x;
    }
    inline float get_y() {
        return y;
    }
    inline std::optional<float> get_z() {
       return z;
    }
    inline float get_pixel_x() {
        return pixel_x;
    }
    inline float get_pixel_y() {
        return pixel_y;
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
    robot_t(SSL_DetectionRobot view);
    ~robot_t() =default;
    constexpr bool operator() (const robot_t& lhs, const robot_t& rhs) const {
        return (lhs.confidence < rhs.confidence);
    };
    inline void set_confidence(const float val) {
        confidence = val;
    }
    inline void set_robot_id(uint32_t val) {
        robot_id = val;
    }
    inline void set_x(float val) {
        x = val;
    }
    inline void set_y(const float val) {
        y = val;
    }
    inline void set_orientation(const float val) {
        orientation = val;
    }
    inline void set_pixel_x(const float val) {
        pixel_x = val;
    }
    inline void set_pixel_y(const float val) {
        pixel_y = val;
    }
    inline void set_height(const float val) {
        height = val;
    }
     inline float get_confidence() {
        return confidence;
    }
    inline uint32_t get_robot_id() {
        return robot_id;
    }
    inline float get_x() {
        return x;
    }
    inline float get_y() {
        return y;
    }
    inline std::optional<float> get_orientation() {
       return orientation;
    }
    inline float get_pixel_x() {
        return pixel_x;
    }
    inline float get_pixel_y() {
        return pixel_y;
    }
    private:
    float                   confidence;
    uint32_t                robot_id;
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

class Model {
    public:
    Model();
    ~Model() =default;
    frame_t get_frame();
    std::vector<ball_t> get_balls();
    std::vector<robot_t> get_robots_yellow();
    std::vector<robot_t> get_robots_blue();
    private:
    std::deque<SSL_DetectionFrame> frames;
};

class WorldModelManager {
    public:
    // std::function<return_type(list_of_argument_types(s))>
    std::deque<SSL_DetectionFrame> init(std::function<std::deque<SSL_DetectionFrame>(void)> func) {
        std::deque<SSL_DetectionFrame> result = func();
        return result;
    }
};
#endif // WORLD_H_