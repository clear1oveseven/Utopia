# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: Battle.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import Common_pb2 as Common__pb2
import BattleEnum_pb2 as BattleEnum__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='Battle.proto',
  package='NetProto',
  syntax='proto3',
  serialized_pb=_b('\n\x0c\x42\x61ttle.proto\x12\x08NetProto\x1a\x0c\x43ommon.proto\x1a\x10\x42\x61ttleEnum.proto\"8\n\x0bRspFreeHero\x12\x13\n\x0bred_hero_id\x18\x01 \x01(\x04\x12\x14\n\x0c\x62lue_hero_id\x18\x02 \x01(\x04\" \n\rSelectHeroReq\x12\x0f\n\x07hero_id\x18\x01 \x01(\x04\"1\n\rSelectHeroRsp\x12\x0f\n\x07hero_id\x18\x01 \x01(\x04\x12\x0f\n\x07is_succ\x18\x02 \x01(\x08\"&\n\x14SceneObjectDisappear\x12\x0e\n\x06objids\x18\x01 \x03(\x04\"-\n\tMoveToPos\x12 \n\x03pos\x18\x01 \x01(\x0b\x32\x13.NetProto.PBVector2\"\xa4\x01\n\x0f\x42\x61ttleOperation\x12%\n\x05opera\x18\x01 \x01(\x0e\x32\x16.NetProto.EPlayerOpera\x12\x11\n\ttarget_id\x18\x02 \x01(\x04\x12\x0b\n\x03\x64ir\x18\x03 \x01(\x02\x12 \n\x03pos\x18\x04 \x01(\x0b\x32\x13.NetProto.PBVector2\x12(\n\nskill_slot\x18\x05 \x01(\x0e\x32\x14.NetProto.ESkillSlot\"B\n\x08ViewGrid\x12#\n\x06\x63\x65nter\x18\x01 \x01(\x0b\x32\x13.NetProto.PBVector2\x12\x11\n\tgrid_type\x18\x02 \x01(\x05\":\n\x10ViewSnapshotDiff\x12\x12\n\nmore_grids\x18\x01 \x03(\x05\x12\x12\n\nmiss_grids\x18\x02 \x03(\x05\"#\n\x0cViewSnapshot\x12\x13\n\x0blight_grids\x18\x01 \x03(\x05\"^\n\x0cViewAllGrids\x12\x11\n\tgrid_size\x18\x01 \x01(\x02\x12\x0b\n\x03row\x18\x02 \x01(\x05\x12\x0b\n\x03\x63ol\x18\x03 \x01(\x05\x12!\n\x05grids\x18\x04 \x03(\x0b\x32\x12.NetProto.ViewGrid\"\x8e\x01\n\x0eSceneUnitState\x12\r\n\x05su_id\x18\x01 \x01(\x04\x12\x11\n\tunit_type\x18\x02 \x01(\x05\x12\x10\n\x08model_id\x18\x03 \x01(\x05\x12 \n\x03pos\x18\x04 \x01(\x0b\x32\x13.NetProto.PBVector3\x12\x10\n\x08\x66\x61\x63\x65_dir\x18\x05 \x01(\x02\x12\x14\n\x0cparent_su_id\x18\x06 \x01(\x04\"m\n\x12SceneUnitTransform\x12\r\n\x05su_id\x18\x01 \x01(\x04\x12 \n\x03pos\x18\x02 \x01(\x0b\x32\x13.NetProto.PBVector3\x12\x10\n\x08\x66\x61\x63\x65_dir\x18\x03 \x01(\x02\x12\x14\n\x0cparent_su_id\x18\x04 \x01(\x04\"S\n\rSceneUnitMove\x12\r\n\x05su_id\x18\x01 \x01(\x04\x12\x33\n\x10move_agent_state\x18\x02 \x01(\x0e\x32\x19.NetProto.EMoveAgentStateB\x03\xf8\x01\x01\x62\x06proto3')
  ,
  dependencies=[Common__pb2.DESCRIPTOR,BattleEnum__pb2.DESCRIPTOR,])




