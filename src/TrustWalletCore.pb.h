// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TrustWalletCore.proto

#ifndef PROTOBUF_INCLUDED_TrustWalletCore_2eproto
#define PROTOBUF_INCLUDED_TrustWalletCore_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry_lite.h>
#include <google/protobuf/map_field_lite.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_TrustWalletCore_2eproto 

namespace protobuf_TrustWalletCore_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
}  // namespace protobuf_TrustWalletCore_2eproto
namespace TW {
namespace proto {
class BitcoinOutPoint;
class BitcoinOutPointDefaultTypeInternal;
extern BitcoinOutPointDefaultTypeInternal _BitcoinOutPoint_default_instance_;
class BitcoinSigningInput;
class BitcoinSigningInputDefaultTypeInternal;
extern BitcoinSigningInputDefaultTypeInternal _BitcoinSigningInput_default_instance_;
class BitcoinSigningInput_ScriptsEntry_DoNotUse;
class BitcoinSigningInput_ScriptsEntry_DoNotUseDefaultTypeInternal;
extern BitcoinSigningInput_ScriptsEntry_DoNotUseDefaultTypeInternal _BitcoinSigningInput_ScriptsEntry_DoNotUse_default_instance_;
class BitcoinUnspentTransaction;
class BitcoinUnspentTransactionDefaultTypeInternal;
extern BitcoinUnspentTransactionDefaultTypeInternal _BitcoinUnspentTransaction_default_instance_;
}  // namespace proto
}  // namespace TW
namespace google {
namespace protobuf {
template<> ::TW::proto::BitcoinOutPoint* Arena::CreateMaybeMessage<::TW::proto::BitcoinOutPoint>(Arena*);
template<> ::TW::proto::BitcoinSigningInput* Arena::CreateMaybeMessage<::TW::proto::BitcoinSigningInput>(Arena*);
template<> ::TW::proto::BitcoinSigningInput_ScriptsEntry_DoNotUse* Arena::CreateMaybeMessage<::TW::proto::BitcoinSigningInput_ScriptsEntry_DoNotUse>(Arena*);
template<> ::TW::proto::BitcoinUnspentTransaction* Arena::CreateMaybeMessage<::TW::proto::BitcoinUnspentTransaction>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace TW {
namespace proto {

// ===================================================================

class BitcoinOutPoint : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:TW.proto.BitcoinOutPoint) */ {
 public:
  BitcoinOutPoint();
  virtual ~BitcoinOutPoint();

  BitcoinOutPoint(const BitcoinOutPoint& from);

  inline BitcoinOutPoint& operator=(const BitcoinOutPoint& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BitcoinOutPoint(BitcoinOutPoint&& from) noexcept
    : BitcoinOutPoint() {
    *this = ::std::move(from);
  }

  inline BitcoinOutPoint& operator=(BitcoinOutPoint&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const BitcoinOutPoint& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BitcoinOutPoint* internal_default_instance() {
    return reinterpret_cast<const BitcoinOutPoint*>(
               &_BitcoinOutPoint_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(BitcoinOutPoint* other);
  friend void swap(BitcoinOutPoint& a, BitcoinOutPoint& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BitcoinOutPoint* New() const final {
    return CreateMaybeMessage<BitcoinOutPoint>(NULL);
  }

  BitcoinOutPoint* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<BitcoinOutPoint>(arena);
  }
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    final;
  void CopyFrom(const BitcoinOutPoint& from);
  void MergeFrom(const BitcoinOutPoint& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(BitcoinOutPoint* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes hash = 1;
  void clear_hash();
  static const int kHashFieldNumber = 1;
  const ::std::string& hash() const;
  void set_hash(const ::std::string& value);
  #if LANG_CXX11
  void set_hash(::std::string&& value);
  #endif
  void set_hash(const char* value);
  void set_hash(const void* value, size_t size);
  ::std::string* mutable_hash();
  ::std::string* release_hash();
  void set_allocated_hash(::std::string* hash);

  // uint32 index = 2;
  void clear_index();
  static const int kIndexFieldNumber = 2;
  ::google::protobuf::uint32 index() const;
  void set_index(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:TW.proto.BitcoinOutPoint)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr hash_;
  ::google::protobuf::uint32 index_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_TrustWalletCore_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class BitcoinUnspentTransaction : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:TW.proto.BitcoinUnspentTransaction) */ {
 public:
  BitcoinUnspentTransaction();
  virtual ~BitcoinUnspentTransaction();

  BitcoinUnspentTransaction(const BitcoinUnspentTransaction& from);

  inline BitcoinUnspentTransaction& operator=(const BitcoinUnspentTransaction& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BitcoinUnspentTransaction(BitcoinUnspentTransaction&& from) noexcept
    : BitcoinUnspentTransaction() {
    *this = ::std::move(from);
  }

  inline BitcoinUnspentTransaction& operator=(BitcoinUnspentTransaction&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const BitcoinUnspentTransaction& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BitcoinUnspentTransaction* internal_default_instance() {
    return reinterpret_cast<const BitcoinUnspentTransaction*>(
               &_BitcoinUnspentTransaction_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(BitcoinUnspentTransaction* other);
  friend void swap(BitcoinUnspentTransaction& a, BitcoinUnspentTransaction& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BitcoinUnspentTransaction* New() const final {
    return CreateMaybeMessage<BitcoinUnspentTransaction>(NULL);
  }

  BitcoinUnspentTransaction* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<BitcoinUnspentTransaction>(arena);
  }
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    final;
  void CopyFrom(const BitcoinUnspentTransaction& from);
  void MergeFrom(const BitcoinUnspentTransaction& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(BitcoinUnspentTransaction* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes script = 2;
  void clear_script();
  static const int kScriptFieldNumber = 2;
  const ::std::string& script() const;
  void set_script(const ::std::string& value);
  #if LANG_CXX11
  void set_script(::std::string&& value);
  #endif
  void set_script(const char* value);
  void set_script(const void* value, size_t size);
  ::std::string* mutable_script();
  ::std::string* release_script();
  void set_allocated_script(::std::string* script);

  // .TW.proto.BitcoinOutPoint out_point = 1;
  bool has_out_point() const;
  void clear_out_point();
  static const int kOutPointFieldNumber = 1;
  private:
  const ::TW::proto::BitcoinOutPoint& _internal_out_point() const;
  public:
  const ::TW::proto::BitcoinOutPoint& out_point() const;
  ::TW::proto::BitcoinOutPoint* release_out_point();
  ::TW::proto::BitcoinOutPoint* mutable_out_point();
  void set_allocated_out_point(::TW::proto::BitcoinOutPoint* out_point);

  // int64 amount = 3;
  void clear_amount();
  static const int kAmountFieldNumber = 3;
  ::google::protobuf::int64 amount() const;
  void set_amount(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:TW.proto.BitcoinUnspentTransaction)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr script_;
  ::TW::proto::BitcoinOutPoint* out_point_;
  ::google::protobuf::int64 amount_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_TrustWalletCore_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class BitcoinSigningInput_ScriptsEntry_DoNotUse : public ::google::protobuf::internal::MapEntryLite<BitcoinSigningInput_ScriptsEntry_DoNotUse, 
    ::std::string, ::std::string,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    ::google::protobuf::internal::WireFormatLite::TYPE_BYTES,
    0 > {
public:
  typedef ::google::protobuf::internal::MapEntryLite<BitcoinSigningInput_ScriptsEntry_DoNotUse, 
    ::std::string, ::std::string,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    ::google::protobuf::internal::WireFormatLite::TYPE_BYTES,
    0 > SuperType;
  BitcoinSigningInput_ScriptsEntry_DoNotUse();
  BitcoinSigningInput_ScriptsEntry_DoNotUse(::google::protobuf::Arena* arena);
  void MergeFrom(const BitcoinSigningInput_ScriptsEntry_DoNotUse& other);
  static const BitcoinSigningInput_ScriptsEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const BitcoinSigningInput_ScriptsEntry_DoNotUse*>(&_BitcoinSigningInput_ScriptsEntry_DoNotUse_default_instance_); }
};

// -------------------------------------------------------------------

class BitcoinSigningInput : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:TW.proto.BitcoinSigningInput) */ {
 public:
  BitcoinSigningInput();
  virtual ~BitcoinSigningInput();

  BitcoinSigningInput(const BitcoinSigningInput& from);

  inline BitcoinSigningInput& operator=(const BitcoinSigningInput& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BitcoinSigningInput(BitcoinSigningInput&& from) noexcept
    : BitcoinSigningInput() {
    *this = ::std::move(from);
  }

  inline BitcoinSigningInput& operator=(BitcoinSigningInput&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const BitcoinSigningInput& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BitcoinSigningInput* internal_default_instance() {
    return reinterpret_cast<const BitcoinSigningInput*>(
               &_BitcoinSigningInput_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(BitcoinSigningInput* other);
  friend void swap(BitcoinSigningInput& a, BitcoinSigningInput& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BitcoinSigningInput* New() const final {
    return CreateMaybeMessage<BitcoinSigningInput>(NULL);
  }

  BitcoinSigningInput* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<BitcoinSigningInput>(arena);
  }
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    final;
  void CopyFrom(const BitcoinSigningInput& from);
  void MergeFrom(const BitcoinSigningInput& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(BitcoinSigningInput* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const final;

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  // repeated bytes private_key = 10;
  int private_key_size() const;
  void clear_private_key();
  static const int kPrivateKeyFieldNumber = 10;
  const ::std::string& private_key(int index) const;
  ::std::string* mutable_private_key(int index);
  void set_private_key(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_private_key(int index, ::std::string&& value);
  #endif
  void set_private_key(int index, const char* value);
  void set_private_key(int index, const void* value, size_t size);
  ::std::string* add_private_key();
  void add_private_key(const ::std::string& value);
  #if LANG_CXX11
  void add_private_key(::std::string&& value);
  #endif
  void add_private_key(const char* value);
  void add_private_key(const void* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& private_key() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_private_key();

  // map<string, bytes> scripts = 11;
  int scripts_size() const;
  void clear_scripts();
  static const int kScriptsFieldNumber = 11;
  const ::google::protobuf::Map< ::std::string, ::std::string >&
      scripts() const;
  ::google::protobuf::Map< ::std::string, ::std::string >*
      mutable_scripts();

  // repeated .TW.proto.BitcoinUnspentTransaction utxo = 12;
  int utxo_size() const;
  void clear_utxo();
  static const int kUtxoFieldNumber = 12;
  ::TW::proto::BitcoinUnspentTransaction* mutable_utxo(int index);
  ::google::protobuf::RepeatedPtrField< ::TW::proto::BitcoinUnspentTransaction >*
      mutable_utxo();
  const ::TW::proto::BitcoinUnspentTransaction& utxo(int index) const;
  ::TW::proto::BitcoinUnspentTransaction* add_utxo();
  const ::google::protobuf::RepeatedPtrField< ::TW::proto::BitcoinUnspentTransaction >&
      utxo() const;

  // string to_address = 3;
  void clear_to_address();
  static const int kToAddressFieldNumber = 3;
  const ::std::string& to_address() const;
  void set_to_address(const ::std::string& value);
  #if LANG_CXX11
  void set_to_address(::std::string&& value);
  #endif
  void set_to_address(const char* value);
  void set_to_address(const char* value, size_t size);
  ::std::string* mutable_to_address();
  ::std::string* release_to_address();
  void set_allocated_to_address(::std::string* to_address);

  // string change_address = 4;
  void clear_change_address();
  static const int kChangeAddressFieldNumber = 4;
  const ::std::string& change_address() const;
  void set_change_address(const ::std::string& value);
  #if LANG_CXX11
  void set_change_address(::std::string&& value);
  #endif
  void set_change_address(const char* value);
  void set_change_address(const char* value, size_t size);
  ::std::string* mutable_change_address();
  ::std::string* release_change_address();
  void set_allocated_change_address(::std::string* change_address);

  // int64 amount = 2;
  void clear_amount();
  static const int kAmountFieldNumber = 2;
  ::google::protobuf::int64 amount() const;
  void set_amount(::google::protobuf::int64 value);

  // uint32 hash_type = 1;
  void clear_hash_type();
  static const int kHashTypeFieldNumber = 1;
  ::google::protobuf::uint32 hash_type() const;
  void set_hash_type(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:TW.proto.BitcoinSigningInput)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::std::string> private_key_;
  ::google::protobuf::internal::MapFieldLite<
      BitcoinSigningInput_ScriptsEntry_DoNotUse,
      ::std::string, ::std::string,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      ::google::protobuf::internal::WireFormatLite::TYPE_BYTES,
      0 > scripts_;
  ::google::protobuf::RepeatedPtrField< ::TW::proto::BitcoinUnspentTransaction > utxo_;
  ::google::protobuf::internal::ArenaStringPtr to_address_;
  ::google::protobuf::internal::ArenaStringPtr change_address_;
  ::google::protobuf::int64 amount_;
  ::google::protobuf::uint32 hash_type_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_TrustWalletCore_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BitcoinOutPoint

// bytes hash = 1;
inline void BitcoinOutPoint::clear_hash() {
  hash_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BitcoinOutPoint::hash() const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinOutPoint.hash)
  return hash_.GetNoArena();
}
inline void BitcoinOutPoint::set_hash(const ::std::string& value) {
  
  hash_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinOutPoint.hash)
}
#if LANG_CXX11
inline void BitcoinOutPoint::set_hash(::std::string&& value) {
  
  hash_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:TW.proto.BitcoinOutPoint.hash)
}
#endif
inline void BitcoinOutPoint::set_hash(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  hash_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:TW.proto.BitcoinOutPoint.hash)
}
inline void BitcoinOutPoint::set_hash(const void* value, size_t size) {
  
  hash_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:TW.proto.BitcoinOutPoint.hash)
}
inline ::std::string* BitcoinOutPoint::mutable_hash() {
  
  // @@protoc_insertion_point(field_mutable:TW.proto.BitcoinOutPoint.hash)
  return hash_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BitcoinOutPoint::release_hash() {
  // @@protoc_insertion_point(field_release:TW.proto.BitcoinOutPoint.hash)
  
  return hash_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BitcoinOutPoint::set_allocated_hash(::std::string* hash) {
  if (hash != NULL) {
    
  } else {
    
  }
  hash_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), hash);
  // @@protoc_insertion_point(field_set_allocated:TW.proto.BitcoinOutPoint.hash)
}

// uint32 index = 2;
inline void BitcoinOutPoint::clear_index() {
  index_ = 0u;
}
inline ::google::protobuf::uint32 BitcoinOutPoint::index() const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinOutPoint.index)
  return index_;
}
inline void BitcoinOutPoint::set_index(::google::protobuf::uint32 value) {
  
  index_ = value;
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinOutPoint.index)
}

// -------------------------------------------------------------------

// BitcoinUnspentTransaction

// .TW.proto.BitcoinOutPoint out_point = 1;
inline bool BitcoinUnspentTransaction::has_out_point() const {
  return this != internal_default_instance() && out_point_ != NULL;
}
inline void BitcoinUnspentTransaction::clear_out_point() {
  if (GetArenaNoVirtual() == NULL && out_point_ != NULL) {
    delete out_point_;
  }
  out_point_ = NULL;
}
inline const ::TW::proto::BitcoinOutPoint& BitcoinUnspentTransaction::_internal_out_point() const {
  return *out_point_;
}
inline const ::TW::proto::BitcoinOutPoint& BitcoinUnspentTransaction::out_point() const {
  const ::TW::proto::BitcoinOutPoint* p = out_point_;
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinUnspentTransaction.out_point)
  return p != NULL ? *p : *reinterpret_cast<const ::TW::proto::BitcoinOutPoint*>(
      &::TW::proto::_BitcoinOutPoint_default_instance_);
}
inline ::TW::proto::BitcoinOutPoint* BitcoinUnspentTransaction::release_out_point() {
  // @@protoc_insertion_point(field_release:TW.proto.BitcoinUnspentTransaction.out_point)
  
  ::TW::proto::BitcoinOutPoint* temp = out_point_;
  out_point_ = NULL;
  return temp;
}
inline ::TW::proto::BitcoinOutPoint* BitcoinUnspentTransaction::mutable_out_point() {
  
  if (out_point_ == NULL) {
    auto* p = CreateMaybeMessage<::TW::proto::BitcoinOutPoint>(GetArenaNoVirtual());
    out_point_ = p;
  }
  // @@protoc_insertion_point(field_mutable:TW.proto.BitcoinUnspentTransaction.out_point)
  return out_point_;
}
inline void BitcoinUnspentTransaction::set_allocated_out_point(::TW::proto::BitcoinOutPoint* out_point) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete out_point_;
  }
  if (out_point) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      out_point = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, out_point, submessage_arena);
    }
    
  } else {
    
  }
  out_point_ = out_point;
  // @@protoc_insertion_point(field_set_allocated:TW.proto.BitcoinUnspentTransaction.out_point)
}

// bytes script = 2;
inline void BitcoinUnspentTransaction::clear_script() {
  script_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BitcoinUnspentTransaction::script() const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinUnspentTransaction.script)
  return script_.GetNoArena();
}
inline void BitcoinUnspentTransaction::set_script(const ::std::string& value) {
  
  script_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinUnspentTransaction.script)
}
#if LANG_CXX11
inline void BitcoinUnspentTransaction::set_script(::std::string&& value) {
  
  script_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:TW.proto.BitcoinUnspentTransaction.script)
}
#endif
inline void BitcoinUnspentTransaction::set_script(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  script_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:TW.proto.BitcoinUnspentTransaction.script)
}
inline void BitcoinUnspentTransaction::set_script(const void* value, size_t size) {
  
  script_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:TW.proto.BitcoinUnspentTransaction.script)
}
inline ::std::string* BitcoinUnspentTransaction::mutable_script() {
  
  // @@protoc_insertion_point(field_mutable:TW.proto.BitcoinUnspentTransaction.script)
  return script_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BitcoinUnspentTransaction::release_script() {
  // @@protoc_insertion_point(field_release:TW.proto.BitcoinUnspentTransaction.script)
  
  return script_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BitcoinUnspentTransaction::set_allocated_script(::std::string* script) {
  if (script != NULL) {
    
  } else {
    
  }
  script_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), script);
  // @@protoc_insertion_point(field_set_allocated:TW.proto.BitcoinUnspentTransaction.script)
}

// int64 amount = 3;
inline void BitcoinUnspentTransaction::clear_amount() {
  amount_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 BitcoinUnspentTransaction::amount() const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinUnspentTransaction.amount)
  return amount_;
}
inline void BitcoinUnspentTransaction::set_amount(::google::protobuf::int64 value) {
  
  amount_ = value;
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinUnspentTransaction.amount)
}

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// BitcoinSigningInput

// uint32 hash_type = 1;
inline void BitcoinSigningInput::clear_hash_type() {
  hash_type_ = 0u;
}
inline ::google::protobuf::uint32 BitcoinSigningInput::hash_type() const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinSigningInput.hash_type)
  return hash_type_;
}
inline void BitcoinSigningInput::set_hash_type(::google::protobuf::uint32 value) {
  
  hash_type_ = value;
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinSigningInput.hash_type)
}

