#pragma once

#include <tuple>
#include <type_traits>
#include <utility>

namespace r3d::utils {

struct DefaultTag {};

template <int N>
struct NumericTag {};

template<typename Base, typename Tag = DefaultTag>
class Tagged : public Base {
public:
	using BaseType = Tagged<Base, Tag>;
	using Base::Base;
};

} // namespace r3d::utils
