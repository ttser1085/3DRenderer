#pragma once

#include "Renderer.h"

namespace r3d {

class Core {
public:
	explicit Core(SizePair target_size_);

    FrozenFrame renderFrame() const;

	Renderer& renderer();
	Camera& camera();
	Scene& scene();

private:
	Renderer renderer_;
	Camera camera_;
	Scene scene_;
};

} // namespace r3d