// int64 amount = 2;
inline void BitcoinSigningInput::clear_amount() {
  amount_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 BitcoinSigningInput::amount() const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinSigningInput.amount)
  return amount_;
}
inline void BitcoinSigningInput::set_amount(::google::protobuf::int64 value) {
  
  amount_ = value;
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinSigningInput.amount)
}

// string to_address = 3;
inline void BitcoinSigningInput::clear_to_address() {
  to_address_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BitcoinSigningInput::to_address() const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinSigningInput.to_address)
  return to_address_.GetNoArena();
}
inline void BitcoinSigningInput::set_to_address(const ::std::string& value) {
  
  to_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinSigningInput.to_address)
}
#if LANG_CXX11
inline void BitcoinSigningInput::set_to_address(::std::string&& value) {
  
  to_address_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:TW.proto.BitcoinSigningInput.to_address)
}
#endif
inline void BitcoinSigningInput::set_to_address(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  to_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:TW.proto.BitcoinSigningInput.to_address)
}
inline void BitcoinSigningInput::set_to_address(const char* value, size_t size) {
  
  to_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:TW.proto.BitcoinSigningInput.to_address)
}
inline ::std::string* BitcoinSigningInput::mutable_to_address() {
  
  // @@protoc_insertion_point(field_mutable:TW.proto.BitcoinSigningInput.to_address)
  return to_address_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BitcoinSigningInput::release_to_address() {
  // @@protoc_insertion_point(field_release:TW.proto.BitcoinSigningInput.to_address)
  
  return to_address_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BitcoinSigningInput::set_allocated_to_address(::std::string* to_address) {
  if (to_address != NULL) {
    
  } else {
    
  }
  to_address_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), to_address);
  // @@protoc_insertion_point(field_set_allocated:TW.proto.BitcoinSigningInput.to_address)
}

