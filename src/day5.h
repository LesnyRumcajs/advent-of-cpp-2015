#pragma once

#include <range/v3/view/split.hpp>
#include <range/v3/view/remove_if.hpp>

#include <set>

namespace day5 {
    namespace detail {
        auto isVowel(auto ch) {
            return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u';
        }

        auto isBlacklistedSequence(auto ch1, auto ch2) {
            return (ch1 == 'a' && ch2 == 'b') || (ch1 == 'c' && ch2 == 'd') || (ch1 == 'p' && ch2 == 'q') ||
                   (ch1 == 'x' && ch2 == 'y');
        }
    }

    auto isNice(std::string_view word) {
        auto vowelCount{0};
        auto twiceInARow{false};
        for (auto it = word.begin(); it != word.end() - 1; ++it) {
            if (detail::isVowel(*it)) {
                ++vowelCount;
            }

            if (it == word.end() - 2 && detail::isVowel(*(it + 1))) {
                ++vowelCount;
            }

            if (*it == *(it + 1)) {
                twiceInARow = true;
            }

            if (detail::isBlacklistedSequence(*it, *(it + 1))) {
                return false;
            }
        }

        return vowelCount >= 3 && twiceInARow;
    }

    auto isBetterNice(std::string_view word) {
        auto inBetween{false};
        auto pairOfPairs{false};
        std::set<std::string> pairs;
        auto lastPair = std::string{};

        for (auto it = word.begin(); it != word.end() - 2; ++it) {
            if (*it == *(it + 2)) {
                inBetween = true;
            }

            auto currentPair = std::string() + *it + *(it + 1);
            if (currentPair != lastPair) {
                lastPair = currentPair;
                if (auto[_, emplaced] = pairs.emplace(currentPair); !emplaced) {
                    pairOfPairs = true;
                }
            } else {
                lastPair = "";
            }


            if (it == word.end() - 3) {
                auto finalPair = std::string() + *(it + 1) + *(it + 2);
                if (finalPair == lastPair) {
                    break;
                }
                if (auto[_, emplaced] = pairs.emplace(finalPair); !emplaced) {
                    pairOfPairs = true;
                }
            }
        }

        return inBetween && pairOfPairs;
    }

    auto countNice(std::string_view input) {
        return ranges::distance(ranges::views::split(input, '\n') | ranges::views::remove_if([](const auto &word) {
            return !isNice({&*word.begin(), static_cast<size_t>(ranges::distance(word))});
        }));
    }

    auto countBetterNice(std::string_view input) {
        return ranges::distance(ranges::views::split(input, '\n') | ranges::views::remove_if([](const auto &word) {
            return !isBetterNice({&*word.begin(), static_cast<size_t>(ranges::distance(word))});
        }));
    }
}