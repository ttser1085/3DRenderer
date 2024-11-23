#pragma once

#include "Frame.h"

namespace r3d {

class Renderer {
public:
	void render(FramePtr frame);

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
};

} // namespace r3d