// string change_address = 4;
inline void BitcoinSigningInput::clear_change_address() {
  change_address_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BitcoinSigningInput::change_address() const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinSigningInput.change_address)
  return change_address_.GetNoArena();
}
inline void BitcoinSigningInput::set_change_address(const ::std::string& value) {
  
  change_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinSigningInput.change_address)
}
#if LANG_CXX11
inline void BitcoinSigningInput::set_change_address(::std::string&& value) {
  
  change_address_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:TW.proto.BitcoinSigningInput.change_address)
}
#endif
inline void BitcoinSigningInput::set_change_address(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  change_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:TW.proto.BitcoinSigningInput.change_address)
}
inline void BitcoinSigningInput::set_change_address(const char* value, size_t size) {
  
  change_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:TW.proto.BitcoinSigningInput.change_address)
}
inline ::std::string* BitcoinSigningInput::mutable_change_address() {
  
  // @@protoc_insertion_point(field_mutable:TW.proto.BitcoinSigningInput.change_address)
  return change_address_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BitcoinSigningInput::release_change_address() {
  // @@protoc_insertion_point(field_release:TW.proto.BitcoinSigningInput.change_address)
  
  return change_address_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BitcoinSigningInput::set_allocated_change_address(::std::string* change_address) {
  if (change_address != NULL) {
    
  } else {
    
  }
  change_address_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), change_address);
  // @@protoc_insertion_point(field_set_allocated:TW.proto.BitcoinSigningInput.change_address)
}

