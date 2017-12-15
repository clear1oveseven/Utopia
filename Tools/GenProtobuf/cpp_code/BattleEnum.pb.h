// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BattleEnum.proto

#ifndef PROTOBUF_BattleEnum_2eproto__INCLUDED
#define PROTOBUF_BattleEnum_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
namespace NetProto {
}  // namespace NetProto

namespace NetProto {

namespace protobuf_BattleEnum_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_BattleEnum_2eproto

enum EUnitType {
  Building = 0,
  Hero = 1,
  Npc = 2,
  MAX = 3,
  EUnitType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EUnitType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EUnitType_IsValid(int value);
const EUnitType EUnitType_MIN = Building;
const EUnitType EUnitType_MAX = MAX;
const int EUnitType_ARRAYSIZE = EUnitType_MAX + 1;

const ::google::protobuf::EnumDescriptor* EUnitType_descriptor();
inline const ::std::string& EUnitType_Name(EUnitType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EUnitType_descriptor(), value);
}
inline bool EUnitType_Parse(
    const ::std::string& name, EUnitType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EUnitType>(
    EUnitType_descriptor(), name, value);
}
enum EMoveAgentState {
  EMoveAgentState_Idle = 0,
  EMoveAgentState_MoveToPos = 1,
  EMoveAgentState_MoveToDir = 2,
  EMoveAgentState_Immobilized = 3,
  EMoveAgentState_ForceLine = 4,
  EMoveAgentState_ForcePos = 5,
  EMoveAgentState_Max = 6,
  EMoveAgentState_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EMoveAgentState_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EMoveAgentState_IsValid(int value);
const EMoveAgentState EMoveAgentState_MIN = EMoveAgentState_Idle;
const EMoveAgentState EMoveAgentState_MAX = EMoveAgentState_Max;
const int EMoveAgentState_ARRAYSIZE = EMoveAgentState_MAX + 1;

const ::google::protobuf::EnumDescriptor* EMoveAgentState_descriptor();
inline const ::std::string& EMoveAgentState_Name(EMoveAgentState value) {
  return ::google::protobuf::internal::NameOfEnum(
    EMoveAgentState_descriptor(), value);
}
inline bool EMoveAgentState_Parse(
    const ::std::string& name, EMoveAgentState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EMoveAgentState>(
    EMoveAgentState_descriptor(), name, value);
}
enum EMoveState {
  EMoveState_Idle = 0,
  EMoveState_Move = 1,
  EMoveState_Immobilized = 2,
  EMoveState_ForceMove = 3,
  EMoveState_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EMoveState_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EMoveState_IsValid(int value);
const EMoveState EMoveState_MIN = EMoveState_Idle;
const EMoveState EMoveState_MAX = EMoveState_ForceMove;
const int EMoveState_ARRAYSIZE = EMoveState_MAX + 1;

const ::google::protobuf::EnumDescriptor* EMoveState_descriptor();
inline const ::std::string& EMoveState_Name(EMoveState value) {
  return ::google::protobuf::internal::NameOfEnum(
    EMoveState_descriptor(), value);
}
inline bool EMoveState_Parse(
    const ::std::string& name, EMoveState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EMoveState>(
    EMoveState_descriptor(), name, value);
}
enum EPlayerOpera {
  EPO_Invalid = 0,
  EPO_Stop = 1,
  EPO_Move = 2,
  EPO_Follow = 3,
  EPO_Hunt = 4,
  EPO_CastSkill = 5,
  EPO_UseItem = 6,
  EPO_Trace = 7,
  EBO_MaxCount = 32,
  EPlayerOpera_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EPlayerOpera_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EPlayerOpera_IsValid(int value);
const EPlayerOpera EPlayerOpera_MIN = EPO_Invalid;
const EPlayerOpera EPlayerOpera_MAX = EBO_MaxCount;
const int EPlayerOpera_ARRAYSIZE = EPlayerOpera_MAX + 1;

const ::google::protobuf::EnumDescriptor* EPlayerOpera_descriptor();
inline const ::std::string& EPlayerOpera_Name(EPlayerOpera value) {
  return ::google::protobuf::internal::NameOfEnum(
    EPlayerOpera_descriptor(), value);
}
inline bool EPlayerOpera_Parse(
    const ::std::string& name, EPlayerOpera* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EPlayerOpera>(
    EPlayerOpera_descriptor(), name, value);
}
enum EFightParam {
  EFP_None = 0,
  EFP_HP = 1,
  EFP_MP = 2,
  EFP_MaxHP = 9,
  EFP_MaxMP = 10,
  EFP_MoveSpeed = 11,
  EFP_AttackDist = 12,
  EFP_AttackSpeed = 13,
  EFP_PhyAttack = 14,
  EFP_MagicAttack = 15,
  EFP_PhyHurt = 16,
  EFP_MagicHurt = 17,
  EFP_PhyDefense = 18,
  EFP_MagicDefense = 19,
  EFP_Dizzy = 20,
  EFP_Silence = 21,
  EFP_Blind = 22,
  EFP_Immobilized = 23,
  EFP_Dead = 24,
  EFP_COUNT = 32,
  EFightParam_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EFightParam_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EFightParam_IsValid(int value);
const EFightParam EFightParam_MIN = EFP_None;
const EFightParam EFightParam_MAX = EFP_COUNT;
const int EFightParam_ARRAYSIZE = EFightParam_MAX + 1;

const ::google::protobuf::EnumDescriptor* EFightParam_descriptor();
inline const ::std::string& EFightParam_Name(EFightParam value) {
  return ::google::protobuf::internal::NameOfEnum(
    EFightParam_descriptor(), value);
}
inline bool EFightParam_Parse(
    const ::std::string& name, EFightParam* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EFightParam>(
    EFightParam_descriptor(), name, value);
}
enum ESkillSlot {
  ESS_QSlot = 0,
  ESS_WSlot = 1,
  ESS_ESlot = 2,
  ESS_RSlot = 3,
  ESS_FSlot = 4,
  ESS_GSlot = 5,
  ESS_PSlot = 6,
  ESS_OneSlot = 11,
  ESS_TwoSlot = 12,
  ESS_ThreeSlot = 13,
  ESS_FourSlot = 14,
  ESS_FiveSlot = 15,
  ESS_SixSlot = 16,
  ESS_SevenSlot = 17,
  ESkillSlot_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ESkillSlot_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ESkillSlot_IsValid(int value);
const ESkillSlot ESkillSlot_MIN = ESS_QSlot;
const ESkillSlot ESkillSlot_MAX = ESS_SevenSlot;
const int ESkillSlot_ARRAYSIZE = ESkillSlot_MAX + 1;

const ::google::protobuf::EnumDescriptor* ESkillSlot_descriptor();
inline const ::std::string& ESkillSlot_Name(ESkillSlot value) {
  return ::google::protobuf::internal::NameOfEnum(
    ESkillSlot_descriptor(), value);
}
inline bool ESkillSlot_Parse(
    const ::std::string& name, ESkillSlot* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ESkillSlot>(
    ESkillSlot_descriptor(), name, value);
}
enum ESkillBar {
  ESkillBar_Default = 0,
  ESkillBar_Extra = 1,
  ESkillBar_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ESkillBar_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ESkillBar_IsValid(int value);
const ESkillBar ESkillBar_MIN = ESkillBar_Default;
const ESkillBar ESkillBar_MAX = ESkillBar_Extra;
const int ESkillBar_ARRAYSIZE = ESkillBar_MAX + 1;

const ::google::protobuf::EnumDescriptor* ESkillBar_descriptor();
inline const ::std::string& ESkillBar_Name(ESkillBar value) {
  return ::google::protobuf::internal::NameOfEnum(
    ESkillBar_descriptor(), value);
}
inline bool ESkillBar_Parse(
    const ::std::string& name, ESkillBar* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ESkillBar>(
    ESkillBar_descriptor(), name, value);
}
enum ESkillState {
  ESS_ReadyGo = 0,
  ESS_Preparing = 1,
  ESS_Releasing = 2,
  ESS_Guilding = 3,
  ESS_Lasting = 4,
  ESS_End = 5,
  ESkillState_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ESkillState_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ESkillState_IsValid(int value);
const ESkillState ESkillState_MIN = ESS_ReadyGo;
const ESkillState ESkillState_MAX = ESS_End;
const int ESkillState_ARRAYSIZE = ESkillState_MAX + 1;

const ::google::protobuf::EnumDescriptor* ESkillState_descriptor();
inline const ::std::string& ESkillState_Name(ESkillState value) {
  return ::google::protobuf::internal::NameOfEnum(
    ESkillState_descriptor(), value);
}
inline bool ESkillState_Parse(
    const ::std::string& name, ESkillState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ESkillState>(
    ESkillState_descriptor(), name, value);
}
enum ESkillUseWay {
  ESkillUseWay_SceneUnit = 0,
  ESkillUseWay_Direction = 1,
  ESkillUseWay_Position = 2,
  ESkillUseWay_PosAndDir = 3,
  ESkillUseWay_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ESkillUseWay_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ESkillUseWay_IsValid(int value);
const ESkillUseWay ESkillUseWay_MIN = ESkillUseWay_SceneUnit;
const ESkillUseWay ESkillUseWay_MAX = ESkillUseWay_PosAndDir;
const int ESkillUseWay_ARRAYSIZE = ESkillUseWay_MAX + 1;

const ::google::protobuf::EnumDescriptor* ESkillUseWay_descriptor();
inline const ::std::string& ESkillUseWay_Name(ESkillUseWay value) {
  return ::google::protobuf::internal::NameOfEnum(
    ESkillUseWay_descriptor(), value);
}
inline bool ESkillUseWay_Parse(
    const ::std::string& name, ESkillUseWay* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ESkillUseWay>(
    ESkillUseWay_descriptor(), name, value);
}
enum ESceneUnitRelation {
  ESceneUnitRelation_None = 0,
  ESceneUnitRelation_Self = 1,
  ESceneUnitRelation_Friend = 2,
  ESceneUnitRelation_Enemy = 3,
  ESceneUnitRelation_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ESceneUnitRelation_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ESceneUnitRelation_IsValid(int value);
const ESceneUnitRelation ESceneUnitRelation_MIN = ESceneUnitRelation_None;
const ESceneUnitRelation ESceneUnitRelation_MAX = ESceneUnitRelation_Enemy;
const int ESceneUnitRelation_ARRAYSIZE = ESceneUnitRelation_MAX + 1;

const ::google::protobuf::EnumDescriptor* ESceneUnitRelation_descriptor();
inline const ::std::string& ESceneUnitRelation_Name(ESceneUnitRelation value) {
  return ::google::protobuf::internal::NameOfEnum(
    ESceneUnitRelation_descriptor(), value);
}
inline bool ESceneUnitRelation_Parse(
    const ::std::string& name, ESceneUnitRelation* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ESceneUnitRelation>(
    ESceneUnitRelation_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace NetProto

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::NetProto::EUnitType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::EUnitType>() {
  return ::NetProto::EUnitType_descriptor();
}
template <> struct is_proto_enum< ::NetProto::EMoveAgentState> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::EMoveAgentState>() {
  return ::NetProto::EMoveAgentState_descriptor();
}
template <> struct is_proto_enum< ::NetProto::EMoveState> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::EMoveState>() {
  return ::NetProto::EMoveState_descriptor();
}
template <> struct is_proto_enum< ::NetProto::EPlayerOpera> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::EPlayerOpera>() {
  return ::NetProto::EPlayerOpera_descriptor();
}
template <> struct is_proto_enum< ::NetProto::EFightParam> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::EFightParam>() {
  return ::NetProto::EFightParam_descriptor();
}
template <> struct is_proto_enum< ::NetProto::ESkillSlot> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::ESkillSlot>() {
  return ::NetProto::ESkillSlot_descriptor();
}
template <> struct is_proto_enum< ::NetProto::ESkillBar> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::ESkillBar>() {
  return ::NetProto::ESkillBar_descriptor();
}
template <> struct is_proto_enum< ::NetProto::ESkillState> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::ESkillState>() {
  return ::NetProto::ESkillState_descriptor();
}
template <> struct is_proto_enum< ::NetProto::ESkillUseWay> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::ESkillUseWay>() {
  return ::NetProto::ESkillUseWay_descriptor();
}
template <> struct is_proto_enum< ::NetProto::ESceneUnitRelation> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::NetProto::ESceneUnitRelation>() {
  return ::NetProto::ESceneUnitRelation_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_BattleEnum_2eproto__INCLUDED
