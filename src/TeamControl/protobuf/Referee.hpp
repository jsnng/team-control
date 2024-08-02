#ifndef REFEREE_HPP__
#define REFEREE_HPP__

#include "GameEvent.hpp"

namespace tc {
namespace protobuf {

struct Point {
    float x; 
    float y;
};

enum class Stage {
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
    PostGame
};

enum class Command {
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

enum class MatchType {
    UnknownMatch,
    GroupPhase,
    EliminationPhase,
    Friendly,
};

struct TeamInfo {
    std::string                 name;
    uint32_t                    score;
    uint32_t                    red_cards;
    uint32_t                    yellow_card_times;
    std::vector<uint32_t>*      yellow_cards;
    uint32_t                    timeouts;
    uint32_t                    timeout_time;
    uint32_t                    goalkeeper;
    uint32_t                    foul_counter;
    uint32_t                    ball_placement_failures;
    bool                        can_place_ball;
    uint32_t                    max_allowed_bots;
    bool                        bot_substitution_intent;
    bool                        ball_placement_failures_reached;
    bool                        bot_substitution_allowed;
    uint32_t                    bot_substitutions_left;
    uint32_t                    bot_substitution_time_left;
};

struct GameEventProposalGroup {
    std::string                 id;
    std::vector<GameEvent>*     game_events;
    bool                        accepted;
};

class Referee {
    public:
        Referee();
        ~Referee();
    private:
        std::string source_identifier;
        MatchType match_type;
        uint64_t packet_timestamp;
        Stage stage;
        int64_t stage_time_left;
        uint32_t command_counter;
        uint64_t command_timestamp;
        TeamInfo yellow;
        TeamInfo Blue;
        Point designated_position;
        bool blue_team_on_positive_half;
        Command next_command;
        std::vector<GameEvent>* game_events;
        std::vector<GameEventProposalGroup>* game_event_proposals;
        int64_t current_action_time_remaining;
        std::string status_message; 
};

} // namespace protobuf
} // namespace tc
#endif // REFEREE_H__