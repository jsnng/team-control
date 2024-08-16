#include "World.h"
#include <ranges>
World::World(WorldModel& model) {
    world_model = &model;
}

ball_t::ball_t(SSL_DetectionBall ssl_view) {
    set_confidence(ssl_view.confidence());
    set_area(ssl_view.area());
    set_x(ssl_view.x());
    set_y(ssl_view.y());
    set_z(ssl_view.z());
    set_pixel_x(ssl_view.pixel_x());
    set_pixel_y(ssl_view.pixel_y());
}

robot_t::robot_t(SSL_DetectionRobot ssl_view) {
    set_confidence(ssl_view.confidence());
    set_robot_id(ssl_view.robot_id());
    set_x(ssl_view.x());
    set_y(ssl_view.y());
    set_pixel_x(ssl_view.pixel_x());
    set_pixel_y(ssl_view.pixel_y());
    set_orientation(ssl_view.orientation());
}
frame_t World::get_frame() {
    SSL_DetectionFrame ssl = world_model->get_current_frame();
    frame_t *frame = new frame_t();
    frame->set_camera_id(ssl.camera_id());
    frame->set_frame_number(ssl.frame_number());
    frame->set_t_capture(ssl.frame_number());
    frame->set_t_sent(ssl.t_sent());
    for(const int i : std::ranges::iota_view{0, ssl.balls_size()}) {
        SSL_DetectionBall ssl_detectionball = ssl.balls(i);
        ball_t ball(ssl_detectionball);
        frame->balls_append(ball);
    }
    for(const int i : std::ranges::iota_view(0, ssl.robots_yellow_size())) {
        auto ssl_yellow_robot = ssl.robots_yellow(i);
        robot_t robot(ssl_yellow_robot);
        frame->robots_yellow_append(robot);
    }
    for(const int i : std::ranges::iota_view(0, ssl.robots_blue_size())) {
        auto ssl_blue_robot = ssl.robots_blue(i);
        robot_t robot(ssl_blue_robot);
        frame->robots_blue_append(robot);
    }
    return *frame;
}
std::vector<ball_t> World::get_balls() {
    frame_t current_frame = get_frame();
    return current_frame.get_balls();
}
std::vector<robot_t> World::get_robots_yellow() {
    frame_t current_frame = get_frame();
    return current_frame.get_robots_yellow();
}
std::vector<robot_t> World::get_robots_blue() {
    frame_t current_frame = get_frame();
    return current_frame.get_robots_blue();
}
