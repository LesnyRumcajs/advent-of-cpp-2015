#pragma once

#include <vector>
#include <string_view>
#include <numeric>
#include <range/v3/view/split.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/algorithm/for_each.hpp>
#include <regex>

namespace day6 {
    struct Point {
        int x;
        int y;
    };

    enum class Action {
        turn_on,
        turn_off,
        toggle
    };

    class Instruction {
    public:
        explicit Instruction(std::string_view instruction) {
            auto regex = std::regex(R"((turn on|turn off|toggle) (\d+),(\d+) through (\d+),(\d+))");
            auto match = std::smatch{};

            auto string_instruction = std::string(instruction);
            if (std::regex_match(string_instruction, match, regex)) {
                if (match[1] == "turn off") {
                    action = Action::turn_off;
                } else if (match[1] == "turn on") {
                    action = Action::turn_on;
                } else if (match[1] == "toggle") {
                    action = Action::toggle;
                }

                begin = Point{
                        .x = std::stoi(match[2]),
                        .y = std::stoi(match[3])
                };

                end = Point{
                        .x = std::stoi(match[4]),
                        .y = std::stoi(match[5])
                };
            } else {
                throw std::runtime_error("not matched!");
            }
        }

        [[nodiscard]] auto getAction() const noexcept {
            return action;
        }

        [[nodiscard]] const auto &getBeginPoint() const noexcept {
            return begin;
        }

        [[nodiscard]] const auto &getEndPoint() const noexcept {
            return end;
        }

    private:
        Action action;
        Point begin{};
        Point end{};
    };

    class LightGrid {
    public:
        void applyInstruction(const Instruction &instruction) {
            for (auto column = instruction.getBeginPoint().y; column <= instruction.getEndPoint().y; ++column) {
                for (auto row = instruction.getBeginPoint().x; row <= instruction.getEndPoint().x; ++row) {
                    switch (instruction.getAction()) {
                        case Action::toggle: {
                            grid[column][row] = !grid[column][row];
                            break;
                        }
                        case Action::turn_on: {
                            grid[column][row] = 1;
                            break;
                        }
                        case Action::turn_off: {
                            grid[column][row] = 0;
                        }
                    }
                }
            }
        }

        void applyModernInstruction(const Instruction &instruction) {
            for (auto column = instruction.getBeginPoint().y; column <= instruction.getEndPoint().y; ++column) {
                for (auto row = instruction.getBeginPoint().x; row <= instruction.getEndPoint().x; ++row) {
                    switch (instruction.getAction()) {
                        case Action::toggle: {
                            grid[column][row] += 2;
                            break;
                        }
                        case Action::turn_on: {
                            grid[column][row] += 1;
                            break;
                        }
                        case Action::turn_off: {
                            grid[column][row] = std::max(grid[column][row] - 1, 0);
                            break;
                        }
                    }
                }
            }
        }

        auto countLit() -> std::size_t {
            return std::accumulate(grid.begin(), grid.end(), 0, [](auto sum, auto row) {
                return sum + std::accumulate(row.begin(), row.end(), 0, [](auto sum, auto column) {
                    return sum + column;
                });
            });
        }

    private:
        static constexpr auto GRID_SIZE = 1000;
        std::array<std::array<int, GRID_SIZE>, GRID_SIZE> grid = {};
    };

    auto countLitLights(std::string_view input) {
        auto grid = LightGrid{};

        ranges::for_each(ranges::views::split(input, '\n') | ranges::views::transform([](const auto &instruction) {
            return Instruction({&*instruction.begin(), static_cast<size_t>(ranges::distance(instruction))});
        }), [&grid](const auto &instruction) {
            grid.applyInstruction(instruction);
        });

        return grid.countLit();
    }

    auto countLitLightsModern(std::string_view input) {
        auto grid = LightGrid{};

        ranges::for_each(ranges::views::split(input, '\n') | ranges::views::transform([](const auto &instruction) {
            return Instruction({&*instruction.begin(), static_cast<size_t>(ranges::distance(instruction))});
        }), [&grid](const auto &instruction) {
            grid.applyModernInstruction(instruction);
        });

        return grid.countLit();
    }
}