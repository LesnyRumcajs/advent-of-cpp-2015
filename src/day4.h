#pragma once

#include <botan/hash.h>
#include <string>

namespace day4 {
    auto mineAdventCoin(const std::string &key, bool extended) -> int {
        auto md5_hasher = Botan::HashFunction::create("MD5");

        auto third_byte_mask = extended ? 0xFF : 0xF0;
        auto result = 0;
        while (true) {
            md5_hasher->update(key + std::to_string(result));
            auto digest = md5_hasher->final();
            if (digest[0] == 0x00 && digest[1] == 0x00 && (digest[2] & third_byte_mask) == 0x00) {
                return result;
            }
            ++result;
        };
    }
}