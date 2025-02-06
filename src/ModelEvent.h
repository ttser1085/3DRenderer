#pragma once

#include <Observer.h>

#include <variant>

namespace r3d {

struct NoneEvent {};

struct RenderEvent {};

using ModelEvent = std::variant<NoneEvent, RenderEvent>;

} // namespace r3d
