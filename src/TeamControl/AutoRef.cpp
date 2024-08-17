#include "AutoRef.h"
#include "SSL_Receiver.h"

void AutoRef::from_protobuf(std::string packet) {
    ssl_gc_referee_message.ParseFromString(packet);
    std::cerr << ssl_gc_referee_message.DebugString() << "\n";
}
uint64_t AutoRef::get_packet_timestamp() {
    return ssl_gc_referee_message.packet_timestamp();
}
Referee_Stage AutoRef::get_stage() {
    return ssl_gc_referee_message.stage();
}
std::optional<int64_t> AutoRef::get_stage_time_left() {
    if(ssl_gc_referee_message.has_stage_time_left()) {
        return ssl_gc_referee_message.stage_time_left();
    }
    return std::nullopt;
}
Referee_Command AutoRef::get_command() {
    return ssl_gc_referee_message.command();
}
uint32_t AutoRef::get_command_timestamp() {
    return ssl_gc_referee_message.command_timestamp();
}
Referee_TeamInfo AutoRef::get_yellow() {
    return ssl_gc_referee_message.yellow();
}
Referee_TeamInfo AutoRef::get_blue() {
    return ssl_gc_referee_message.blue();
}
Referee_Point AutoRef::get_designated_position() {
    return ssl_gc_referee_message.designated_position();
}
std::optional<bool> AutoRef::get_blue_team_on_positive_half() {
    if(ssl_gc_referee_message.has_blue_team_on_positive_half()) {
        return ssl_gc_referee_message.blue_team_on_positive_half();
    }
    return std::nullopt;
}
Referee_Command AutoRef::get_next_command() {
    return ssl_gc_referee_message.next_command();
}
std::vector<GameEvent> AutoRef::get_game_events() {
    if(ssl_gc_referee_message.game_events_size() <= 0) {
        return std::vector<GameEvent>();
    }
    std::vector<GameEvent> game_events;
    std::copy(ssl_gc_referee_message.game_events().begin(), 
        ssl_gc_referee_message.game_events().end(), std::back_inserter(game_events));
    return game_events;
}
std::vector<GameEventProposalGroup> AutoRef::get_game_event_proposals() {
    if(ssl_gc_referee_message.game_event_proposals_size() <= 0) {
        return std::vector<GameEventProposalGroup>();
    }
    std::vector<GameEventProposalGroup> game_events;
    std::copy(ssl_gc_referee_message.game_event_proposals().begin(), 
        ssl_gc_referee_message.game_event_proposals().end(), std::back_inserter(game_events));
    return game_events;
}
std::optional<int64_t> AutoRef::get_current_action_time_remaining() {
    if(ssl_gc_referee_message.has_current_action_time_remaining()) {
        return ssl_gc_referee_message.current_action_time_remaining();
    }
    return std::nullopt;
}
std::optional<std::string> AutoRef::get_status_message() {
    if(ssl_gc_referee_message.has_status_message()) {
        return ssl_gc_referee_message.status_message();
    }
    return std::nullopt;
}