#pragma once

#include "Frame.h"

namespace r3d {

class Renderer {
public:
	Renderer(Frame::Width target_width, Frame::Height target_height);

	FramePtr makeFrame();

	void setTargetSize(Frame::Width target_width, Frame::Height target_height);

private:
	class Primitives {
	public:
		// TODO:
		// static void drawPixel
		// static void drawLine
		// static void drawTriangle

	private:
		Primitives() = delete;
		~Primitives() = delete;
	};

	Frame::Width target_width_;
	Frame::Height target_height_;
};

} // namespace r3d
