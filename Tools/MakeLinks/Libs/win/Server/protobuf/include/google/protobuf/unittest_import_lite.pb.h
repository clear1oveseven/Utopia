// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_import_lite.proto

#ifndef PROTOBUF_google_2fprotobuf_2funittest_5fimport_5flite_2eproto_INCLUDED
#define PROTOBUF_google_2fprotobuf_2funittest_5fimport_5flite_2eproto_INCLUDED

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
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
#include <google/protobuf/unittest_import_public_lite.pb.h>  // IWYU pragma: export
// @@protoc_insertion_point(includes)

namespace protobuf_google_2fprotobuf_2funittest_5fimport_5flite_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsImportMessageLiteImpl();
void InitDefaultsImportMessageLite();
inline void InitDefaults() {
  InitDefaultsImportMessageLite();
}
}  // namespace protobuf_google_2fprotobuf_2funittest_5fimport_5flite_2eproto
namespace protobuf_unittest_import {
class ImportMessageLite;
class ImportMessageLiteDefaultTypeInternal;
extern ImportMessageLiteDefaultTypeInternal _ImportMessageLite_default_instance_;
}  // namespace protobuf_unittest_import
namespace google {
namespace protobuf {
template<> ::protobuf_unittest_import::ImportMessageLite* Arena::Create< ::protobuf_unittest_import::ImportMessageLite>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace protobuf_unittest_import {

enum ImportEnumLite {
  IMPORT_LITE_FOO = 7,
  IMPORT_LITE_BAR = 8,
  IMPORT_LITE_BAZ = 9
};
bool ImportEnumLite_IsValid(int value);
const ImportEnumLite ImportEnumLite_MIN = IMPORT_LITE_FOO;
const ImportEnumLite ImportEnumLite_MAX = IMPORT_LITE_BAZ;
const int ImportEnumLite_ARRAYSIZE = ImportEnumLite_MAX + 1;

// ===================================================================

class ImportMessageLite : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:protobuf_unittest_import.ImportMessageLite) */ {
 public:
  ImportMessageLite();
  virtual ~ImportMessageLite();

  ImportMessageLite(const ImportMessageLite& from);

  inline ImportMessageLite& operator=(const ImportMessageLite& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ImportMessageLite(ImportMessageLite&& from) noexcept
    : ImportMessageLite() {
    *this = ::std::move(from);
  }

  inline ImportMessageLite& operator=(ImportMessageLite&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::std::string& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::std::string* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ImportMessageLite& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ImportMessageLite* internal_default_instance() {
    return reinterpret_cast<const ImportMessageLite*>(
               &_ImportMessageLite_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ImportMessageLite* other);
  friend void swap(ImportMessageLite& a, ImportMessageLite& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ImportMessageLite* New() const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::Create<ImportMessageLite>(NULL);
  }

  ImportMessageLite* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL {
    return ::google::protobuf::Arena::Create<ImportMessageLite>(arena);
  }
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const ImportMessageLite& from);
  void MergeFrom(const ImportMessageLite& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ImportMessageLite* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 d = 1;
  bool has_d() const;
  void clear_d();
  static const int kDFieldNumber = 1;
  ::google::protobuf::int32 d() const;
  void set_d(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:protobuf_unittest_import.ImportMessageLite)
 private:
  void set_has_d();
  void clear_has_d();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 d_;
  friend struct ::protobuf_google_2fprotobuf_2funittest_5fimport_5flite_2eproto::TableStruct;
  friend void ::protobuf_google_2fprotobuf_2funittest_5fimport_5flite_2eproto::InitDefaultsImportMessageLiteImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ImportMessageLite

// optional int32 d = 1;
inline bool ImportMessageLite::has_d() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ImportMessageLite::set_has_d() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ImportMessageLite::clear_has_d() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ImportMessageLite::clear_d() {
  d_ = 0;
  clear_has_d();
}
inline ::google::protobuf::int32 ImportMessageLite::d() const {
  // @@protoc_insertion_point(field_get:protobuf_unittest_import.ImportMessageLite.d)
  return d_;
}
inline void ImportMessageLite::set_d(::google::protobuf::int32 value) {
  set_has_d();
  d_ = value;
  // @@protoc_insertion_point(field_set:protobuf_unittest_import.ImportMessageLite.d)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf_unittest_import

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::protobuf_unittest_import::ImportEnumLite> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_google_2fprotobuf_2funittest_5fimport_5flite_2eproto_INCLUDED
