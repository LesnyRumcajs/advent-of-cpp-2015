#pragma once

#include <string_view>

#include <range/v3/view.hpp>
#include <range/v3/action.hpp>

namespace day2 {
    namespace detail {
        [[nodiscard]] auto extractDimensions(std::string_view entry) -> std::vector<int> {
            return ranges::views::split(entry, 'x')
                   | ranges::views::transform([](const auto &item) {
                return std::atoi(&*item.begin());
            })
                   | ranges::to<std::vector<int>>() | ranges::actions::sort;
        }
    }

    [[nodiscard]] auto calculatePackagePaper(std::string_view input) {
        auto result = 0;
        std::istringstream input_stream(input.data());
        std::string entry;
        while (std::getline(input_stream, entry)) {
            auto dimensions = detail::extractDimensions(entry);
            result += 2 * dimensions[0] * dimensions[1] +
                      2 * dimensions[0] * dimensions[2] +
                      2 * dimensions[1] * dimensions[2] +
                      dimensions[0] * dimensions[1];
        }

        return result;
    }

    [[nodiscard]] auto calculateRibbon(std::string_view input) {
        auto result = 0;
        std::istringstream input_stream(input.data());
        std::string entry;
        while (std::getline(input_stream, entry)) {
            auto dimensions = detail::extractDimensions(entry);
            result += 2 * dimensions[0] +
                      2 * dimensions[1] +
                      dimensions[0] * dimensions[1] * dimensions[2];
        }

        return result;
    }
}