#pragma once

#include <string_view>
#include <string>
#include <optional>

namespace day11 {
    [[nodiscard]] auto createNextSecurePassword(std::string_view password) -> std::string {
        auto currentPassword = std::string{password};
        auto isSecure = [](const auto &password) {
            auto hasTriplet = false;
            auto pairsCount = 0;
            auto lastPair = std::optional<decltype(password.begin())>{};

            for (auto it = password.begin(); it != password.end(); ++it) {
                if (*it == 'i' || *it == 'o' || *it == 'l') {
                    return false;
                }

                if (!hasTriplet && it < password.end() - 2 && *(it + 1) == *it + 1 && *(it + 2) == *it + 2) {
                    hasTriplet = true;
                }

                if (pairsCount < 2 && (!lastPair || it > lastPair) && it < password.end() - 1 &&
                    *it == *(it + 1)) {
                    ++pairsCount;
                    lastPair = it + 1;
                }
            }
            return hasTriplet && pairsCount == 2;
        };

        auto generateNext = [](auto &password) {
            for (auto it = password.rbegin(); it != password.rend(); ++it) {
                if (*it != 'z') {
                    (*it)++;
                    break;
                } else {
                    *it = 'a';
                }
            }
        };

        do {
            generateNext(currentPassword);
        } while (!isSecure(currentPassword));

        return currentPassword;
    }
}
