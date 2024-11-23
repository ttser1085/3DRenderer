#pragma once

#include "Linalg.h"

#include <Observer.h>
#include <variant>

namespace r3d {

class ModelEvent {
public:
	struct None {};

	struct RenderFrame {};

	struct ResizeFrame {
		Vec2s new_size;
	};

	ModelEvent() = default;

	template<typename T>
	ModelEvent(const T& event) {
		event_ = event;
	}

	template<typename T>
	bool is() const {
		return std::holds_alternative<T>(event_);
	}

	template<typename T>
	const T* getIf() const {
		return std::get_if<T>(&event_);
	}

private:
	using EventVariant = std::variant<None, RenderFrame, ResizeFrame>;

	EventVariant event_ = None{};
};

using ModelEventObservable =
	NSLibrary::CObservableData<ModelEvent, NSLibrary::CByReference>;
using ModelEventObserver =
	NSLibrary::CObserver<ModelEvent, NSLibrary::CByReference>;
using ModelEventColdInput =
	NSLibrary::CColdInput<ModelEvent, NSLibrary::CByReference>;

} // namespace r3d
