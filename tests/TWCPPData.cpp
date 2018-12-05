#include <TrustWalletCore/TWData.h>
#include <vector>

TWData *_Nonnull TWDataCreateWithBytes(const uint8_t *_Nonnull bytes, size_t size) {
    auto data = new std::vector<uint8_t>(bytes, bytes + size);
    return data;
}

TWData *_Nonnull TWDataCreateWithSize(size_t size) {
    auto data = new std::vector<uint8_t>(size, 0);
    return data;
}

TWData *_Nonnull TWDataCreateWithData(TWData *_Nonnull data) {
    auto other = reinterpret_cast<const std::vector<uint8_t>*>(data);
    auto copy = new std::vector<uint8_t>(*other);
    return copy;
}

size_t TWDataSize(TWData *_Nonnull data) {
    auto v = reinterpret_cast<const std::vector<uint8_t>*>(data);
    return v->size();
}

uint8_t *_Nonnull TWDataBytes(TWData *_Nonnull data) {
    auto v = const_cast<std::vector<uint8_t>*>(reinterpret_cast<const std::vector<uint8_t>*>(data));
    return v->data();
}

void TWDataReleaseBytes(TWData *_Nonnull data, uint8_t *_Nonnull bytes) {
    // Not necessary
}

uint8_t TWDataGet(TWData *_Nonnull data, size_t index) {
    auto v = reinterpret_cast<const std::vector<uint8_t>*>(data);
    return (*v)[index];
}

void TWDataSet(TWData *_Nonnull data, size_t index, uint8_t byte) {
    auto v = const_cast<std::vector<uint8_t>*>(reinterpret_cast<const std::vector<uint8_t>*>(data));
    (*v)[index] = byte;
}

void TWDataCopyBytes(TWData *_Nonnull data, size_t start, size_t size, uint8_t *_Nonnull output) {
    auto v = reinterpret_cast<const std::vector<uint8_t>*>(data);
    std::copy(std::begin(*v) + start, std::begin(*v) + start + size, output);
}

void TWDataReplaceBytes(TWData *_Nonnull data, size_t start, size_t size, const uint8_t *_Nonnull bytes) {
    auto v = const_cast<std::vector<uint8_t>*>(reinterpret_cast<const std::vector<uint8_t>*>(data));
    std::copy(bytes, bytes + size, std::begin(*v) + start);
}

TWData *_Nonnull TWDataAppendBytes(TWData *_Nonnull data, const uint8_t *_Nonnull bytes, size_t size) {
    auto v = const_cast<std::vector<uint8_t>*>(reinterpret_cast<const std::vector<uint8_t>*>(data));
    for (auto i = 0; i < size; i += 1)
        v->push_back(bytes[i]);
    return data;
}

TWData *_Nonnull TWDataAppendByte(TWData *_Nonnull data, uint8_t byte) {
    auto v = const_cast<std::vector<uint8_t>*>(reinterpret_cast<const std::vector<uint8_t>*>(data));
    v->push_back(byte);
    return data;
}

TWData *_Nonnull TWDataAppendData(TWData *_Nonnull data, TWData *_Nonnull append) {
    auto v = const_cast<std::vector<uint8_t>*>(reinterpret_cast<const std::vector<uint8_t>*>(data));
    auto av = reinterpret_cast<const std::vector<uint8_t>*>(append);
    for (auto& b : *av)
        v->push_back(b);
    return data;
}

void TWDataReset(TWData *_Nonnull data) {
    auto v = const_cast<std::vector<uint8_t>*>(reinterpret_cast<const std::vector<uint8_t>*>(data));
    std::fill(std::begin(*v), std::end(*v), 0);
}

void TWDataDelete(TWData *_Nonnull data) {
    auto v = reinterpret_cast<const std::vector<uint8_t>*>(data);
    delete v;
}
