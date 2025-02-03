#pragma once

#include "Frame.h"
#include "Scene.h"

namespace r3d {

class Renderer {

	using Width = inttypes::Width;
	using Height = inttypes::Height;

public:
	Renderer(Width target_width, Height target_height);

	Frame makeFrame() const;

	void setTargetSize(Width target_width, Height target_height);

private:
	Width target_width_;
	Height target_height_;

	Scene scene_;
};

} // namespace r3d
