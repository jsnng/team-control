# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: ssl_vision_detection_tracked.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import TeamControl.SSL.proto2.ssl_gc_common_pb2 as ssl__gc__common__pb2
import TeamControl.SSL.proto2.ssl_gc_geometry_pb2 as ssl__gc__geometry__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\"ssl_vision_detection_tracked.proto\x1a\x13ssl_gc_common.proto\x1a\x15ssl_gc_geometry.proto\"O\n\x0bTrackedBall\x12\x15\n\x03pos\x18\x01 \x02(\x0b\x32\x08.Vector3\x12\x15\n\x03vel\x18\x02 \x01(\x0b\x32\x08.Vector3\x12\x12\n\nvisibility\x18\x03 \x01(\x02\"\xa3\x01\n\nKickedBall\x12\x15\n\x03pos\x18\x01 \x02(\x0b\x32\x08.Vector2\x12\x15\n\x03vel\x18\x02 \x02(\x0b\x32\x08.Vector3\x12\x17\n\x0fstart_timestamp\x18\x03 \x02(\x01\x12\x16\n\x0estop_timestamp\x18\x04 \x01(\x01\x12\x1a\n\x08stop_pos\x18\x05 \x01(\x0b\x32\x08.Vector2\x12\x1a\n\x08robot_id\x18\x06 \x01(\x0b\x32\x08.RobotId\"\x96\x01\n\x0cTrackedRobot\x12\x1a\n\x08robot_id\x18\x01 \x02(\x0b\x32\x08.RobotId\x12\x15\n\x03pos\x18\x02 \x02(\x0b\x32\x08.Vector2\x12\x13\n\x0borientation\x18\x03 \x02(\x02\x12\x15\n\x03vel\x18\x04 \x01(\x0b\x32\x08.Vector2\x12\x13\n\x0bvel_angular\x18\x05 \x01(\x02\x12\x12\n\nvisibility\x18\x06 \x01(\x02\"\xb8\x01\n\x0cTrackedFrame\x12\x14\n\x0c\x66rame_number\x18\x01 \x02(\r\x12\x11\n\ttimestamp\x18\x02 \x02(\x01\x12\x1b\n\x05\x62\x61lls\x18\x03 \x03(\x0b\x32\x0c.TrackedBall\x12\x1d\n\x06robots\x18\x04 \x03(\x0b\x32\r.TrackedRobot\x12 \n\x0bkicked_ball\x18\x05 \x01(\x0b\x32\x0b.KickedBall\x12!\n\x0c\x63\x61pabilities\x18\x06 \x03(\x0e\x32\x0b.Capability*\x92\x01\n\nCapability\x12\x16\n\x12\x43\x41PABILITY_UNKNOWN\x10\x00\x12\"\n\x1e\x43\x41PABILITY_DETECT_FLYING_BALLS\x10\x01\x12$\n CAPABILITY_DETECT_MULTIPLE_BALLS\x10\x02\x12\"\n\x1e\x43\x41PABILITY_DETECT_KICKED_BALLS\x10\x03\x42\x41Z?github.com/RoboCup-SSL/ssl-game-controller/internal/app/tracker')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'ssl_vision_detection_tracked_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  DESCRIPTOR._serialized_options = b'Z?github.com/RoboCup-SSL/ssl-game-controller/internal/app/tracker'
  _CAPABILITY._serialized_start=670
  _CAPABILITY._serialized_end=816
  _TRACKEDBALL._serialized_start=82
  _TRACKEDBALL._serialized_end=161
  _KICKEDBALL._serialized_start=164
  _KICKEDBALL._serialized_end=327
  _TRACKEDROBOT._serialized_start=330
  _TRACKEDROBOT._serialized_end=480
  _TRACKEDFRAME._serialized_start=483
  _TRACKEDFRAME._serialized_end=667
# @@protoc_insertion_point(module_scope)
