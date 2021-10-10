#include "day7.h"

#include <regex>

#include <range/v3/view/split.hpp>
#include <range/v3/algorithm/for_each.hpp>

bool isPositiveNumber(const std::string &s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

auto day7::WireUnaryOp::readSignal(day7::Circuit *circuit) -> day7::Signal {
    if (!value.has_value()) {
        auto val = isPositiveNumber(lhs) ? std::stoi(lhs) : circuit->readSignal(lhs);

        switch (op) {
            case UnaryOp::NOT:
                value = ~val;
                break;
            case UnaryOp::LSHIFT:
                value = val << argument.value();
                break;
            case UnaryOp::RSHIFT:
                value = val >> argument.value();
                break;
            case UnaryOp::FORWARD:
                value = val;
                break;
        }
    }

    return value.value();
}

day7::WireUnaryOp::WireUnaryOp(day7::WireId lhs, day7::WireUnaryOp::UnaryOp op, std::optional<int> argument) : lhs(
        std::move(lhs)),
                                                                                                               op(op),
                                                                                                               argument(
                                                                                                                       argument) {}

auto day7::WireBinaryOp::readSignal(day7::Circuit *circuit) -> day7::Signal {
    if (!value.has_value()) {
        auto val1 = isPositiveNumber(lhs) ? std::stoi(lhs) : circuit->readSignal(lhs);
        auto val2 = isPositiveNumber(rhs) ? std::stoi(rhs) : circuit->readSignal(rhs);

        switch (op) {
            case BinaryOp::OR:
                value = val1 | val2;
                break;
            case BinaryOp::AND:
                value = val1 & val2;
                break;
        }
    }

    return value.value();
}

day7::WireBinaryOp::WireBinaryOp(day7::WireId lhs, day7::WireId rhs, day7::WireBinaryOp::BinaryOp op) : lhs(
        std::move(lhs)),
                                                                                                        rhs(std::move(
                                                                                                                rhs)),
                                                                                                        op(op) {}

day7::Signal day7::WireDirect::readSignal(day7::Circuit *) {
    return value;
}

#include <iostream>
#include <utility>

void day7::Circuit::applyInstructions(const std::string &instruction) {
    static auto value_regex = std::regex(R"(^(\d+) -> (\w+))");
    static auto binary_op_regex = std::regex(R"(^(\w+) (\w+) (\w+) -> (\w+))");
    static auto unary_op_regex = std::regex(R"(^NOT (\w+) -> (\w+))");
    static auto forward_regex = std::regex(R"(^(\w+) -> (\w+))");

    auto match = std::smatch{};
    if (std::regex_match(instruction, match, value_regex)) {
        auto wireId = match[2];
        auto value = std::stoi(match[1]);
        circuit[wireId] = std::make_unique<WireDirect>(value);
    } else if (std::regex_match(instruction, match, binary_op_regex)) {
        auto wireId = match[4];
        auto lhs = match[1];
        auto rhs = match[3];
        auto op = match[2];

        if (op == "AND") {
            circuit[wireId] = std::make_unique<WireBinaryOp>(lhs, rhs, WireBinaryOp::BinaryOp::AND);
        } else if (op == "OR") {
            circuit[wireId] = std::make_unique<WireBinaryOp>(lhs, rhs, WireBinaryOp::BinaryOp::OR);
        } else if (op == "LSHIFT") {
            circuit[wireId] = std::make_unique<WireUnaryOp>(lhs, WireUnaryOp::UnaryOp::LSHIFT, std::stoi(rhs));
        } else if (op == "RSHIFT") {
            circuit[wireId] = std::make_unique<WireUnaryOp>(lhs, WireUnaryOp::UnaryOp::RSHIFT, std::stoi(rhs));
        } else {
            throw std::runtime_error("op fiasco!");
        }
    } else if (std::regex_match(instruction, match, unary_op_regex)) {
        auto wireId = match[2];
        auto lhs = match[1];
        circuit[wireId] = std::make_unique<WireUnaryOp>(lhs, WireUnaryOp::UnaryOp::NOT);
    } else if (std::regex_match(instruction, match, forward_regex)) {
        auto wireId = match[2];
        auto lhs = match[1];
        circuit[wireId] = std::make_unique<WireUnaryOp>(lhs, WireUnaryOp::UnaryOp::FORWARD);
    } else {
        throw std::runtime_error("input fiasco!");
    }
}

day7::Circuit::Circuit(std::string_view input) {
    ranges::for_each(ranges::views::split(input, '\n'), [&](const auto &instruction) {
        applyInstructions({&*instruction.begin(), static_cast<size_t>(ranges::distance(instruction))});
    });
}

void day7::Circuit::overrideWire(std::string wireId, day7::Signal signal) {
    circuit[wireId] = std::make_unique<WireDirect>(signal);
}

auto day7::calculateSignal(std::string_view input, std::string_view wire) -> Signal {
    auto circuit = Circuit(input);
    return circuit.readSignal(wire.data());
}

auto
day7::calculateOverridenSignal(std::string_view input, std::string_view wire1, std::string_view wire2) -> day7::Signal {
    auto circuit = Circuit(input);
    auto originalSignal = circuit.readSignal((wire1.data()));

    circuit = Circuit(input);
    circuit.overrideWire(wire2.data(), originalSignal);
    return circuit.readSignal(wire1.data());
}
