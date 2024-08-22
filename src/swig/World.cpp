#include "World.h"
#include <ranges>

ball_t::ball_t(SSL_DetectionBall view) {
    set_confidence(view.confidence());
    set_area(view.area());
    set_x(view.x());
    set_y(view.y());
    set_z(view.z());
    set_pixel_x(view.pixel_x());
    set_pixel_y(view.pixel_y());
}

robot_t::robot_t(SSL_DetectionRobot view) {
    set_confidence(view.confidence());
    set_robot_id(view.robot_id());
    set_x(view.x());
    set_y(view.y());
    set_pixel_x(view.pixel_x());
    set_pixel_y(view.pixel_y());
    set_orientation(view.orientation());
}
Model::Model() {
    auto instance = WorldModelManager();
    auto callback = std::bind(&WorldModel::get_frames, WorldModel());
    frames = instance.init(callback);
}
frame_t 
Model::get_frame() {
    SSL_DetectionFrame detection = frames.front();
    frame_t *frame = new frame_t();
    frame->set_camera_id(detection.camera_id());
    frame->set_frame_number(detection.frame_number());
    frame->set_t_capture(detection.frame_number());
    frame->set_t_sent(detection.t_sent());
    for(const int i : std::ranges::iota_view(0, detection.balls_size())) {
        SSL_DetectionBall ssl_detectionball = detection.balls(i);
        ball_t ball(ssl_detectionball);
        frame->balls_append(ball);
    }
    for(const int i : std::ranges::iota_view(0, detection.robots_yellow_size())) {
        auto ssl_yellow_robot = detection.robots_yellow(i);
        robot_t robot(ssl_yellow_robot);
        frame->robots_yellow_append(robot);
    }
    for(const int i : std::ranges::iota_view(0, detection.robots_blue_size())) {
        auto ssl_blue_robot = detection.robots_blue(i);
        robot_t robot(ssl_blue_robot);
        frame->robots_blue_append(robot);
    }
    return *frame;
}
std::vector<ball_t> 
Model::get_balls() {
    frame_t current_frame = get_frame();
    return current_frame.get_balls();
}
std::vector<robot_t> 
Model::get_robots_yellow() {
    frame_t current_frame = get_frame();
    return current_frame.get_robots_yellow();
}
std::vector<robot_t> 
Model::get_robots_blue() {
    frame_t current_frame = get_frame();
    return current_frame.get_robots_blue();
}
