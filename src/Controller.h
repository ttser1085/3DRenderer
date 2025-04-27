#pragma once

#include "Broker.h"
#include "ModelEvent.h"
#include "Utils/Overloaded.h"

namespace r3d {

namespace detail {

template<typename T, typename Variant>
struct CallWithBrokerImpl;

template<typename T, typename... Types>
struct CallWithBrokerImpl<T, std::variant<Types...>> {
	static constexpr bool value = (requires(T ctrl, Broker& broker, Types arg) {
		{ ctrl(broker, arg) } -> std::same_as<void>;
	} || ...);
};

} // namespace detail

template<typename T>
concept Controller = detail::CallWithBrokerImpl<T, ModelEvent>::value;

} // namespace r3d
