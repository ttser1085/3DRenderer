#pragma once

#include "Frame.h"

#include <Observer.h>
#include <variant>

namespace r3d {

struct NoneEvent {};

struct RenderEvent {};

struct ResizeEvent {
	Frame::Width new_width;
	Frame::Height new_height;
};

using ModelEvent = std::variant<NoneEvent, RenderEvent, ResizeEvent>;

using ModelEventObservable =
	NSLibrary::CObservableData<ModelEvent, NSLibrary::CByReference>;
using ModelEventObserver =
	NSLibrary::CObserver<ModelEvent, NSLibrary::CByReference>;
using ModelEventColdInput =
	NSLibrary::CColdInput<ModelEvent, NSLibrary::CByReference>;

} // namespace r3d
