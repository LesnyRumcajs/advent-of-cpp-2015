#pragma once

#include <range/v3/view.hpp>
#include <range/v3/action.hpp>

namespace day2 {
namespace detail {
[[nodiscard]] auto extractDimensions(std::string entry) -> std::vector<int> {
        return ranges::views::split(entry, 'x') | ranges::views::transform([](const auto& item){
            return std::stoi(std::string(&*item.begin(), ranges::distance(item)));
        }) | ranges::to<std::vector<int>>() | ranges::actions::sort;
    }
}

[[nodiscard]] auto calculatePackagePaper(std::string input) {
    auto result = 0;
    std::istringstream input_stream(input);
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

[[nodiscard]] auto calculateRibbon(std::string input) {
    auto result = 0;
    std::istringstream input_stream(input);
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