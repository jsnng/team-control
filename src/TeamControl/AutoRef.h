#ifndef AUTOREF_H_
#define AUTOREF_H_

#include "ssl_gc_referee_message.pb.h"
#include "ssl_gc_game_event.pb.h"
#include "SSL_Receiver.h"

class TeamInformation {
    public:
    /**
     * TeamInformation constructor
     * @note refer to `protobuf/ssl_gc_referee_message.proto`
     * @param info Referee_TeamInfo protobuf structure 
     */
    TeamInformation(Referee_TeamInfo info) {
        ssl_gc_team_info = info;
    }
    ~TeamInformation() =default;
    /**
     * get attribute `name` from Referee_TeamInfo
     * @return string Referee_TeamInfo.name
     */
    inline std::string get_name() const {
        return ssl_gc_team_info.name();
    }
    /**
     * get attribute `score` from Referee_TeamInfo
     * @return uint32_t Referee_TeamInfo.score
     */
    inline uint32_t get_score() const {
        return ssl_gc_team_info.score();
    }
    /**
     * get attribute `red_cards` from Referee_TeamInfo
     * @return uint32_t Referee_TeamInfo.red_cards
     */
    inline uint32_t get_red_cards() const {
        return ssl_gc_team_info.red_cards();
    }
    /**
     * get attribute `yellow_cards` from Referee_TeamInfo
     * @return vector<uint32_t> Referee_TeamInfo.yellow_cards
     */
    std::vector<uint32_t> get_yellow_card_times();
    inline uint32_t get_yellow_cards() const {
        return ssl_gc_team_info.yellow_cards();
    }
    /**
     * get attribute `timeouts` from Referee_TeamInfo
     * @return uint32_t Referee_TeamInfo.timeouts
     */
    inline uint32_t get_timeouts() const {
        return ssl_gc_team_info.timeouts();
    }
     /**
     * get attribute `timeout_time` from Referee_TeamInfo
     * @return uint32_t Referee_TeamInfo.timeout_time
     */
    inline uint32_t get_timeout_time() const {
        return ssl_gc_team_info.timeout_time();
    }
    /**
     * get attribute `goalkeeper` from Referee_TeamInfo
     * @return uint32_t Referee_TeamInfo.goalkeeper
     */
    inline uint32_t get_goalkeeper() const {
        return ssl_gc_team_info.goalkeeper();
    }
    /**
     * get attribute `foul_counter` from Referee_TeamInfo
     * @return optional<uint32_t> Referee_TeamInfo.foul_counter
     */
    inline std::optional<uint32_t> get_foul_counter() const {
        if(ssl_gc_team_info.has_foul_counter()) {
            return ssl_gc_team_info.foul_counter();
        }
        return std::nullopt;
    }
    /**
     * get attribute `ball_placement_failures` from Referee_TeamInfo
     * @return optional<uint32_t> Referee_TeamInfo.ball_placement_failures
     */
    inline std::optional<uint32_t> get_ball_placement_failures() const {
        if(ssl_gc_team_info.has_ball_placement_failures()) {
            return ssl_gc_team_info.ball_placement_failures();
        }
        return std::nullopt;
    }
    /**
     * get attribute `can_place_ball` from Referee_TeamInfo
     * @return optional<bool> Referee_TeamInfo.can_place_ball
     */
    inline std::optional<bool> get_can_place_ball() const {
        if(ssl_gc_team_info.has_can_place_ball()) {
            return ssl_gc_team_info.can_place_ball();
        }
        return std::nullopt;
    }
    /**
     * get attribute `max_allowed_bots` from Referee_TeamInfo
     * @return optional<uint32_t> Referee_TeamInfo.max_allowed_bots
     */
    inline std::optional<uint32_t> get_max_allowed_bots() const {
        if(ssl_gc_team_info.has_max_allowed_bots()) {
            return ssl_gc_team_info.max_allowed_bots();
        }
        return std::nullopt;
    }
    /**
     * get attribute `bot_substitution_allowed` from Referee_TeamInfo
     * @return optional<bool> Referee_TeamInfo.bot_substitution_allowed
     */
    inline std::optional<bool> get_bot_substitution_allowed() const {
        if(ssl_gc_team_info.has_bot_substitution_allowed()) {
            return ssl_gc_team_info.bot_substitution_allowed();
        }
        return std::nullopt;
    }
    /**
     * get attribute `bot_substitutions_left` from Referee_TeamInfo
     * @return optional<uint32_t> Referee_TeamInfo.bot_substitutions_left
     */
    inline std::optional<uint32_t> get_bot_substitutions_left() const {
        if(ssl_gc_team_info.has_bot_substitutions_left()) {
            return ssl_gc_team_info.bot_substitutions_left();
        }
        return std::nullopt;
    }
    /**
     * get attribute `bot_substitution_time_left` from Referee_TeamInfo
     * @return optional<uint32_t> Referee_TeamInfo.bot_substitution_time_left
     */
    inline std::optional<uint32_t> get_bot_substitution_time_left() const {
        if(ssl_gc_team_info.has_bot_substitution_time_left()) {
            return ssl_gc_team_info.bot_substitution_time_left();
        }
        return std::nullopt;
    }
    private:
    Referee_TeamInfo ssl_gc_team_info;
};