// repeated bytes private_key = 10;
inline int BitcoinSigningInput::private_key_size() const {
  return private_key_.size();
}
inline void BitcoinSigningInput::clear_private_key() {
  private_key_.Clear();
}
inline const ::std::string& BitcoinSigningInput::private_key(int index) const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinSigningInput.private_key)
  return private_key_.Get(index);
}
inline ::std::string* BitcoinSigningInput::mutable_private_key(int index) {
  // @@protoc_insertion_point(field_mutable:TW.proto.BitcoinSigningInput.private_key)
  return private_key_.Mutable(index);
}
inline void BitcoinSigningInput::set_private_key(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinSigningInput.private_key)
  private_key_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void BitcoinSigningInput::set_private_key(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:TW.proto.BitcoinSigningInput.private_key)
  private_key_.Mutable(index)->assign(std::move(value));
}
#endif
inline void BitcoinSigningInput::set_private_key(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  private_key_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:TW.proto.BitcoinSigningInput.private_key)
}
inline void BitcoinSigningInput::set_private_key(int index, const void* value, size_t size) {
  private_key_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:TW.proto.BitcoinSigningInput.private_key)
}
inline ::std::string* BitcoinSigningInput::add_private_key() {
  // @@protoc_insertion_point(field_add_mutable:TW.proto.BitcoinSigningInput.private_key)
  return private_key_.Add();
}
inline void BitcoinSigningInput::add_private_key(const ::std::string& value) {
  private_key_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:TW.proto.BitcoinSigningInput.private_key)
}
#if LANG_CXX11
inline void BitcoinSigningInput::add_private_key(::std::string&& value) {
  private_key_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:TW.proto.BitcoinSigningInput.private_key)
}
#endif
inline void BitcoinSigningInput::add_private_key(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  private_key_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:TW.proto.BitcoinSigningInput.private_key)
}
inline void BitcoinSigningInput::add_private_key(const void* value, size_t size) {
  private_key_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:TW.proto.BitcoinSigningInput.private_key)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
