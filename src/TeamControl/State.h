#ifndef STATE_H_
#define STATE_H_

class State {
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