_RSPFREEHERO = _descriptor.Descriptor(
  name='RspFreeHero',
  full_name='NetProto.RspFreeHero',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='red_hero_id', full_name='NetProto.RspFreeHero.red_hero_id', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='blue_hero_id', full_name='NetProto.RspFreeHero.blue_hero_id', index=1,
      number=2, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=58,
  serialized_end=114,
)


_SELECTHEROREQ = _descriptor.Descriptor(
  name='SelectHeroReq',
  full_name='NetProto.SelectHeroReq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='hero_id', full_name='NetProto.SelectHeroReq.hero_id', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=116,
  serialized_end=148,
)


_SELECTHERORSP = _descriptor.Descriptor(
  name='SelectHeroRsp',
  full_name='NetProto.SelectHeroRsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='hero_id', full_name='NetProto.SelectHeroRsp.hero_id', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='is_succ', full_name='NetProto.SelectHeroRsp.is_succ', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=150,
  serialized_end=199,
)


_SCENEOBJECTDISAPPEAR = _descriptor.Descriptor(
  name='SceneObjectDisappear',
  full_name='NetProto.SceneObjectDisappear',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='objids', full_name='NetProto.SceneObjectDisappear.objids', index=0,
      number=1, type=4, cpp_type=4, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=201,
  serialized_end=239,
)


_MOVETOPOS = _descriptor.Descriptor(
  name='MoveToPos',
  full_name='NetProto.MoveToPos',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='pos', full_name='NetProto.MoveToPos.pos', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=241,
  serialized_end=286,
)


_BATTLEOPERATION = _descriptor.Descriptor(
  name='BattleOperation',
  full_name='NetProto.BattleOperation',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='opera', full_name='NetProto.BattleOperation.opera', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='target_id', full_name='NetProto.BattleOperation.target_id', index=1,
      number=2, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='dir', full_name='NetProto.BattleOperation.dir', index=2,
      number=3, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos', full_name='NetProto.BattleOperation.pos', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='skill_slot', full_name='NetProto.BattleOperation.skill_slot', index=4,
      number=5, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=289,
  serialized_end=453,
)


_VIEWGRID = _descriptor.Descriptor(
  name='ViewGrid',
  full_name='NetProto.ViewGrid',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='center', full_name='NetProto.ViewGrid.center', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='grid_type', full_name='NetProto.ViewGrid.grid_type', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=455,
  serialized_end=521,
)


_VIEWSNAPSHOTDIFF = _descriptor.Descriptor(
  name='ViewSnapshotDiff',
  full_name='NetProto.ViewSnapshotDiff',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='more_grids', full_name='NetProto.ViewSnapshotDiff.more_grids', index=0,
      number=1, type=5, cpp_type=1, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='miss_grids', full_name='NetProto.ViewSnapshotDiff.miss_grids', index=1,
      number=2, type=5, cpp_type=1, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=523,
  serialized_end=581,
)


_VIEWSNAPSHOT = _descriptor.Descriptor(
  name='ViewSnapshot',
  full_name='NetProto.ViewSnapshot',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='light_grids', full_name='NetProto.ViewSnapshot.light_grids', index=0,
      number=1, type=5, cpp_type=1, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=583,
  serialized_end=618,
)


_VIEWALLGRIDS = _descriptor.Descriptor(
  name='ViewAllGrids',
  full_name='NetProto.ViewAllGrids',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='grid_size', full_name='NetProto.ViewAllGrids.grid_size', index=0,
      number=1, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='row', full_name='NetProto.ViewAllGrids.row', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='col', full_name='NetProto.ViewAllGrids.col', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='grids', full_name='NetProto.ViewAllGrids.grids', index=3,
      number=4, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=620,
  serialized_end=714,
)


