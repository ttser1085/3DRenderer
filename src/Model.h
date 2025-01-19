#pragma once

#include "Renderer.h"

namespace r3d {
class Model {

	using FrameOutput =
		NSLibrary::CObservableData<FramePtr, NSLibrary::CByValue>;
	using FrameInput = NSLibrary::CObserver<FramePtr, NSLibrary::CByValue>;

public:
	Model(Frame::Width frame_width, Frame::Height frame_height);

	void attachFramePort(FrameInput* obs);

	void renderFrame();
	void resizeFrame(Frame::Width new_width, Frame::Height new_height);

private:
	Renderer renderer_;

	FrameOutput frame_out_;
};

} // namespace r3d
