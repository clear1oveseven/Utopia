// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_lazy_dependencies_custom_option.proto

#ifndef PROTOBUF_google_2fprotobuf_2funittest_5flazy_5fdependencies_5fcustom_5foption_2eproto_INCLUDED
#define PROTOBUF_google_2fprotobuf_2funittest_5flazy_5fdependencies_5fcustom_5foption_2eproto_INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/unittest_lazy_dependencies_enum.pb.h>
#include <google/protobuf/descriptor.pb.h>
// @@protoc_insertion_point(includes)

namespace protobuf_google_2fprotobuf_2funittest_5flazy_5fdependencies_5fcustom_5foption_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsLazyMessageImpl();
void InitDefaultsLazyMessage();
inline void InitDefaults() {
  InitDefaultsLazyMessage();
}
}  // namespace protobuf_google_2fprotobuf_2funittest_5flazy_5fdependencies_5fcustom_5foption_2eproto
namespace protobuf_unittest {
namespace lazy_imports {
class LazyMessage;
class LazyMessageDefaultTypeInternal;
extern LazyMessageDefaultTypeInternal _LazyMessage_default_instance_;
}  // namespace lazy_imports
}  // namespace protobuf_unittest
namespace google {
namespace protobuf {
template<> ::protobuf_unittest::lazy_imports::LazyMessage* Arena::CreateMessage< ::protobuf_unittest::lazy_imports::LazyMessage>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace protobuf_unittest {
namespace lazy_imports {

// ===================================================================

class LazyMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protobuf_unittest.lazy_imports.LazyMessage) */ {
 public:
  LazyMessage();
  virtual ~LazyMessage();

  LazyMessage(const LazyMessage& from);

  inline LazyMessage& operator=(const LazyMessage& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  LazyMessage(LazyMessage&& from) noexcept
    : LazyMessage() {
    *this = ::std::move(from);
  }

  inline LazyMessage& operator=(LazyMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  inline ::google::protobuf::Arena* GetArena() const PROTOBUF_FINAL {
    return GetArenaNoVirtual();
  }
  inline void* GetMaybeArenaPointer() const PROTOBUF_FINAL {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const LazyMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LazyMessage* internal_default_instance() {
    return reinterpret_cast<const LazyMessage*>(
               &_LazyMessage_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void UnsafeArenaSwap(LazyMessage* other);
  void Swap(LazyMessage* other);
  friend void swap(LazyMessage& a, LazyMessage& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline LazyMessage* New() const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::CreateMessage<LazyMessage>(NULL);
  }

  LazyMessage* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::CreateMessage<LazyMessage>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const LazyMessage& from);
  void MergeFrom(const LazyMessage& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(LazyMessage* other);
  protected:
  explicit LazyMessage(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 a = 1;
  bool has_a() const;
  void clear_a();
  static const int kAFieldNumber = 1;
  ::google::protobuf::int32 a() const;
  void set_a(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protobuf_unittest.lazy_imports.LazyMessage)
 private:
  void set_has_a();
  void clear_has_a();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 a_;
  friend struct ::protobuf_google_2fprotobuf_2funittest_5flazy_5fdependencies_5fcustom_5foption_2eproto::TableStruct;
  friend void ::protobuf_google_2fprotobuf_2funittest_5flazy_5fdependencies_5fcustom_5foption_2eproto::InitDefaultsLazyMessageImpl();
};
// ===================================================================

static const int kLazyEnumOptionFieldNumber = 138596335;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::MessageOptions,
    ::google::protobuf::internal::EnumTypeTraits< ::protobuf_unittest::lazy_imports::LazyEnum, ::protobuf_unittest::lazy_imports::LazyEnum_IsValid>, 14, false >
  lazy_enum_option;

// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// LazyMessage

// optional int32 a = 1;
inline bool LazyMessage::has_a() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LazyMessage::set_has_a() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LazyMessage::clear_has_a() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LazyMessage::clear_a() {
  a_ = 0;
  clear_has_a();
}
inline ::google::protobuf::int32 LazyMessage::a() const {
  // @@protoc_insertion_point(field_get:protobuf_unittest.lazy_imports.LazyMessage.a)
  return a_;
}
inline void LazyMessage::set_a(::google::protobuf::int32 value) {
  set_has_a();
  a_ = value;
  // @@protoc_insertion_point(field_set:protobuf_unittest.lazy_imports.LazyMessage.a)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace lazy_imports
}  // namespace protobuf_unittest

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2fprotobuf_2funittest_5flazy_5fdependencies_5fcustom_5foption_2eproto_INCLUDED
