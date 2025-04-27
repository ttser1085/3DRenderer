#pragma once

namespace r3d::utils {

template<class... Ts>
struct Overloaded : Ts... {
	using Ts::operator()...;
};

// For C++17 and less:
template<class... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;

} // namespace r3d::utils
