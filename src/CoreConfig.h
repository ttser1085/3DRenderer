#pragma once

#include "Inttypes/Inttypes.h"
#include "Core/Object.h"
#include "Core/Renderer.h"

namespace r3d {

struct CoreConfig {
	std::vector<Object> objects;
    Renderer::RenderMode mode;
};

} // namespace r3d
