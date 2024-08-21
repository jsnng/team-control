#ifndef AUTOREF_H_
#define AUTOREF_H_

#include "ssl_gc_referee_message.pb.h"
#include "ssl_gc_game_event.pb.h"
#include "SSL_Receiver.h"

class TeamInformation {
    public:
    TeamInformation(Referee_TeamInfo info) {
        ssl_gc_team_info = info;
    }
    ~TeamInformation() =default;
    inline std::string get_name() const {
        return ssl_gc_team_info.name();
    }
    inline uint32_t get_score() const {
        return ssl_gc_team_info.score();
    }
    inline uint32_t get_red_cards() const {
        return ssl_gc_team_info.red_cards();
    }
    std::vector<uint32_t> get_yellow_card_times();
    inline uint32_t get_yellow_cards() const {
        return ssl_gc_team_info.yellow_cards();
    }
    inline uint32_t get_timeouts() const {
        return ssl_gc_team_info.timeouts();
    }
    inline uint32_t get_timeout_time() const {
        return ssl_gc_team_info.timeout_time();
    }
    inline uint32_t get_goalkeeper() const {
        return ssl_gc_team_info.goalkeeper();
    }
    inline std::optional<uint32_t> get_foul_counter() const {
        if(ssl_gc_team_info.has_foul_counter()) {
            return ssl_gc_team_info.foul_counter();
        }
        return std::nullopt;
    }
    inline std::optional<uint32_t> get_ball_placement_failures() const {
        if(ssl_gc_team_info.has_ball_placement_failures()) {
            return ssl_gc_team_info.ball_placement_failures();
        }
        return std::nullopt;
    }
    inline std::optional<bool> get_can_place_ball() const {
        if(ssl_gc_team_info.has_can_place_ball()) {
            return ssl_gc_team_info.can_place_ball();
        }
        return std::nullopt;
    }
    inline std::optional<uint32_t> get_max_allowed_bots() const {
        if(ssl_gc_team_info.has_max_allowed_bots()) {
            return ssl_gc_team_info.max_allowed_bots();
        }
        return std::nullopt;
    }
    inline std::optional<bool> get_bot_substitution_allowed() const {
        if(ssl_gc_team_info.has_bot_substitution_allowed()) {
            return ssl_gc_team_info.bot_substitution_allowed();
        }
        return std::nullopt;
    }
    inline std::optional<uint32_t> get_bot_substitutions_left() const {
        if(ssl_gc_team_info.has_bot_substitutions_left()) {
            return ssl_gc_team_info.bot_substitutions_left();
        }
        return std::nullopt;
    }
    inline std::optional<uint32_t> get_bot_substitution_time_left() const {
        if(ssl_gc_team_info.has_bot_substitution_time_left()) {
            return ssl_gc_team_info.bot_substitution_time_left();
        }
        return std::nullopt;
    }
    private:
    Referee_TeamInfo ssl_gc_team_info;
};

class AutoRef {
    public:
    AutoRef() =default;
    ~AutoRef() =default;

    inline void from_protobuf(std::string packet) {
        ssl_gc_referee_message.ParseFromString(packet);
        std::cerr << ssl_gc_referee_message.DebugString() << "\n";
    }
    inline uint64_t get_packet_timestamp() const {
        return ssl_gc_referee_message.packet_timestamp();
    }
    inline Referee_Stage get_stage() const {
        return ssl_gc_referee_message.stage();
    }
    inline std::optional<int64_t> get_stage_time_left() const {
        if(ssl_gc_referee_message.has_stage_time_left()) {
            return ssl_gc_referee_message.stage_time_left();
        }
        return std::nullopt;
    }
    inline Referee_Command get_command() const {
        return ssl_gc_referee_message.command();
    }
    inline uint32_t get_command_timestamp() const {
        return ssl_gc_referee_message.command_timestamp();
    }
    inline TeamInformation get_yellow() const {
        TeamInformation yellow(ssl_gc_referee_message.yellow());
        return yellow;
    }
    inline TeamInformation get_blue() const {
        TeamInformation blue(ssl_gc_referee_message.blue());
        return blue;
    }
    inline Referee_Point get_designated_position() const {
        return ssl_gc_referee_message.designated_position();
    }
    inline std::optional<bool> get_blue_team_on_positive_half() const {
        if(ssl_gc_referee_message.has_blue_team_on_positive_half()) {
            return ssl_gc_referee_message.blue_team_on_positive_half();
        }
        return std::nullopt;
    }
    inline Referee_Command get_next_command() const {
        return ssl_gc_referee_message.next_command();
    }
    inline std::vector<GameEvent> get_game_events() const {
        if(ssl_gc_referee_message.game_events_size() <= 0) {
            return std::vector<GameEvent>();
        }
        std::vector<GameEvent> game_events;
        std::copy(ssl_gc_referee_message.game_events().begin(), 
            ssl_gc_referee_message.game_events().end(), std::back_inserter(game_events));
        return game_events;
    }
    inline std::vector<GameEventProposalGroup> get_game_event_proposals() const {
        if(ssl_gc_referee_message.game_event_proposals_size() <= 0) {
            return std::vector<GameEventProposalGroup>();
        }
        std::vector<GameEventProposalGroup> game_events;
        std::copy(ssl_gc_referee_message.game_event_proposals().begin(), 
            ssl_gc_referee_message.game_event_proposals().end(), std::back_inserter(game_events));
        return game_events;
    }
    inline std::optional<int64_t> get_current_action_time_remaining() const {
        if(ssl_gc_referee_message.has_current_action_time_remaining()) {
            return ssl_gc_referee_message.current_action_time_remaining();
        }
        return std::nullopt;
    }
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