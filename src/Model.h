#pragma once

#include "Frame.h"
#include "Renderer.h"

#include <functional>

namespace r3d {
class Model {

public:
	Model(Frame::Width frame_width, Frame::Height frame_height);

	void attachFramePort(FrameObserver* obs);

	void renderFrame();
	void resizeFrame(const Vec2s& new_size);

private:
	FramePtr current_frame_;
	Renderer renderer_;

	FrameObservable frame_port_out_;
};

using ModelRef = std::reference_wrapper<Model>;

} // namespace r3d
