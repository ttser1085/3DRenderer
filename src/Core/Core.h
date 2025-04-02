#pragma once

#include "Renderer.h"

namespace r3d {

class Core {
public:
	explicit Core(inttypes::SizePair target_size_);

    FrozenFrame renderFrame() const;

    void moveCamera(Vec3 dir, Float dtime);

private:
	Renderer renderer_;
	Camera camera_;
	Scene scene_;
};

} // namespace r3d
