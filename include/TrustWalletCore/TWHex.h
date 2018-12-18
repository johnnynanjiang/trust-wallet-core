#pragma once

#include <string>

namespace TW {
    template<typename T>
    std::string hex(const T& data) {
        static const char* const table = "0123456789abcdef";
        auto string = std::string{};
        
        for (uint8_t byte : data) {
            string.push_back(table[byte >> 4]);
            string.push_back(table[byte & 0x0f]);
        }

        return string;
    }
}