BitcoinSigningInput::private_key() const {
  // @@protoc_insertion_point(field_list:TW.proto.BitcoinSigningInput.private_key)
  return private_key_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
BitcoinSigningInput::mutable_private_key() {
  // @@protoc_insertion_point(field_mutable_list:TW.proto.BitcoinSigningInput.private_key)
  return &private_key_;
}

// map<string, bytes> scripts = 11;
inline int BitcoinSigningInput::scripts_size() const {
  return scripts_.size();
}
inline void BitcoinSigningInput::clear_scripts() {
  scripts_.Clear();
}
inline const ::google::protobuf::Map< ::std::string, ::std::string >&
BitcoinSigningInput::scripts() const {
  // @@protoc_insertion_point(field_map:TW.proto.BitcoinSigningInput.scripts)
  return scripts_.GetMap();
}
inline ::google::protobuf::Map< ::std::string, ::std::string >*
BitcoinSigningInput::mutable_scripts() {
  // @@protoc_insertion_point(field_mutable_map:TW.proto.BitcoinSigningInput.scripts)
  return scripts_.MutableMap();
}

// repeated .TW.proto.BitcoinUnspentTransaction utxo = 12;
inline int BitcoinSigningInput::utxo_size() const {
  return utxo_.size();
}
inline void BitcoinSigningInput::clear_utxo() {
  utxo_.Clear();
}
inline ::TW::proto::BitcoinUnspentTransaction* BitcoinSigningInput::mutable_utxo(int index) {
  // @@protoc_insertion_point(field_mutable:TW.proto.BitcoinSigningInput.utxo)
  return utxo_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::TW::proto::BitcoinUnspentTransaction >*
BitcoinSigningInput::mutable_utxo() {
  // @@protoc_insertion_point(field_mutable_list:TW.proto.BitcoinSigningInput.utxo)
  return &utxo_;
}
inline const ::TW::proto::BitcoinUnspentTransaction& BitcoinSigningInput::utxo(int index) const {
  // @@protoc_insertion_point(field_get:TW.proto.BitcoinSigningInput.utxo)
  return utxo_.Get(index);
}
inline ::TW::proto::BitcoinUnspentTransaction* BitcoinSigningInput::add_utxo() {
  // @@protoc_insertion_point(field_add:TW.proto.BitcoinSigningInput.utxo)
  return utxo_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::TW::proto::BitcoinUnspentTransaction >&
BitcoinSigningInput::utxo() const {
  // @@protoc_insertion_point(field_list:TW.proto.BitcoinSigningInput.utxo)
  return utxo_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace TW

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_TrustWalletCore_2eproto