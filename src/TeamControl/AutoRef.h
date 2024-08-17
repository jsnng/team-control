#ifndef AUTOREF_H_
#define AUTOREF_H_

#include "ssl_gc_referee_message.pb.h"
#include "ssl_gc_game_event.pb.h"
#include "SSL_Receiver.h"

class AutoRef {
    public:
    AutoRef() =default;
    ~AutoRef() =default;
    void from_protobuf(std::string packet);
    uint64_t get_packet_timestamp();
    Referee_Stage get_stage();
    std::optional<int64_t> get_stage_time_left();
    Referee_Command get_command();
    uint32_t get_command_timestamp();
    Referee_TeamInfo get_yellow();
    Referee_TeamInfo get_blue();
    Referee_Point get_designated_position();
    std::optional<bool> get_blue_team_on_positive_half();
    Referee_Command get_next_command();
    std::vector<GameEvent> get_game_events();
    std::vector<GameEventProposalGroup> get_game_event_proposals();
    std::optional<int64_t> get_current_action_time_remaining();
    std::optional<std::string> get_status_message();
    private:
    Referee ssl_gc_referee_message;
};

#endif // AUTOREF_H_