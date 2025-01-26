#pragma once

#include "Frame.h"
#include "Object.h"

namespace r3d {

class Renderer {
public:
	Renderer(Width target_width, Height target_height);

	FramePtr makeFrame() const;

	void setTargetSize(Width target_width, Height target_height);

private:
	Width target_width_;
	Height target_height_;

	std::vector<Object> objects_;
};

} // namespace r3d
