#ifndef SSL_REFEREE_H_
#define SSL_REFEREE_H_

#include "ssl_common.h"
#include <string>
#include <cassert>
#include <optional>
#include <vector>

namespace ssl {
namespace protobuf {

/**
 * protobuf message `Referee`
 * @see src/TeamControl/protobuf/ssl_gc_referee_message.proto
 */
class Referee {
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

        enum class MatchType {
            UnknownMatch,
            GroupPhase,
            EliminationPhase,
            Friendly,
        };

        enum class EventType {
            UnknownGameEventType,
            BallLeftFieldTouchLine,         
            BallLeftFieldGoalLine,         
            AimlessKick, 
            AttackerTooCloseToDefenseArea,         
            DefenderInDefenseArea,         
            BoundaryCrossing,         
            KeeperHeldBall,         
            BotDribbledBallTooFar, 
            BotPushedBot,         
            BotHeldBallDeliberately,         
            BotTippedOver,         
            BotDroppedParts, 
            AttackerTouchedBallInDefenseArea,         
            BotKickedBallTooFast,         
            BotCrashUnique,         
            BotCrashDrawn, 
            DefenderTooCloseToKickPoint,         
            BotTooFastInStop,         
            BotInterferedPlacement,         
            ExcessiveBotSubstitution, 
            PossibleGoal,         
            Goal,         
            InvalidGoal, 
            AttackerDoubleTouchedBall,         
            PlacementSucceeded,         
            PenaltyKickFailed, 
            NoProgressInGame,         
            PlacementFailed,         
            MultipleCards,         
            MultipleFouls,         
            BotSubstitution,         
            TooManyRobots,         
            ChallengeFlag,         
            ChallengeFlagHandled,         
            EmergencyStop, 
            UnsportingBehaviorMinor,         
            UnsportingBehaviorMajor, 
            Prepared,
            IndirectGoal,
            ChippedGoal,
            KickTimeout,
            AttackerTouchedOpponentInDefenseArea,
            AttackerTouchedOpponentInDefenseAreaSkipped,
            BotCrashUniqueSkipped,
            BotPushedBotSkipped,
            DefenderInDefenseAreaPartially,
            MultiplePlacementFailures,
        };

        Referee();
        ~Referee();

        std::string to_string(const EventType&) noexcept;
        std::string to_string(const MatchType&);
        std::string to_string(const CommandType&);
        std::string to_string(const StageType&) noexcept;

    private:
        struct Point {
            float x; 
            float y;
        };

        /**
        * protobuf message `GameEvent`
        * @see src/TeamControl/protobuf/ssl_gc_game_event.proto
        */
        struct GameEvent {
            std::optional<std::string> id;
            std::optional<EventType> type;
            std::vector<std::string>* origin;
            std::optional<uint64_t> created_timestamp;
            EventType event;
            std::optional<Team> by_team, kicking_team;
            std::optional<uint64_t> last_touch_by_team;
            std::optional<std::string> reason;
            std::optional<std::string> message;
            std::optional<Point>    location, 
                                    kick_location, 
                                    start, 
                                    end, 
                                    ball_location;
            std::optional<float>    speed, 
                                    distance, 
                                    crash_speed, 
                                    speed_diff, 
                                    crash_angle, 
                                    time,
                                    max_ball_height,
                                    time_taken, 
                                    duration,
                                    precision,
                                    remaining_distance,
                                    nearest_own_bot_distance,
                                    initial_ball_speed,
                                    pushed_distance;
            std::optional<bool>     chipped, 
                                    accepted;
            std::optional<uint32_t> kicking_bot, 
                                    by_bot, 
                                    num_robots_by_team, 
                                    bot_yellow, 
                                    bot_blue, 
                                    violator, 
                                    victim,
                                    num_robots_allowed, 
                                    num_robots_on_field;
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
            std::optional<uint32_t>     foul_counter;
            std::optional<uint32_t>     ball_placement_failures;
            std::optional<bool>         can_place_ball;
            std::optional<uint32_t>     max_allowed_bots;
            std::optional<bool>         bot_substitution_intent;
            std::optional<bool>         ball_placement_failures_reached;
            std::optional<bool>         bot_substitution_allowed;
            std::optional<uint32_t>     bot_substitutions_left;
            std::optional<uint32_t>     bot_substitution_time_left;
        };

        struct GameEventProposalGroup {
            std::string                 id;
            std::vector<GameEvent>*     game_events;
            bool                        accepted;
        };

        std::optional<std::string>              source_identifier;
        std::optional<MatchType>                match_type;
        uint64_t                                packet_timestamp;
        std::optional<StageType>                stage;
        std::optional<int64_t>                  stage_time_left;
        uint32_t                                command_counter;
        uint64_t                                command_timestamp;
        TeamInfo                                yellow;
        TeamInfo                                blue;
        std::optional<Point>                    designated_position;
        std::optional<bool>                     blue_team_on_positive_half;
        std::optional<CommandType>              next_command;
        std::vector<GameEvent>*                 game_events;
        std::vector<GameEventProposalGroup>*    game_event_proposals;
        std::optional<int64_t>                  current_action_time_remaining;
        std::optional<std::string>              status_message;
};

} // namespace protobuf
} // namespace tc
#endif // SSL_REFEREE_H_