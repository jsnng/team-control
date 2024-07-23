# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: ssl_gc_game_event.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import TeamControl.SSL.proto2.ssl_gc_common_pb2 as ssl__gc__common__pb2
import TeamControl.SSL.proto2.ssl_gc_geometry_pb2 as ssl__gc__geometry__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x17ssl_gc_game_event.proto\x1a\x13ssl_gc_common.proto\x1a\x15ssl_gc_geometry.proto\"\x85\x43\n\tGameEvent\x12\n\n\x02id\x18\x32 \x01(\t\x12\x1d\n\x04type\x18( \x01(\x0e\x32\x0f.GameEvent.Type\x12\x0e\n\x06origin\x18) \x03(\t\x12\x19\n\x11\x63reated_timestamp\x18\x31 \x01(\x04\x12>\n\x1a\x62\x61ll_left_field_touch_line\x18\x06 \x01(\x0b\x32\x18.GameEvent.BallLeftFieldH\x00\x12=\n\x19\x62\x61ll_left_field_goal_line\x18\x07 \x01(\x0b\x32\x18.GameEvent.BallLeftFieldH\x00\x12.\n\x0c\x61imless_kick\x18\x0b \x01(\x0b\x32\x16.GameEvent.AimlessKickH\x00\x12V\n\"attacker_too_close_to_defense_area\x18\x13 \x01(\x0b\x32(.GameEvent.AttackerTooCloseToDefenseAreaH\x00\x12\x44\n\x18\x64\x65\x66\x65nder_in_defense_area\x18\x1f \x01(\x0b\x32 .GameEvent.DefenderInDefenseAreaH\x00\x12\x38\n\x11\x62oundary_crossing\x18+ \x01(\x0b\x32\x1b.GameEvent.BoundaryCrossingH\x00\x12\x35\n\x10keeper_held_ball\x18\r \x01(\x0b\x32\x19.GameEvent.KeeperHeldBallH\x00\x12\x45\n\x19\x62ot_dribbled_ball_too_far\x18\x11 \x01(\x0b\x32 .GameEvent.BotDribbledBallTooFarH\x00\x12\x31\n\x0e\x62ot_pushed_bot\x18\x18 \x01(\x0b\x32\x17.GameEvent.BotPushedBotH\x00\x12H\n\x1a\x62ot_held_ball_deliberately\x18\x1a \x01(\x0b\x32\".GameEvent.BotHeldBallDeliberatelyH\x00\x12\x33\n\x0f\x62ot_tipped_over\x18\x1b \x01(\x0b\x32\x18.GameEvent.BotTippedOverH\x00\x12\x37\n\x11\x62ot_dropped_parts\x18\x33 \x01(\x0b\x32\x1a.GameEvent.BotDroppedPartsH\x00\x12\\\n%attacker_touched_ball_in_defense_area\x18\x0f \x01(\x0b\x32+.GameEvent.AttackerTouchedBallInDefenseAreaH\x00\x12\x43\n\x18\x62ot_kicked_ball_too_fast\x18\x12 \x01(\x0b\x32\x1f.GameEvent.BotKickedBallTooFastH\x00\x12\x35\n\x10\x62ot_crash_unique\x18\x16 \x01(\x0b\x32\x19.GameEvent.BotCrashUniqueH\x00\x12\x33\n\x0f\x62ot_crash_drawn\x18\x15 \x01(\x0b\x32\x18.GameEvent.BotCrashDrawnH\x00\x12R\n defender_too_close_to_kick_point\x18\x1d \x01(\x0b\x32&.GameEvent.DefenderTooCloseToKickPointH\x00\x12;\n\x14\x62ot_too_fast_in_stop\x18\x1c \x01(\x0b\x32\x1b.GameEvent.BotTooFastInStopH\x00\x12\x45\n\x18\x62ot_interfered_placement\x18\x14 \x01(\x0b\x32!.GameEvent.BotInterferedPlacementH\x00\x12(\n\rpossible_goal\x18\' \x01(\x0b\x32\x0f.GameEvent.GoalH\x00\x12\x1f\n\x04goal\x18\x08 \x01(\x0b\x32\x0f.GameEvent.GoalH\x00\x12\'\n\x0cinvalid_goal\x18, \x01(\x0b\x32\x0f.GameEvent.GoalH\x00\x12L\n\x1c\x61ttacker_double_touched_ball\x18\x0e \x01(\x0b\x32$.GameEvent.AttackerDoubleTouchedBallH\x00\x12<\n\x13placement_succeeded\x18\x05 \x01(\x0b\x32\x1d.GameEvent.PlacementSucceededH\x00\x12;\n\x13penalty_kick_failed\x18- \x01(\x0b\x32\x1c.GameEvent.PenaltyKickFailedH\x00\x12:\n\x13no_progress_in_game\x18\x02 \x01(\x0b\x32\x1b.GameEvent.NoProgressInGameH\x00\x12\x36\n\x10placement_failed\x18\x03 \x01(\x0b\x32\x1a.GameEvent.PlacementFailedH\x00\x12\x32\n\x0emultiple_cards\x18  \x01(\x0b\x32\x18.GameEvent.MultipleCardsH\x00\x12\x32\n\x0emultiple_fouls\x18\" \x01(\x0b\x32\x18.GameEvent.MultipleFoulsH\x00\x12\x36\n\x10\x62ot_substitution\x18% \x01(\x0b\x32\x1a.GameEvent.BotSubstitutionH\x00\x12I\n\x1a\x65xcessive_bot_substitution\x18\x34 \x01(\x0b\x32#.GameEvent.ExcessiveBotSubstitutionH\x00\x12\x33\n\x0ftoo_many_robots\x18& \x01(\x0b\x32\x18.GameEvent.TooManyRobotsH\x00\x12\x32\n\x0e\x63hallenge_flag\x18. \x01(\x0b\x32\x18.GameEvent.ChallengeFlagH\x00\x12\x41\n\x16\x63hallenge_flag_handled\x18\x30 \x01(\x0b\x32\x1f.GameEvent.ChallengeFlagHandledH\x00\x12\x32\n\x0e\x65mergency_stop\x18/ \x01(\x0b\x32\x18.GameEvent.EmergencyStopH\x00\x12G\n\x19unsporting_behavior_minor\x18# \x01(\x0b\x32\".GameEvent.UnsportingBehaviorMinorH\x00\x12G\n\x19unsporting_behavior_major\x18$ \x01(\x0b\x32\".GameEvent.UnsportingBehaviorMajorH\x00\x12+\n\x08prepared\x18\x01 \x01(\x0b\x32\x13.GameEvent.PreparedB\x02\x18\x01H\x00\x12\x34\n\rindirect_goal\x18\t \x01(\x0b\x32\x17.GameEvent.IndirectGoalB\x02\x18\x01H\x00\x12\x32\n\x0c\x63hipped_goal\x18\n \x01(\x0b\x32\x16.GameEvent.ChippedGoalB\x02\x18\x01H\x00\x12\x32\n\x0ckick_timeout\x18\x0c \x01(\x0b\x32\x16.GameEvent.KickTimeoutB\x02\x18\x01H\x00\x12h\n)attacker_touched_opponent_in_defense_area\x18\x10 \x01(\x0b\x32/.GameEvent.AttackerTouchedOpponentInDefenseAreaB\x02\x18\x01H\x00\x12p\n1attacker_touched_opponent_in_defense_area_skipped\x18* \x01(\x0b\x32/.GameEvent.AttackerTouchedOpponentInDefenseAreaB\x02\x18\x01H\x00\x12\x41\n\x18\x62ot_crash_unique_skipped\x18\x17 \x01(\x0b\x32\x19.GameEvent.BotCrashUniqueB\x02\x18\x01H\x00\x12=\n\x16\x62ot_pushed_bot_skipped\x18\x19 \x01(\x0b\x32\x17.GameEvent.BotPushedBotB\x02\x18\x01H\x00\x12[\n\"defender_in_defense_area_partially\x18\x1e \x01(\x0b\x32).GameEvent.DefenderInDefenseAreaPartiallyB\x02\x18\x01H\x00\x12O\n\x1bmultiple_placement_failures\x18! \x01(\x0b\x32$.GameEvent.MultiplePlacementFailuresB\x02\x18\x01H\x00\x1aS\n\rBallLeftField\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x1ar\n\x0b\x41imlessKick\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x1f\n\rkick_location\x18\x04 \x01(\x0b\x32\x08.Vector2\x1a\xef\x01\n\x04Goal\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x1b\n\x0ckicking_team\x18\x06 \x01(\x0e\x32\x05.Team\x12\x13\n\x0bkicking_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x1f\n\rkick_location\x18\x04 \x01(\x0b\x32\x08.Vector2\x12\x17\n\x0fmax_ball_height\x18\x05 \x01(\x02\x12\x1a\n\x12num_robots_by_team\x18\x07 \x01(\r\x12\x1a\n\x12last_touch_by_team\x18\x08 \x01(\x04\x12\x0f\n\x07message\x18\t \x01(\t\x1as\n\x0cIndirectGoal\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x1f\n\rkick_location\x18\x04 \x01(\x0b\x32\x08.Vector2\x1a\x8b\x01\n\x0b\x43hippedGoal\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x1f\n\rkick_location\x18\x04 \x01(\x0b\x32\x08.Vector2\x12\x17\n\x0fmax_ball_height\x18\x05 \x01(\x02\x1a\x65\n\x10\x42otTooFastInStop\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\r\n\x05speed\x18\x04 \x01(\x02\x1as\n\x1b\x44\x65\x66\x65nderTooCloseToKickPoint\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x10\n\x08\x64istance\x18\x04 \x01(\x02\x1a\x8f\x01\n\rBotCrashDrawn\x12\x12\n\nbot_yellow\x18\x01 \x01(\r\x12\x10\n\x08\x62ot_blue\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x13\n\x0b\x63rash_speed\x18\x04 \x01(\x02\x12\x12\n\nspeed_diff\x18\x05 \x01(\x02\x12\x13\n\x0b\x63rash_angle\x18\x06 \x01(\x02\x1a\xa4\x01\n\x0e\x42otCrashUnique\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x10\n\x08violator\x18\x02 \x01(\r\x12\x0e\n\x06victim\x18\x03 \x01(\r\x12\x1a\n\x08location\x18\x04 \x01(\x0b\x32\x08.Vector2\x12\x13\n\x0b\x63rash_speed\x18\x05 \x01(\x02\x12\x12\n\nspeed_diff\x18\x06 \x01(\x02\x12\x13\n\x0b\x63rash_angle\x18\x07 \x01(\x02\x1a}\n\x0c\x42otPushedBot\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x10\n\x08violator\x18\x02 \x01(\r\x12\x0e\n\x06victim\x18\x03 \x01(\r\x12\x1a\n\x08location\x18\x04 \x01(\x0b\x32\x08.Vector2\x12\x17\n\x0fpushed_distance\x18\x05 \x01(\x02\x1at\n\rBotTippedOver\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x1f\n\rball_location\x18\x04 \x01(\x0b\x32\x08.Vector2\x1av\n\x0f\x42otDroppedParts\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x1f\n\rball_location\x18\x04 \x01(\x0b\x32\x08.Vector2\x1am\n\x15\x44\x65\x66\x65nderInDefenseArea\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x10\n\x08\x64istance\x18\x04 \x01(\x02\x1a\x97\x01\n\x1e\x44\x65\x66\x65nderInDefenseAreaPartially\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x10\n\x08\x64istance\x18\x04 \x01(\x02\x12\x1f\n\rball_location\x18\x05 \x01(\x0b\x32\x08.Vector2\x1ax\n AttackerTouchedBallInDefenseArea\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x10\n\x08\x64istance\x18\x04 \x01(\x02\x1a\x87\x01\n\x14\x42otKickedBallTooFast\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x1a\n\x12initial_ball_speed\x18\x04 \x01(\x02\x12\x0f\n\x07\x63hipped\x18\x05 \x01(\x08\x1ao\n\x15\x42otDribbledBallTooFar\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x17\n\x05start\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x15\n\x03\x65nd\x18\x04 \x01(\x0b\x32\x08.Vector2\x1az\n$AttackerTouchedOpponentInDefenseArea\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x0e\n\x06victim\x18\x04 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x1a_\n\x19\x41ttackerDoubleTouchedBall\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x1a\x96\x01\n\x1d\x41ttackerTooCloseToDefenseArea\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x10\n\x08\x64istance\x18\x04 \x01(\x02\x12\x1f\n\rball_location\x18\x05 \x01(\x0b\x32\x08.Vector2\x1ao\n\x17\x42otHeldBallDeliberately\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x12\x10\n\x08\x64uration\x18\x04 \x01(\x02\x1a\\\n\x16\x42otInterferedPlacement\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06\x62y_bot\x18\x02 \x01(\r\x12\x1a\n\x08location\x18\x03 \x01(\x0b\x32\x08.Vector2\x1a\'\n\rMultipleCards\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x1aO\n\rMultipleFouls\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12&\n\x12\x63\x61used_game_events\x18\x02 \x03(\x0b\x32\n.GameEvent\x1a\x33\n\x19MultiplePlacementFailures\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x1aO\n\x0bKickTimeout\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x1a\n\x08location\x18\x02 \x01(\x0b\x32\x08.Vector2\x12\x0c\n\x04time\x18\x03 \x01(\x02\x1a<\n\x10NoProgressInGame\x12\x1a\n\x08location\x18\x01 \x01(\x0b\x32\x08.Vector2\x12\x0c\n\x04time\x18\x02 \x01(\x02\x1ag\n\x0fPlacementFailed\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x1a\n\x12remaining_distance\x18\x02 \x01(\x02\x12 \n\x18nearest_own_bot_distance\x18\x03 \x01(\x02\x1a\x41\n\x17UnsportingBehaviorMinor\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06reason\x18\x02 \x02(\t\x1a\x41\n\x17UnsportingBehaviorMajor\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x0e\n\x06reason\x18\x02 \x02(\t\x1aV\n\x0eKeeperHeldBall\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x1a\n\x08location\x18\x02 \x01(\x0b\x32\x08.Vector2\x12\x10\n\x08\x64uration\x18\x03 \x01(\x02\x1a\x65\n\x12PlacementSucceeded\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x12\n\ntime_taken\x18\x02 \x01(\x02\x12\x11\n\tprecision\x18\x03 \x01(\x02\x12\x10\n\x08\x64istance\x18\x04 \x01(\x02\x1a\x1e\n\x08Prepared\x12\x12\n\ntime_taken\x18\x01 \x01(\x02\x1a)\n\x0f\x42otSubstitution\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x1a\x32\n\x18\x45xcessiveBotSubstitution\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x1a\'\n\rChallengeFlag\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x1a@\n\x14\x43hallengeFlagHandled\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x10\n\x08\x61\x63\x63\x65pted\x18\x02 \x02(\x08\x1a\'\n\rEmergencyStop\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x1a\x81\x01\n\rTooManyRobots\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x1a\n\x12num_robots_allowed\x18\x02 \x01(\x05\x12\x1b\n\x13num_robots_on_field\x18\x03 \x01(\x05\x12\x1f\n\rball_location\x18\x04 \x01(\x0b\x32\x08.Vector2\x1a\x46\n\x10\x42oundaryCrossing\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x1a\n\x08location\x18\x02 \x01(\x0b\x32\x08.Vector2\x1aW\n\x11PenaltyKickFailed\x12\x16\n\x07\x62y_team\x18\x01 \x02(\x0e\x32\x05.Team\x12\x1a\n\x08location\x18\x02 \x01(\x0b\x32\x08.Vector2\x12\x0e\n\x06reason\x18\x03 \x01(\t\"\xb5\n\n\x04Type\x12\x1b\n\x17UNKNOWN_GAME_EVENT_TYPE\x10\x00\x12\x1e\n\x1a\x42\x41LL_LEFT_FIELD_TOUCH_LINE\x10\x06\x12\x1d\n\x19\x42\x41LL_LEFT_FIELD_GOAL_LINE\x10\x07\x12\x10\n\x0c\x41IMLESS_KICK\x10\x0b\x12&\n\"ATTACKER_TOO_CLOSE_TO_DEFENSE_AREA\x10\x13\x12\x1c\n\x18\x44\x45\x46\x45NDER_IN_DEFENSE_AREA\x10\x1f\x12\x15\n\x11\x42OUNDARY_CROSSING\x10)\x12\x14\n\x10KEEPER_HELD_BALL\x10\r\x12\x1d\n\x19\x42OT_DRIBBLED_BALL_TOO_FAR\x10\x11\x12\x12\n\x0e\x42OT_PUSHED_BOT\x10\x18\x12\x1e\n\x1a\x42OT_HELD_BALL_DELIBERATELY\x10\x1a\x12\x13\n\x0f\x42OT_TIPPED_OVER\x10\x1b\x12\x15\n\x11\x42OT_DROPPED_PARTS\x10/\x12)\n%ATTACKER_TOUCHED_BALL_IN_DEFENSE_AREA\x10\x0f\x12\x1c\n\x18\x42OT_KICKED_BALL_TOO_FAST\x10\x12\x12\x14\n\x10\x42OT_CRASH_UNIQUE\x10\x16\x12\x13\n\x0f\x42OT_CRASH_DRAWN\x10\x15\x12$\n DEFENDER_TOO_CLOSE_TO_KICK_POINT\x10\x1d\x12\x18\n\x14\x42OT_TOO_FAST_IN_STOP\x10\x1c\x12\x1c\n\x18\x42OT_INTERFERED_PLACEMENT\x10\x14\x12\x1e\n\x1a\x45XCESSIVE_BOT_SUBSTITUTION\x10\x30\x12\x11\n\rPOSSIBLE_GOAL\x10\'\x12\x08\n\x04GOAL\x10\x08\x12\x10\n\x0cINVALID_GOAL\x10*\x12 \n\x1c\x41TTACKER_DOUBLE_TOUCHED_BALL\x10\x0e\x12\x17\n\x13PLACEMENT_SUCCEEDED\x10\x05\x12\x17\n\x13PENALTY_KICK_FAILED\x10+\x12\x17\n\x13NO_PROGRESS_IN_GAME\x10\x02\x12\x14\n\x10PLACEMENT_FAILED\x10\x03\x12\x12\n\x0eMULTIPLE_CARDS\x10 \x12\x12\n\x0eMULTIPLE_FOULS\x10\"\x12\x14\n\x10\x42OT_SUBSTITUTION\x10%\x12\x13\n\x0fTOO_MANY_ROBOTS\x10&\x12\x12\n\x0e\x43HALLENGE_FLAG\x10,\x12\x1a\n\x16\x43HALLENGE_FLAG_HANDLED\x10.\x12\x12\n\x0e\x45MERGENCY_STOP\x10-\x12\x1d\n\x19UNSPORTING_BEHAVIOR_MINOR\x10#\x12\x1d\n\x19UNSPORTING_BEHAVIOR_MAJOR\x10$\x12\x10\n\x08PREPARED\x10\x01\x1a\x02\x08\x01\x12\x15\n\rINDIRECT_GOAL\x10\t\x1a\x02\x08\x01\x12\x14\n\x0c\x43HIPPED_GOAL\x10\n\x1a\x02\x08\x01\x12\x14\n\x0cKICK_TIMEOUT\x10\x0c\x1a\x02\x08\x01\x12\x31\n)ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA\x10\x10\x1a\x02\x08\x01\x12\x39\n1ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA_SKIPPED\x10(\x1a\x02\x08\x01\x12 \n\x18\x42OT_CRASH_UNIQUE_SKIPPED\x10\x17\x1a\x02\x08\x01\x12\x1e\n\x16\x42OT_PUSHED_BOT_SKIPPED\x10\x19\x1a\x02\x08\x01\x12*\n\"DEFENDER_IN_DEFENSE_AREA_PARTIALLY\x10\x1e\x1a\x02\x08\x01\x12#\n\x1bMULTIPLE_PLACEMENT_FAILURES\x10!\x1a\x02\x08\x01\x42\x07\n\x05\x65ventB?Z=github.com/RoboCup-SSL/ssl-game-controller/internal/app/state')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'ssl_gc_game_event_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  DESCRIPTOR._serialized_options = b'Z=github.com/RoboCup-SSL/ssl-game-controller/internal/app/state'
  _GAMEEVENT_TYPE.values_by_name["PREPARED"]._options = None
  _GAMEEVENT_TYPE.values_by_name["PREPARED"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["INDIRECT_GOAL"]._options = None
  _GAMEEVENT_TYPE.values_by_name["INDIRECT_GOAL"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["CHIPPED_GOAL"]._options = None
  _GAMEEVENT_TYPE.values_by_name["CHIPPED_GOAL"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["KICK_TIMEOUT"]._options = None
  _GAMEEVENT_TYPE.values_by_name["KICK_TIMEOUT"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA"]._options = None
  _GAMEEVENT_TYPE.values_by_name["ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA_SKIPPED"]._options = None
  _GAMEEVENT_TYPE.values_by_name["ATTACKER_TOUCHED_OPPONENT_IN_DEFENSE_AREA_SKIPPED"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["BOT_CRASH_UNIQUE_SKIPPED"]._options = None
  _GAMEEVENT_TYPE.values_by_name["BOT_CRASH_UNIQUE_SKIPPED"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["BOT_PUSHED_BOT_SKIPPED"]._options = None
  _GAMEEVENT_TYPE.values_by_name["BOT_PUSHED_BOT_SKIPPED"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["DEFENDER_IN_DEFENSE_AREA_PARTIALLY"]._options = None
  _GAMEEVENT_TYPE.values_by_name["DEFENDER_IN_DEFENSE_AREA_PARTIALLY"]._serialized_options = b'\010\001'
  _GAMEEVENT_TYPE.values_by_name["MULTIPLE_PLACEMENT_FAILURES"]._options = None
  _GAMEEVENT_TYPE.values_by_name["MULTIPLE_PLACEMENT_FAILURES"]._serialized_options = b'\010\001'
  _GAMEEVENT.fields_by_name['prepared']._options = None
  _GAMEEVENT.fields_by_name['prepared']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['indirect_goal']._options = None
  _GAMEEVENT.fields_by_name['indirect_goal']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['chipped_goal']._options = None
  _GAMEEVENT.fields_by_name['chipped_goal']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['kick_timeout']._options = None
  _GAMEEVENT.fields_by_name['kick_timeout']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['attacker_touched_opponent_in_defense_area']._options = None
  _GAMEEVENT.fields_by_name['attacker_touched_opponent_in_defense_area']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['attacker_touched_opponent_in_defense_area_skipped']._options = None
  _GAMEEVENT.fields_by_name['attacker_touched_opponent_in_defense_area_skipped']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['bot_crash_unique_skipped']._options = None
  _GAMEEVENT.fields_by_name['bot_crash_unique_skipped']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['bot_pushed_bot_skipped']._options = None
  _GAMEEVENT.fields_by_name['bot_pushed_bot_skipped']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['defender_in_defense_area_partially']._options = None
  _GAMEEVENT.fields_by_name['defender_in_defense_area_partially']._serialized_options = b'\030\001'
  _GAMEEVENT.fields_by_name['multiple_placement_failures']._options = None
  _GAMEEVENT.fields_by_name['multiple_placement_failures']._serialized_options = b'\030\001'
  _GAMEEVENT._serialized_start=72
  _GAMEEVENT._serialized_end=8653
  _GAMEEVENT_BALLLEFTFIELD._serialized_start=3175
  _GAMEEVENT_BALLLEFTFIELD._serialized_end=3258
  _GAMEEVENT_AIMLESSKICK._serialized_start=3260
  _GAMEEVENT_AIMLESSKICK._serialized_end=3374
  _GAMEEVENT_GOAL._serialized_start=3377
  _GAMEEVENT_GOAL._serialized_end=3616
  _GAMEEVENT_INDIRECTGOAL._serialized_start=3618
  _GAMEEVENT_INDIRECTGOAL._serialized_end=3733
  _GAMEEVENT_CHIPPEDGOAL._serialized_start=3736
  _GAMEEVENT_CHIPPEDGOAL._serialized_end=3875
  _GAMEEVENT_BOTTOOFASTINSTOP._serialized_start=3877
  _GAMEEVENT_BOTTOOFASTINSTOP._serialized_end=3978
  _GAMEEVENT_DEFENDERTOOCLOSETOKICKPOINT._serialized_start=3980
  _GAMEEVENT_DEFENDERTOOCLOSETOKICKPOINT._serialized_end=4095
  _GAMEEVENT_BOTCRASHDRAWN._serialized_start=4098
  _GAMEEVENT_BOTCRASHDRAWN._serialized_end=4241
  _GAMEEVENT_BOTCRASHUNIQUE._serialized_start=4244
  _GAMEEVENT_BOTCRASHUNIQUE._serialized_end=4408
  _GAMEEVENT_BOTPUSHEDBOT._serialized_start=4410
  _GAMEEVENT_BOTPUSHEDBOT._serialized_end=4535
  _GAMEEVENT_BOTTIPPEDOVER._serialized_start=4537
  _GAMEEVENT_BOTTIPPEDOVER._serialized_end=4653
  _GAMEEVENT_BOTDROPPEDPARTS._serialized_start=4655
  _GAMEEVENT_BOTDROPPEDPARTS._serialized_end=4773
  _GAMEEVENT_DEFENDERINDEFENSEAREA._serialized_start=4775
  _GAMEEVENT_DEFENDERINDEFENSEAREA._serialized_end=4884
  _GAMEEVENT_DEFENDERINDEFENSEAREAPARTIALLY._serialized_start=4887
  _GAMEEVENT_DEFENDERINDEFENSEAREAPARTIALLY._serialized_end=5038
  _GAMEEVENT_ATTACKERTOUCHEDBALLINDEFENSEAREA._serialized_start=5040
  _GAMEEVENT_ATTACKERTOUCHEDBALLINDEFENSEAREA._serialized_end=5160
  _GAMEEVENT_BOTKICKEDBALLTOOFAST._serialized_start=5163
  _GAMEEVENT_BOTKICKEDBALLTOOFAST._serialized_end=5298
  _GAMEEVENT_BOTDRIBBLEDBALLTOOFAR._serialized_start=5300
  _GAMEEVENT_BOTDRIBBLEDBALLTOOFAR._serialized_end=5411
  _GAMEEVENT_ATTACKERTOUCHEDOPPONENTINDEFENSEAREA._serialized_start=5413
  _GAMEEVENT_ATTACKERTOUCHEDOPPONENTINDEFENSEAREA._serialized_end=5535
  _GAMEEVENT_ATTACKERDOUBLETOUCHEDBALL._serialized_start=5537
  _GAMEEVENT_ATTACKERDOUBLETOUCHEDBALL._serialized_end=5632
  _GAMEEVENT_ATTACKERTOOCLOSETODEFENSEAREA._serialized_start=5635
  _GAMEEVENT_ATTACKERTOOCLOSETODEFENSEAREA._serialized_end=5785
  _GAMEEVENT_BOTHELDBALLDELIBERATELY._serialized_start=5787
  _GAMEEVENT_BOTHELDBALLDELIBERATELY._serialized_end=5898
  _GAMEEVENT_BOTINTERFEREDPLACEMENT._serialized_start=5900
  _GAMEEVENT_BOTINTERFEREDPLACEMENT._serialized_end=5992
  _GAMEEVENT_MULTIPLECARDS._serialized_start=5994
  _GAMEEVENT_MULTIPLECARDS._serialized_end=6033
  _GAMEEVENT_MULTIPLEFOULS._serialized_start=6035
  _GAMEEVENT_MULTIPLEFOULS._serialized_end=6114
  _GAMEEVENT_MULTIPLEPLACEMENTFAILURES._serialized_start=6116
  _GAMEEVENT_MULTIPLEPLACEMENTFAILURES._serialized_end=6167
  _GAMEEVENT_KICKTIMEOUT._serialized_start=6169
  _GAMEEVENT_KICKTIMEOUT._serialized_end=6248
  _GAMEEVENT_NOPROGRESSINGAME._serialized_start=6250
  _GAMEEVENT_NOPROGRESSINGAME._serialized_end=6310
  _GAMEEVENT_PLACEMENTFAILED._serialized_start=6312
  _GAMEEVENT_PLACEMENTFAILED._serialized_end=6415
  _GAMEEVENT_UNSPORTINGBEHAVIORMINOR._serialized_start=6417
  _GAMEEVENT_UNSPORTINGBEHAVIORMINOR._serialized_end=6482
  _GAMEEVENT_UNSPORTINGBEHAVIORMAJOR._serialized_start=6484
  _GAMEEVENT_UNSPORTINGBEHAVIORMAJOR._serialized_end=6549
  _GAMEEVENT_KEEPERHELDBALL._serialized_start=6551
  _GAMEEVENT_KEEPERHELDBALL._serialized_end=6637
  _GAMEEVENT_PLACEMENTSUCCEEDED._serialized_start=6639
  _GAMEEVENT_PLACEMENTSUCCEEDED._serialized_end=6740
  _GAMEEVENT_PREPARED._serialized_start=6742
  _GAMEEVENT_PREPARED._serialized_end=6772
  _GAMEEVENT_BOTSUBSTITUTION._serialized_start=6774
  _GAMEEVENT_BOTSUBSTITUTION._serialized_end=6815
  _GAMEEVENT_EXCESSIVEBOTSUBSTITUTION._serialized_start=6817
  _GAMEEVENT_EXCESSIVEBOTSUBSTITUTION._serialized_end=6867
  _GAMEEVENT_CHALLENGEFLAG._serialized_start=6869
  _GAMEEVENT_CHALLENGEFLAG._serialized_end=6908
  _GAMEEVENT_CHALLENGEFLAGHANDLED._serialized_start=6910
  _GAMEEVENT_CHALLENGEFLAGHANDLED._serialized_end=6974
  _GAMEEVENT_EMERGENCYSTOP._serialized_start=6976
  _GAMEEVENT_EMERGENCYSTOP._serialized_end=7015
  _GAMEEVENT_TOOMANYROBOTS._serialized_start=7018
  _GAMEEVENT_TOOMANYROBOTS._serialized_end=7147
  _GAMEEVENT_BOUNDARYCROSSING._serialized_start=7149
  _GAMEEVENT_BOUNDARYCROSSING._serialized_end=7219
  _GAMEEVENT_PENALTYKICKFAILED._serialized_start=7221
  _GAMEEVENT_PENALTYKICKFAILED._serialized_end=7308
  _GAMEEVENT_TYPE._serialized_start=7311
  _GAMEEVENT_TYPE._serialized_end=8644
# @@protoc_insertion_point(module_scope)
