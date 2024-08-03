#include "ssl_referee.h"

using namespace ssl::protobuf;

std::string 
Referee::to_string(const EventType& t) noexcept {
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc++11-extensions"
    switch(t) {
        case EventType::BallLeftFieldTouchLine: return "BALL_LEFT_FIELD_TOUCH_LINE";         
        case EventType::BallLeftFieldGoalLine: return "BALL_LEFT_FIELD_GOAL_LINE";
        case EventType::AimlessKick: return "AIMLESS_KICK";
        case EventType::AttackerTooCloseToDefenseArea: return "ATTACKER_TOO_CLOSE_TO_DEFENSE_AREA";
        case EventType::DefenderInDefenseArea: return "DEFENDER_IN_DEFENSE_AREA";
        case EventType::BoundaryCrossing: return "BOUNDARY_CROSSING";
        case EventType::KeeperHeldBall: return "KEEPER_HELD_BALL";
        case EventType::BotDribbledBallTooFar: return "BOT_DRIBBLED_BALL_TOO_FAR";
        case EventType::BotPushedBot: return "BOT_PUSHED_BOT";
        case EventType::BotHeldBallDeliberately: return "BOT_HELD_BALL_DELIBERATELY";
        case EventType::BotTippedOver: return "BOT_TRIPPED_OVER";
        case EventType::BotDroppedParts: return "BOT_DROPPED_PARTS";
        case EventType::AttackerTouchedBallInDefenseArea: return "ATTACKER_TOUCHED_BALL_IN_DEFENSE_AREA";
        case EventType::BotKickedBallTooFast: return "BOT_KICKED_BALL_TOO_FAR";
        case EventType::BotCrashUnique: return "BOT_CRASH_UNIQUE";
        case EventType::BotCrashDrawn: return "BOT_CRASH_DRAWN";
        case EventType::DefenderTooCloseToKickPoint: return "DEFENDER_TOO_CLOSE_TO_KICK_POINT";
        case EventType::BotTooFastInStop: return "BOT_TOO_FAST_IN_STOP";
        case EventType::BotInterferedPlacement: return "BOT_INTERFERED_PLACEMENT";
        case EventType::ExcessiveBotSubstitution: return "EXCESSIVE_BOT_SUBSTITUTION";
        case EventType::PossibleGoal: return "POSSIBLE_GOAL";
        case EventType::Goal: return "GOAL";
        case EventType::InvalidGoal: return "INVALID_GOAL";
        case EventType::AttackerDoubleTouchedBall: return "ATTACKER_DOUBLE_TOUCHED_BALL";
        case EventType::PlacementSucceeded: return "PLACEMENT_SUCCEEDED";
        case EventType::PenaltyKickFailed: return "PENALTY_KICK_FAILED";
        case EventType::NoProgressInGame: return "NO_PROGRESS_IN_GAME";
        case EventType::PlacementFailed: return "PLACEMENT_FAILED";
        case EventType::MultipleCards: return "MULTIPLE_CARDS";
        case EventType::MultipleFouls: return "MULTIPLE_FOULS";
        case EventType::BotSubstitution: return "BOT_SUBSTITUTION";
        case EventType::TooManyRobots: return "TOO_MANY_ROBOTS";
        case EventType::ChallengeFlag: return "CHALLENGE_FLAG";
        case EventType::ChallengeFlagHandled: return "CHALLENGE_FLAG_HANDLED";
        case EventType::EmergencyStop: return "EMERGENCY_STOP";
        case EventType::UnsportingBehaviorMinor: return "UNSPORTING_BEHAVIOR_MINOR";
        case EventType::UnsportingBehaviorMajor: return "UNSPORTING_BEHAVIOR_MAJOR";
        case EventType::Prepared: return "PREPARED";
        case EventType::IndirectGoal: return "INDIRECT_GOAL";
        case EventType::ChippedGoal: return "CHIPPED_GOAL";
        case EventType::KickTimeout: return "KICK_TIMEOUT";
        case EventType::AttackerTouchedOpponentInDefenseArea: return "ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA";
        case EventType::AttackerTouchedOpponentInDefenseAreaSkipped: return "ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA_SKIPPED";
        case EventType::BotCrashUniqueSkipped: return "BOT_CRASH_UNIQUE_SKIPPED";
        case EventType::BotPushedBotSkipped: return "BOT_PUSHED_BOT_SKIPPED";
        case EventType::DefenderInDefenseAreaPartially: return "DEFENDER_IN_DEFENSE_AREA_PARTIALLY";
        case EventType::MultiplePlacementFailures: return "MULTIPLE_PLACEMENT_FAILURES";
        case EventType::UnknownGameEventType:
        default: return "UNKNOWN_GAME_EVENT_TYPE";
    }
    #pragma clang diagnostic pop
}

