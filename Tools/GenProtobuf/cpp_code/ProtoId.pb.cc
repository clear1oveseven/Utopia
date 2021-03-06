// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProtoId.proto

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
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace NetProto {
}  // namespace NetProto
namespace protobuf_ProtoId_2eproto {
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];
const ::google::protobuf::uint32 TableStruct::offsets[1] = {};
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;

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

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rProtoId.proto\022\010NetProto*\371\003\n\007ProtoId\022\013\n"
      "\007PID_Min\020\000\022\014\n\010PID_Ping\020\001\022\014\n\010PID_Pong\020\002\022\025"
      "\n\021PID_QueryFreeHero\020d\022\023\n\017PID_RspFreeHero"
      "\020e\022\025\n\021PID_SelectHeroReq\020f\022\025\n\021PID_SelectH"
      "eroRsp\020g\022\031\n\025PID_LoadSceneComplete\020h\022\022\n\016P"
      "ID_LeaveScene\020i\022\035\n\030PID_SceneObjectDisapp"
      "ear\020\362\007\022\022\n\rPID_MoveToPos\020\374\007\022\021\n\014PID_StopMo"
      "ve\020\206\010\022\027\n\022PID_BattleOperaReq\020\314\010\022\025\n\020PID_Vi"
      "ewSnapshot\020\326\010\022\025\n\020PID_ViewAllGrids\020\327\010\022\031\n\024"
      "PID_ViewSnapshotDiff\020\330\010\022\027\n\022PID_SceneUnit"
      "State\020\260\t\022\033\n\026PID_SceneUnitTransform\020\261\t\022\026\n"
      "\021PID_SceneUnitMove\020\262\t\022\035\n\030PID_SceneUnitSk"
      "illAction\020\263\t\022\031\n\024PID_ReloadLuaScripts\020\241\037\022"
      "\014\n\007PID_Max\020\200(B\003\370\001\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 546);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ProtoId.proto", &protobuf_RegisterTypes);
}

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
namespace NetProto {
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
    case 1010:
    case 1020:
    case 1030:
    case 1100:
    case 1110:
    case 1111:
    case 1112:
    case 1200:
    case 1201:
    case 1202:
    case 1203:
    case 4001:
    case 5120:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace NetProto
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