/**
 * @see refer to `protobuf/ssl_gc_referee_message.proto`
 */
class AutoRef {
    public:
    AutoRef() =default;
    ~AutoRef() =default;
    /**
     * convert a string from network into SSL_Referee_Message protobuf
     * @param packet recieved data as a string
     */
    inline void from_protobuf(std::string packet) {
        ssl_gc_referee_message.ParseFromString(packet);
        std::cerr << ssl_gc_referee_message.DebugString() << "\n";
    }
    /**
     * get attribute `packet_timestamp` from SSL_Referee_Message
     * @return uint64_t Referee.packet_timestamp
     */
    inline uint64_t get_packet_timestamp() const {
        return ssl_gc_referee_message.packet_timestamp();
    }
    /**
     * get attribute `stage` from SSL_Referee_Message
     * @return Referee_Stage Referee.stage
     */
    inline Referee_Stage get_stage() const {
        return ssl_gc_referee_message.stage();
    }
    /**
     * get attribute `stage_time_left` from SSL_Referee_Message
     * @return optional<int64_t> Referee.stage_time_left
     */
    inline std::optional<int64_t> get_stage_time_left() const {
        if(ssl_gc_referee_message.has_stage_time_left()) {
            return ssl_gc_referee_message.stage_time_left();
        }
        return std::nullopt;
    }
    /**
     * get attribute `command` from SSL_Referee_Message
     * @return Referee_Command Referee.command
     */
    inline Referee_Command get_command() const {
        return ssl_gc_referee_message.command();
    }
    /**
     * get attribute `command_timestamp` from SSL_Referee_Message
     * @return uint32_t Referee.command_timestamp
     */
    inline uint32_t get_command_timestamp() const {
        return ssl_gc_referee_message.command_timestamp();
    }
    /**
     * get attribute `yellow` from SSL_Referee_Message
     * @return TeamInformation Referee.yellow
     */
    inline TeamInformation get_yellow() const {
        TeamInformation yellow(ssl_gc_referee_message.yellow());
        return yellow;
    }
    /**
     * get attribute `blue` from SSL_Referee_Message
     * @return TeamInformation Referee.blue
     */
    inline TeamInformation get_blue() const {
        TeamInformation blue(ssl_gc_referee_message.blue());
        return blue;
    }
    /**
     * get attribute `Referee_Point` from SSL_Referee_Message
     * @return Referee_Stage Referee.designated_position
     */
    inline Referee_Point get_designated_position() const {
        return ssl_gc_referee_message.designated_position();
    }
    /**
     * get attribute `blue_team_on_positive_half` from SSL_Referee_Message
     * @return optional<bool> Referee.blue_team_on_positive_half
     */
    inline std::optional<bool> get_blue_team_on_positive_half() const {
        if(ssl_gc_referee_message.has_blue_team_on_positive_half()) {
            return ssl_gc_referee_message.blue_team_on_positive_half();
        }
        return std::nullopt;
    }
    /**
     * get attribute `next_command` from SSL_Referee_Message
     * @return Referee_Command Referee.next_command
     */
    inline Referee_Command get_next_command() const {
        return ssl_gc_referee_message.next_command();
    }
    /**
     * get attribute `game_events_size` from SSL_Referee_Message
     * @return vector<GameEvent> Referee.game_events_size
     */
    inline std::vector<GameEvent> get_game_events() const {
        if(ssl_gc_referee_message.game_events_size() <= 0) {
            return std::vector<GameEvent>();
        }
        std::vector<GameEvent> game_events;
        std::copy(ssl_gc_referee_message.game_events().begin(), 
            ssl_gc_referee_message.game_events().end(), std::back_inserter(game_events));
        return game_events;
    }
    /**
     * get attribute `game_event_proposals_size9` from SSL_Referee_Message
     * @return vector<GameEventProposalGroup> Referee.game_event_proposals_size
     */
    inline std::vector<GameEventProposalGroup> get_game_event_proposals() const {
        if(ssl_gc_referee_message.game_event_proposals_size() <= 0) {
            return std::vector<GameEventProposalGroup>();
        }
        std::vector<GameEventProposalGroup> game_events;
        std::copy(ssl_gc_referee_message.game_event_proposals().begin(), 
            ssl_gc_referee_message.game_event_proposals().end(), std::back_inserter(game_events));
        return game_events;
    }
    /**
     * get attribute `current_action_time_remaining` from SSL_Referee_Message
     * @return optional<int64_t> Referee.current_action_time_remaining
     */
    inline std::optional<int64_t> get_current_action_time_remaining() const {
        if(ssl_gc_referee_message.has_current_action_time_remaining()) {
            return ssl_gc_referee_message.current_action_time_remaining();
        }
        return std::nullopt;
    }   
    /**
     * get attribute `status_message` from SSL_Referee_Message
     * @return optional<string> Referee.status_message
     */
    inline std::optional<std::string> get_status_message() const {
        if(ssl_gc_referee_message.has_status_message()) {
            return ssl_gc_referee_message.status_message();
        }
        return std::nullopt;
    }
    private:
    Referee ssl_gc_referee_message;
};

#endif // AUTOREF_H_