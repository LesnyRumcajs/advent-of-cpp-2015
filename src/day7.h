#pragma once

#include <string_view>
#include <string>
#include <unordered_map>
#include <optional>
#include <memory>

namespace day7 {
    class Circuit;

    using WireId = std::string;
    using Signal = uint16_t;

    struct Wire {
        [[nodiscard]] virtual auto readSignal(Circuit *) -> Signal = 0;
    };

    struct WireDirect : public Wire {
        explicit WireDirect(Signal value) : value(value) {};

        virtual ~WireDirect() = default;

        [[nodiscard]] Signal readSignal(Circuit *) override;

    private:
        Signal value{};
    };

    struct WireBinaryOp : public Wire {
        enum class BinaryOp {
            OR,
            AND,
        };

        WireBinaryOp(WireId lhs, WireId rhs, BinaryOp op);

        virtual ~WireBinaryOp() = default;

        [[nodiscard]] auto readSignal(Circuit *circuit) -> Signal override;

    private:
        WireId lhs;
        WireId rhs;
        BinaryOp op;

        std::optional<Signal> value;
    };

    struct WireUnaryOp : public Wire {
        enum class UnaryOp {
            NOT,
            LSHIFT,
            RSHIFT,
            FORWARD
        };

        WireUnaryOp(WireId lhs, UnaryOp op, std::optional<int> argument = std::nullopt);

        virtual ~WireUnaryOp() = default;

        [[nodiscard]] auto readSignal(Circuit *circuit) -> Signal override;

    private:
        WireId lhs;
        UnaryOp op;
        std::optional<int> argument;
        std::optional<Signal> value;
    };

    class Circuit {
    public:
        explicit Circuit(std::string_view input);

        [[nodiscard]] auto readSignal(WireId wireId) -> Signal {
            return circuit[wireId]->readSignal(this);
        }

        void overrideWire(std::string wireId, Signal signal);

    private:
        void applyInstructions(const std::string &instruction);

        std::unordered_map<WireId, std::unique_ptr<Wire>> circuit;
    };


    auto calculateSignal(std::string_view input, std::string_view wire) -> Signal;

    auto calculateOverridenSignal(std::string_view input, std::string_view wire1, std::string_view wire2) -> Signal;
}
