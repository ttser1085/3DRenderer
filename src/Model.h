#pragma once

#include "Renderer.h"

namespace r3d {
class Model {

	using FrameOutput =
		NSLibrary::CObservableData<FrozenFrame, NSLibrary::CByValue>;
	using FrameInput = NSLibrary::CObserver<FrozenFrame, NSLibrary::CByValue>;

public:
	Model(Width frame_width, Height frame_height);

	void attachFramePort(FrameInput* obs);

	void renderFrame();
	void resizeFrame(Width new_width, Height new_height);

private:
	Renderer renderer_;

	FrameOutput frame_out_;
};

} // namespace r3d
