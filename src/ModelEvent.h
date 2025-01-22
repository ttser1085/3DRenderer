#pragma once

#include "Frame.h"

#include <Observer.h>
#include <variant>

namespace r3d {

struct NoneEvent {};

struct RenderEvent {};

struct ResizeEvent {
	Width new_width;
	Height new_height;
};

using ModelEvent = std::variant<NoneEvent, RenderEvent, ResizeEvent>;

} // namespace r3d
