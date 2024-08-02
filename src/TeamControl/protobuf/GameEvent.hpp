#ifndef GAMEVENT_HPP__
#define GAMEVENT_HPP__

#include <string>

namespace tc {
namespace protobuf {

enum class Type {
    UNKNOWN_GAME_EVENT_TYPE                             = 0,
    BALL_LEFT_FIELD_TOUCH_LINE                          = 6,         
    BALL_LEFT_FIELD_GOAL_LINE                           = 7,         
    AIMLESS_KICK                                        = 11, 
    ATTACKER_TOO_CLOSE_TO_DEFENSE_AREA                  = 19,         
    DEFENDER_IN_DEFENSE_AREA                            = 31,         
    BOUNDARY_CROSSING                                   = 41,         
    KEEPER_HELD_BALL                                    = 13,         
    BOT_DRIBBLED_BALL_TOO_FAR                           = 17, 
    BOT_PUSHED_BOT                                      = 24,         
    BOT_HELD_BALL_DELIBERATELY                          = 26,         
    BOT_TIPPED_OVER                                     = 27,         
    BOT_DROPPED_PARTS                                   = 47, 
    ATTACKER_TOUCHED_BALL_IN_DEFENSE_AREA               = 15,         
    BOT_KICKED_BALL_TOO_FAST                            = 18,         
    BOT_CRASH_UNIQUE                                    = 22,         
    BOT_CRASH_DRAWN                                     = 21, 
    DEFENDER_TOO_CLOSE_TO_KICK_POINT                    = 29,         
    BOT_TOO_FAST_IN_STOP                                = 28,         
    BOT_INTERFERED_PLACEMENT                            = 20,         
    EXCESSIVE_BOT_SUBSTITUTION                          = 48, 
    POSSIBLE_GOAL                                       = 39,         
    GOAL                                                = 8,         
    INVALID_GOAL                                        = 42, 
    ATTACKER_DOUBLE_TOUCHED_BALL                        = 14,         
    PLACEMENT_SUCCEEDED                                 = 5,         
    PENALTY_KICK_FAILED                                 = 43, 
    NO_PROGRESS_IN_GAME                                 = 2,         
    PLACEMENT_FAILED                                    = 3,         
    MULTIPLE_CARDS                                      = 32,         
    MULTIPLE_FOULS                                      = 34,         
    BOT_SUBSTITUTION                                    = 37,         
    TOO_MANY_ROBOTS                                     = 38,         
    CHALLENGE_FLAG                                      = 44,         
    CHALLENGE_FLAG_HANDLED                              = 46,         
    EMERGENCY_STOP                                      = 45, 
    UNSPORTING_BEHAVIOR_MINOR                           = 35,         
    UNSPORTING_BEHAVIOR_MAJOR                           = 36, 
    PREPARED                                            = 1,
    INDIRECT_GOAL                                       = 9,
    CHIPPED_GOAL                                        = 10,
    KICK_TIMEOUT                                        = 12,
    ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA           = 16,
    ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA_SKIPPED   = 40,
    BOT_CRASH_UNIQUE_SKIPPED                            = 23,
    BOT_PUSHED_BOT_SKIPPED                              = 25,
    DEFENDER_IN_DEFENSE_AREA_PARTIALLY                  = 30,
    MULTIPLE_PLACEMENT_FAILURES                         = 33,
};

class GameEvent {
    private:
        std::string id;
        Type type;
        std::string origin;
        uint64_t created_timestamp;
    public:
        GameEvent();
        ~GameEvent();
};

} // namespace protobuf
} // namespace tc
#endif // GAMEVENT_HPP__