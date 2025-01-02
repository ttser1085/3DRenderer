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
	void resizeFrame(Frame::Width new_width, Frame::Height new_height);

private:
	Renderer renderer_;

	FrameObservable frame_port_out_;
};

using ModelRef = std::reference_wrapper<Model>;

} // namespace r3d
