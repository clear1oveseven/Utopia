// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProtoId.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ProtoId.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace NetProto {

namespace protobuf_ProtoId_2eproto {


namespace {

const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[1] = {};
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;
namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "ProtoId.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      NULL, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace
void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rProtoId.proto\022\010NetProto*\376\003\n\007ProtoId\022\013\n"
      "\007PID_Min\020\000\022\014\n\010PID_Ping\020\001\022\014\n\010PID_Pong\020\002\022\025"
      "\n\021PID_QueryFreeHero\020d\022\023\n\017PID_RspFreeHero"
      "\020e\022\025\n\021PID_SelectHeroReq\020f\022\025\n\021PID_SelectH"
      "eroRsp\020g\022\031\n\025PID_LoadSceneComplete\020h\022\022\n\016P"
      "ID_LeaveScene\020i\022\030\n\024PID_PullAllSceneInfo\020"
      "j\022\033\n\027PID_PullAllSceneInfoRsp\020k\022\031\n\024PID_Sc"
      "eneObjectState\020\350\007\022\035\n\030PID_SceneObjectDisa"
      "ppear\020\351\007\022\030\n\023PID_MoveObjectState\020\362\007\022\037\n\032PI"
      "D_MoveObjectMutableState\020\363\007\022\022\n\rPID_MoveT"
      "oPos\020\374\007\022\021\n\014PID_StopMove\020\206\010\022\027\n\022PID_Battle"
      "OperaReq\020\314\010\022\025\n\020PID_ViewSnapshot\020\326\010\022\025\n\020PI"
      "D_ViewAllGrids\020\327\010\022\031\n\024PID_ViewSnapshotDif"
      "f\020\330\010\022\014\n\007PID_Max\020\200(B\003\370\001\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 551);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ProtoId.proto", &protobuf_RegisterTypes);
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_ProtoId_2eproto

const ::google::protobuf::EnumDescriptor* ProtoId_descriptor() {
  protobuf_ProtoId_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_ProtoId_2eproto::file_level_enum_descriptors[0];
}
bool ProtoId_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 1000:
    case 1001:
    case 1010:
    case 1011:
    case 1020:
    case 1030:
    case 1100:
    case 1110:
    case 1111:
    case 1112:
    case 5120:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace NetProto

// @@protoc_insertion_point(global_scope)
