#ifndef STATE_H_
#define STATE_H_

class Stage {
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

class State {
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

    private:
    template <Team T>
    void halt();
    template <Team T>
    void stop();
    template <Team T>
    void normal_start();
    template <Team T>
    void force_start();
    template <Team T>
    void prepare_kickoff_yellow();
    template <Team T>
    void prepare_kickoff_blue();
    template <Team T>
    void prepare_penalty_yellow();
    template <Team T>
    void prepare_penalty_blue();
    template <Team T>
    void direct_free_yellow();
    template <Team T>
    void direct_free_blue();
    template <Team T>
    void indirect_free_yellow();
    template <Team T>
    void indirect_free_blue();
    template <Team T>
    void timeout_yellow();
    template <Team T>
    void timeout_blue();
    template <Team T>
    void goal_yellow();
    template <Team T>
    void goal_blue();
    template <Team T>
    void ball_placement_yellow();
    template <Team T>
    void ball_placement_blue();
    template <Team T>
    void running();
};
#endif // STATE_H_