#pragma once

#include "Frame.h"

namespace r3d {

class Renderer {
public:
	Renderer(Width target_width, Height target_height);

	FramePtr makeFrame() const;

	void setTargetSize(Width target_width, Height target_height);

private:
	Width target_width_;
	Height target_height_;
};

} // namespace r3d
