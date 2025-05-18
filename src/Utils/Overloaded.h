#pragma once

#include <variant>

namespace r3d::utils {

template<class... Ts>
struct Overloaded : Ts... {
	using Ts::operator()...;
};

// For C++17 and less:
template<class... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;


// Visits:
template <class... Args, class... Ts>
constexpr decltype(auto) Visit(const std::variant<Args...>& var, Ts&&... ts) {
    return std::visit(Overloaded{std::forward<Ts>(ts)...}, var);
}

template <class... Args, class... Ts>
constexpr decltype(auto) Visit(std::variant<Args...>& var, Ts&&... ts) {
    return std::visit(Overloaded{std::forward<Ts>(ts)...}, var);
}

template <class... Args, class... Ts>
constexpr decltype(auto) Visit(std::variant<Args...>&& var, Ts&&... ts) {
    return std::visit(Overloaded{std::forward<Ts>(ts)...}, std::move(var));
}

} // namespace r3d::utils
