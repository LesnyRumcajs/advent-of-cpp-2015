#pragma once

#include <string_view>
#include <string>
#include <map>
#include <regex>

#include <range/v3/view/split.hpp>
#include <range/v3/algorithm/for_each.hpp>
#include <iostream>

namespace day9 {
    using VertexId = std::string;
    using Distance = uint32_t;

    [[nodiscard]] auto calculateMinMaxPath(std::string_view input) -> std::pair<Distance, Distance> {
        auto routes = std::map<std::pair<VertexId, VertexId>, Distance>{};
        auto cities = std::vector<VertexId>{};
        auto regex = std::regex(R"((\w+) to (\w+) = (\d+))");
        ranges::for_each(ranges::views::split(input, '\n'), [&](const auto &line) {
            auto match = std::smatch{};
            auto string_line = std::string(&*line.begin(), static_cast<size_t>(ranges::distance(line)));

            if (std::regex_match(string_line, match, regex)) {
                auto from = match[1];
                auto to = match[2];
                auto distance = std::stoi(match[3]);

                routes.insert({std::make_pair(from, to), distance});
                routes.insert({std::make_pair(to, from), distance});
                cities.emplace_back(from);
                cities.emplace_back(to);
            }
        });

        std::sort(cities.begin(), cities.end());
        cities.erase(std::unique(cities.begin(), cities.end()), cities.end());

        auto min_distance = std::numeric_limits<Distance>::max();
        auto max_distance = std::numeric_limits<Distance>::min();
        do {
            auto path_distance = Distance{};
            for (auto it = cities.begin(); it != cities.end() - 1; ++it) {
                if (auto distance = routes.find(std::make_pair(*it, *(it + 1))); distance != routes.end()) {
                    path_distance += distance->second;
                } else {
                    path_distance = std::numeric_limits<Distance>::max();
                    break;
                }
            }

            min_distance = std::min(min_distance, path_distance);
            max_distance = std::max(max_distance, path_distance);

        } while (std::next_permutation(cities.begin(), cities.end()));

        return {min_distance, max_distance};
    }
}