_SCENEUNITSTATE = _descriptor.Descriptor(
  name='SceneUnitState',
  full_name='NetProto.SceneUnitState',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='su_id', full_name='NetProto.SceneUnitState.su_id', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='unit_type', full_name='NetProto.SceneUnitState.unit_type', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='model_id', full_name='NetProto.SceneUnitState.model_id', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos', full_name='NetProto.SceneUnitState.pos', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='face_dir', full_name='NetProto.SceneUnitState.face_dir', index=4,
      number=5, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='parent_su_id', full_name='NetProto.SceneUnitState.parent_su_id', index=5,
      number=6, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=717,
  serialized_end=859,
)


_SCENEUNITTRANSFORM = _descriptor.Descriptor(
  name='SceneUnitTransform',
  full_name='NetProto.SceneUnitTransform',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='su_id', full_name='NetProto.SceneUnitTransform.su_id', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos', full_name='NetProto.SceneUnitTransform.pos', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='face_dir', full_name='NetProto.SceneUnitTransform.face_dir', index=2,
      number=3, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='parent_su_id', full_name='NetProto.SceneUnitTransform.parent_su_id', index=3,
      number=4, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=861,
  serialized_end=970,
)


_SCENEUNITMOVE = _descriptor.Descriptor(
  name='SceneUnitMove',
  full_name='NetProto.SceneUnitMove',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='su_id', full_name='NetProto.SceneUnitMove.su_id', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='move_agent_state', full_name='NetProto.SceneUnitMove.move_agent_state', index=1,
      number=2, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=972,
  serialized_end=1055,
)

_MOVETOPOS.fields_by_name['pos'].message_type = Common__pb2._PBVECTOR2
_BATTLEOPERATION.fields_by_name['opera'].enum_type = BattleEnum__pb2._EPLAYEROPERA
_BATTLEOPERATION.fields_by_name['pos'].message_type = Common__pb2._PBVECTOR2
_BATTLEOPERATION.fields_by_name['skill_slot'].enum_type = BattleEnum__pb2._ESKILLSLOT
_VIEWGRID.fields_by_name['center'].message_type = Common__pb2._PBVECTOR2
_VIEWALLGRIDS.fields_by_name['grids'].message_type = _VIEWGRID
_SCENEUNITSTATE.fields_by_name['pos'].message_type = Common__pb2._PBVECTOR3
_SCENEUNITTRANSFORM.fields_by_name['pos'].message_type = Common__pb2._PBVECTOR3
_SCENEUNITMOVE.fields_by_name['move_agent_state'].enum_type = BattleEnum__pb2._EMOVEAGENTSTATE
DESCRIPTOR.message_types_by_name['RspFreeHero'] = _RSPFREEHERO
DESCRIPTOR.message_types_by_name['SelectHeroReq'] = _SELECTHEROREQ
DESCRIPTOR.message_types_by_name['SelectHeroRsp'] = _SELECTHERORSP
DESCRIPTOR.message_types_by_name['SceneObjectDisappear'] = _SCENEOBJECTDISAPPEAR
DESCRIPTOR.message_types_by_name['MoveToPos'] = _MOVETOPOS
DESCRIPTOR.message_types_by_name['BattleOperation'] = _BATTLEOPERATION
DESCRIPTOR.message_types_by_name['ViewGrid'] = _VIEWGRID
DESCRIPTOR.message_types_by_name['ViewSnapshotDiff'] = _VIEWSNAPSHOTDIFF
DESCRIPTOR.message_types_by_name['ViewSnapshot'] = _VIEWSNAPSHOT
DESCRIPTOR.message_types_by_name['ViewAllGrids'] = _VIEWALLGRIDS
DESCRIPTOR.message_types_by_name['SceneUnitState'] = _SCENEUNITSTATE
DESCRIPTOR.message_types_by_name['SceneUnitTransform'] = _SCENEUNITTRANSFORM
DESCRIPTOR.message_types_by_name['SceneUnitMove'] = _SCENEUNITMOVE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