std::string 
Referee::to_string(const StageType& t) {
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc++11-extensions"
    switch(t) {
        case StageType::NormalFirstHalfPre: return "NORMAL_FIRST_HALF_PRE";
        case StageType::NormalFirstHalf: return "NORMAL_FIRST_HALF";
        case StageType::NormalHalfTime: return "NORMAL_HALF_TIME";
        case StageType::NormalSecondHalfPre: return "NORMAL_SECOND_HALF_PRE";
        case StageType::NormalSecondHalf: return "NORMAL_SECOND_HALF";
        case StageType::ExtraTimeBreak: return "EXTRA_TIME_BREAK";
        case StageType::ExtraFirstHalfPre: return "EXTRA_FIRST_HALF_PR";
        case StageType::ExtraFirstHalf: return "EXTRA_FIRST_HALF";
        case StageType::ExtraHalfTime: return "EXTRA_HALF_TIME";
        case StageType::ExtraSecondHalfPre: return "EXTRA_SECOND_HALF_PRE";
        case StageType::ExtraSecondHalf: return "EXTRA_SECOND_HALF";
        case StageType::PenaltyShootoutBreak: return "PENALTY_SHOOTOUT_BREAK";
        case StageType::PenaltyShootout: return "PENALTY_SHOOTOUT";
        case StageType::PostGame: return "POST_GAME";
        default: std::throw_with_nested(std::invalid_argument(""));
    }
    #pragma clang diagnostic pop
}

std::string 
Referee::to_string(const CommandType& t) {
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc++11-extensions"
    switch(t){
        case CommandType::Halt: return "HALF";
        case CommandType::Stop: return "STOP";
        case CommandType::NormalStart: return "NORMAL_START";
        case CommandType::ForceStart: return "FORCE_START";
        case CommandType::PrepareKickoffYellow: return "PREPARE_KICKOFF_YELLOW";
        case CommandType::PrepareKickoffBlue: return "PREPARE_KICKOFF_BLUE";
        case CommandType::PreparePenaltyYellow: return "PREPARE_PENALTY_YELLOW";
        case CommandType::PreparePenaltyBlue: return "PREPARE_PENALTY_BLUE";
        case CommandType::DirectFreeYellow: return "DIRECT_FREE_YELLOW";
        case CommandType::DirectFreeBlue: return "DIRECT_FREE_BLUE";
        case CommandType::IndirectFreeYellow: return "INDIRECT_FREE_YELLOW";
        case CommandType::IndirectFreeBlue: return "INDIRECT_FREE_BLUE";
        case CommandType::TimeoutYellow: return "TIMEOUT_YELLOW";
        case CommandType::TimeoutBlue: return "TIMEOUT_BLUE";
        case CommandType::GoalYellow: return "GOAL_YELLOW";
        case CommandType::GoalBlue: return "GOAL_BLUE";
        case CommandType::BallPlacementYellow: return "BALL_PLACEMENT_YELLOW";
        case CommandType::BallPlacementBlue: return "BALL_PLACEMENT_BLUE";
        default: std::throw_with_nested(std::invalid_argument(""));
    }
    #pragma clang diagnostic pop
}

std::string 
Referee::to_string(const MatchType& t) noexcept {
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wc++11-extensions"
    switch(t) {
        case MatchType::GroupPhase: return "GROUP_PHASE";
        case MatchType::EliminationPhase: return "ELIMINATION_PHASE";
        case MatchType::Friendly: return "FRIENDLY";
        case MatchType::UnknownMatch:
        default: return "UNKNOWN_MATCH";
    }
    #pragma clang diagnostic pop
}

Referee::Referee() {

}