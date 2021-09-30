#pragma once

#include <string_view>
#include <set>
#include <stdexcept>
#include <range/v3/view/chunk.hpp>
#include <range/v3/algorithm/for_each.hpp>

namespace day3 {
    using Point = std::pair<int, int>;

    namespace detail {
        auto applyInstruction(auto instruction, Point& pos) {
            switch (instruction) {
                case '>':
                    pos.first += 1;
                    break;
                case '<':
                    pos.first -= 1;
                    break;
                case 'v':
                    pos.second+= 1;
                    break;
                case '^':
                    pos.second -= 1;
                    break;
                default:
                    throw std::runtime_error("input fiasco");
            }
        }
    }
    auto countVisitedHouses(std::string_view input) {
        auto visited = std::set<Point>();

        auto pos = Point(0,0);
        visited.insert(pos);

        for (auto ch : input) {
            detail::applyInstruction(ch, pos);
            visited.insert(pos);
        }

        return visited.size();
    }

    auto countVisitedHousesWithRoboSanta(std::string_view input) {
        auto visited = std::set<Point>();
        auto santa_pos = Point(0,0);
        auto robot_pos = Point(0,0);
        visited.insert(santa_pos);

        ranges::for_each(input | ranges::views::chunk(2), [&](const auto instructions) {
            detail::applyInstruction(instructions[0], santa_pos);
            visited.insert(santa_pos);
            detail::applyInstruction(instructions[1], robot_pos);
            visited.insert(robot_pos);
        });

        return visited.size();
    }
}