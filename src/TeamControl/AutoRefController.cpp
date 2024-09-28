#include "AutoRefController.h"

void StateController::prepare_kickoff_yellow() {
}
void StateController::prepare_kickoff_blue() {
}
void StateController::normal_start() {
}
void StateController::force_start() {
}
void StateController::prepare_penalty_yellow() {
}
void StateController::prepare_penatly_blue() {
}
void StateController::direct_free_yellow() {
}
void StateController::direct_free_blue() {
}
void StateController::indirect_free_yellow() {
}
void StateController::indirect_free_blue() {
}
void StateController::timeout_yellow() {
}
void StateController::timeout_blue() {
}
void StateController::goal_yellow() {
}
void StateController::goal_blue() {
}
void StateController::ball_placement_yellow() {
}
void StateController::ball_placement_blue() {
}
void StateController::unknown_command() {
}
void StateController::transiton(Command command) {
    switch(command) {
        case STOP:
            current_state = STOPPED;
            stop();
        break;
        case NORMAL_START:
            current_state = RUNNING;
            normal_start();
        break;
        case FORCE_START: 
            current_state = RUNNING;
            force_start();
        break;
        case PREPARE_KICKOFF_YELLOW:
            current_state = STOPPED;
            prepare_kickoff_yellow();
        break;
        case PREPARE_KICKOFF_BLUE:
            current_state = STOPPED;
            prepare_kickoff_blue();
        break;
        case PREPARE_PENALTY_YELLOW:
            current_state = STOPPED;
            prepare_penalty_yellow();
        break;
        case PREPARE_PENALTY_BLUE:
            current_state = STOPPED;
            prepare_penatly_blue();
        break;
        case DIRECT_FREE_YELLOW:
            current_state = STOPPED;
            direct_free_yellow();
        break;
        case DIRECT_FREE_BLUE:
            current_state = STOPPED;
            direct_free_blue();
        break;
        case INDIRECT_FREE_YELLOW:
            current_state = STOPPED;
            indirect_free_yellow();
        break;
        case INDIRECT_FREE_BLUE:
            current_state = STOPPED;
            indirect_free_blue();
        break;
        case TIMEOUT_YELLOW:
            current_state = HALTED;
            timeout_yellow();
        break;
        case TIMEOUT_BLUE:
            current_state = HALTED;
            timeout_blue();
        break;
        case GOAL_YELLOW:
            current_state = HALTED;
            goal_yellow();
        break;
        case GOAL_BLUE:
            current_state = HALTED;
            goal_blue();
        break;
        case BALL_PLACEMENT_YELLOW:
            current_state = STOPPED;
            ball_placement_yellow();
        break;
        case BALL_PLACEMENT_BLUE:
            current_state = STOPPED;
            ball_placement_blue();
        break;
        case UNKNOWN_COMMAND:
        default:
        break;
    }
}

void StageController::normal_first_half_pre() {
}
void StageController::normal_first_half() {  
}
void StageController::normal_half_time() {
}
void StageController::normal_second_half_pre() {
}
void StageController::normal_second_half() {
}
void StageController::extra_time_break() {
}
void StageController::extra_first_half_pre() {
}
void StageController::extra_first_half() {
}
void StageController::extra_half_time() {  
}
void StageController::extra_second_half_pre() {  
}
void StageController::extra_second_half() {  
}
void StageController::penalty_shootout_break() {
}
void StageController::penalty_shootout() {
}
void StageController::post_game() {  
}
void StageController::tranition(Stage stage) {
    switch(stage) {
        case NORMAL_FIRST_HALF_PRE:
            normal_first_half_pre();
        break;
        case NORMAL_FIRST_HALF:
            normal_first_half();
        break;
        case NORMAL_HALF_TIME:
            normal_half_time();
        break;
        case NORMAL_SECOND_HALF_PRE:
            normal_second_half_pre();
        break;
        case NORMAL_SECOND_HALF:
            normal_second_half();
        break;
        case EXTRA_TIME_BREAK:
            extra_time_break();
        break;
        case EXTRA_FIRST_HALF_PRE:
            extra_first_half_pre();
        break;
        case EXTRA_FIRST_HALF:
            extra_first_half();
        break;
        case EXTRA_HALF_TIME:
            extra_half_time();
        break;
        case EXTRA_SECOND_HALF_PRE:
            extra_second_half_pre();
        break;
        case EXTRA_SECOND_HALF:
            extra_second_half();
        break;
        case PENALTY_SHOOTOUT_BREAK:
            penalty_shootout_break();
        break;
        case PENALTY_SHOOTOUT:
            penalty_shootout();
        break;
        case POST_GAME:
            post_game();
        break;
    }
}