#ifndef  MODEL_H_
#define  MODEL_H_

class VirtualStageModel {
    public:
    enum class StageType {
        NormalFirstHalfPre,
        NormalFirstHalf,
        NormalHalfTime,
        NormalSecondHalfPre,
        NormalSecondHalf,
        ExtraTimeBreak,
        ExtraFirstHalfPre,
        ExtraFirstHalf,
        ExtraHalfTime,
        ExtraSecondHalfPre,
        ExtraSecondHalf,
        PenaltyShootoutBreak,
        PenaltyShootout,
        PostGame,
    };

    virtual void get_stage_model();
    virtual void do_normal_first_half_pre();
    virtual void do_normal_first_half();
    virtual void do_normal_half_time();
    virtual void do_normal_second_half_pre();
    virtual void do_normal_second_half();
    virtual void do_extra_time_break();
    virtual void do_extra_first_half_pre();
    virtual void do_extra_first_half();
    virtual void do_extra_half_time();
    virtual void do_extra_second_half_pre();
    virtual void do_extra_second_half();
    virtual void do_penalty_shootout_break();
    virtual void do_penalty_shootout();
    virtual void do_post_game();
};

class ConcreteStageModel : public VirtualStageModel {
    public:
    ConcreteStageModel();
    virtual ~ConcreteStageModel();
    virtual void get_stage_model();
    virtual void do_normal_first_half_pre();
    virtual void do_normal_first_half();
    virtual void do_normal_half_time();
    virtual void do_normal_second_half_pre();
    virtual void do_normal_second_half();
    virtual void do_extra_time_break();
    virtual void do_extra_first_half_pre();
    virtual void do_extra_first_half();
    virtual void do_extra_half_time();
    virtual void do_extra_second_half_pre();
    virtual void do_extra_second_half();
    virtual void do_penalty_shootout_break();
    virtual void do_penalty_shootout();
    virtual void do_post_game();
    private:
    StageType current_stage;

};

class VirtualStateModel {
    public:
    enum class CommandType {
        Halt,
        Stop,
        NormalStart,
        ForceStart,
        PrepareKickoffYellow,
        PrepareKickoffBlue,
        PreparePenaltyYellow,
        PreparePenaltyBlue,
        DirectFreeYellow,
        DirectFreeBlue,
        IndirectFreeYellow,
        IndirectFreeBlue,
        TimeoutYellow,
        TimeoutBlue,
        GoalYellow,
        GoalBlue,
        BallPlacementYellow,
        BallPlacementBlue,
    };

    enum class Team {
        Unknown, 
        Yellow, 
        Blue,
    };

    enum class StateType {
        Running,
        Halted,
        Stopped,
    };

    /**
     * get our "representation" of the game right now
     * 
     */
    virtual void get_state_model();

    /**
     * when "autoplayer" is playing football
     * there are three possible states:
     *      - halted
     *      - stopped
     *      - running
     */
    virtual void do_halted();
    virtual void do_stopped();
    virtual void do_running();

    /**
     * state transition functions
     * trggered by either:
     * autoref OR
     * referee
     * unless its a timeout...
     */
    virtual void do_halt();
    virtual void do_stop();
    virtual void do_normal_start();
    virtual void do_force_start();
    virtual void do_prepare_kickoff_yellow();
    virtual void do_prepare_kickoff_blue();
    virtual void do_prepare_penalty_yellow();
    virtual void do_prepare_penalty_blue();
    virtual void do_direct_free_yellow();
    virtual void do_direct_free_blue();
    virtual void do_indirect_free_yellow();
    virtual void do_indirect_free_blue();
    virtual void do_timeout_yellow();
    virtual void do_timeout_blue();
    virtual void do_goal_yellow();
    virtual void do_goal_blue();
    virtual void do_ball_placement_yellow();
    virtual void do_ball_placement_blue();
};

class ConcreteStageModel : public VirtualStateModel {
    public:
    ConcreteStageModel();
    virtual ~ConcreteStageModel();
    virtual void do_halt();
    virtual void do_stop();
    virtual void do_normal_start();
    virtual void do_force_start();
    virtual void do_prepare_kickoff_yellow();
    virtual void do_prepare_kickoff_blue();
    virtual void do_prepare_penalty_yellow();
    virtual void do_prepare_penalty_blue();
    virtual void do_direct_free_yellow();
    virtual void do_direct_free_blue();
    virtual void do_indirect_free_yellow();
    virtual void do_indirect_free_blue();
    virtual void do_timeout_yellow();
    virtual void do_timeout_blue();
    virtual void do_goal_yellow();
    virtual void do_goal_blue();
    virtual void do_ball_placement_yellow();
    virtual void do_ball_placement_blue();
    private:
    CommandType current_command;
    CommandType previous_command;
    StateType current_state;
    StateType previous_state;
};
#endif // MODEL_H_
