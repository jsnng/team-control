#include "AutoRef.h"

class StageController {
    public:
    enum Stage {
        NORMAL_FIRST_HALF_PRE,
        NORMAL_FIRST_HALF,
        NORMAL_HALF_TIME,
        NORMAL_SECOND_HALF_PRE,
        NORMAL_SECOND_HALF,
        EXTRA_TIME_BREAK,
        EXTRA_FIRST_HALF_PRE,
        EXTRA_FIRST_HALF,
        EXTRA_HALF_TIME,
        EXTRA_SECOND_HALF_PRE,
        EXTRA_SECOND_HALF,
        PENALTY_SHOOTOUT_BREAK,
        PENALTY_SHOOTOUT,
        POST_GAME,
    };
    void tranition(Stage stage);
    private:
    void normal_first_half_pre();
    void normal_first_half();
    void normal_half_time();
    void normal_second_half_pre();
    void normal_second_half();
    void extra_time_break();
    void extra_first_half_pre();
    void extra_first_half();
    void extra_half_time();
    void extra_second_half_pre();
    void extra_second_half();
    void penalty_shootout_break();
    void penalty_shootout();
    void post_game();
};

class StateController {
    public:
    enum State {
        RUNNING,
        STOPPED,
        HALTED,
    };
    enum Command {
        HALT,
        STOP,
        NORMAL_START,
        FORCE_START,
        PREPARE_KICKOFF_YELLOW,
        PREPARE_KICKOFF_BLUE,
        PREPARE_PENALTY_YELLOW,
        PREPARE_PENALTY_BLUE,
        DIRECT_FREE_YELLOW, 
        DIRECT_FREE_BLUE,
        INDIRECT_FREE_YELLOW,
        INDIRECT_FREE_BLUE,
        TIMEOUT_YELLOW,
        TIMEOUT_BLUE,
        GOAL_YELLOW,
        GOAL_BLUE,
        BALL_PLACEMENT_YELLOW,
        BALL_PLACEMENT_BLUE,
        UNKNOWN_COMMAND,
    };
    void transiton(Command command);
    void halt();
    void stop();
    template <StageController::Stage T>
    void run();
    private:
    State current_state;
    void prepare_kickoff_yellow();
    void prepare_kickoff_blue();
    void normal_start();
    void force_start();
    void prepare_penalty_yellow();
    void prepare_penatly_blue();
    void direct_free_yellow();
    void direct_free_blue();
    void indirect_free_yellow();
    void indirect_free_blue();
    void timeout_yellow();
    void timeout_blue();
    void goal_yellow();
    void goal_blue();
    void ball_placement_yellow();
    void ball_placement_blue();
    void unknown_command();
};