RspFreeHero = _reflection.GeneratedProtocolMessageType('RspFreeHero', (_message.Message,), dict(
  DESCRIPTOR = _RSPFREEHERO,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.RspFreeHero)
  ))
_sym_db.RegisterMessage(RspFreeHero)

SelectHeroReq = _reflection.GeneratedProtocolMessageType('SelectHeroReq', (_message.Message,), dict(
  DESCRIPTOR = _SELECTHEROREQ,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.SelectHeroReq)
  ))
_sym_db.RegisterMessage(SelectHeroReq)

SelectHeroRsp = _reflection.GeneratedProtocolMessageType('SelectHeroRsp', (_message.Message,), dict(
  DESCRIPTOR = _SELECTHERORSP,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.SelectHeroRsp)
  ))
_sym_db.RegisterMessage(SelectHeroRsp)

SceneObjectDisappear = _reflection.GeneratedProtocolMessageType('SceneObjectDisappear', (_message.Message,), dict(
  DESCRIPTOR = _SCENEOBJECTDISAPPEAR,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.SceneObjectDisappear)
  ))
_sym_db.RegisterMessage(SceneObjectDisappear)

MoveToPos = _reflection.GeneratedProtocolMessageType('MoveToPos', (_message.Message,), dict(
  DESCRIPTOR = _MOVETOPOS,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.MoveToPos)
  ))
_sym_db.RegisterMessage(MoveToPos)

BattleOperation = _reflection.GeneratedProtocolMessageType('BattleOperation', (_message.Message,), dict(
  DESCRIPTOR = _BATTLEOPERATION,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.BattleOperation)
  ))
_sym_db.RegisterMessage(BattleOperation)

ViewGrid = _reflection.GeneratedProtocolMessageType('ViewGrid', (_message.Message,), dict(
  DESCRIPTOR = _VIEWGRID,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.ViewGrid)
  ))
_sym_db.RegisterMessage(ViewGrid)

ViewSnapshotDiff = _reflection.GeneratedProtocolMessageType('ViewSnapshotDiff', (_message.Message,), dict(
  DESCRIPTOR = _VIEWSNAPSHOTDIFF,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.ViewSnapshotDiff)
  ))
_sym_db.RegisterMessage(ViewSnapshotDiff)

ViewSnapshot = _reflection.GeneratedProtocolMessageType('ViewSnapshot', (_message.Message,), dict(
  DESCRIPTOR = _VIEWSNAPSHOT,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.ViewSnapshot)
  ))
_sym_db.RegisterMessage(ViewSnapshot)

ViewAllGrids = _reflection.GeneratedProtocolMessageType('ViewAllGrids', (_message.Message,), dict(
  DESCRIPTOR = _VIEWALLGRIDS,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.ViewAllGrids)
  ))
_sym_db.RegisterMessage(ViewAllGrids)

SceneUnitState = _reflection.GeneratedProtocolMessageType('SceneUnitState', (_message.Message,), dict(
  DESCRIPTOR = _SCENEUNITSTATE,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.SceneUnitState)
  ))
_sym_db.RegisterMessage(SceneUnitState)

SceneUnitTransform = _reflection.GeneratedProtocolMessageType('SceneUnitTransform', (_message.Message,), dict(
  DESCRIPTOR = _SCENEUNITTRANSFORM,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.SceneUnitTransform)
  ))
_sym_db.RegisterMessage(SceneUnitTransform)

SceneUnitMove = _reflection.GeneratedProtocolMessageType('SceneUnitMove', (_message.Message,), dict(
  DESCRIPTOR = _SCENEUNITMOVE,
  __module__ = 'Battle_pb2'
  # @@protoc_insertion_point(class_scope:NetProto.SceneUnitMove)
  ))
_sym_db.RegisterMessage(SceneUnitMove)


DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), _b('\370\001\001'))
# @@protoc_insertion_point(module_scope)
