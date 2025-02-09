#pragma once

#include "Renderer.h"

namespace r3d {
class Model {

	using SizePair = inttypes::SizePair;

	using FrameOutput =
		NSLibrary::CObservableData<FrozenFrame, NSLibrary::CByValue>;
	using FrameInput = NSLibrary::CObserver<FrozenFrame, NSLibrary::CByValue>;

public:
	explicit Model(SizePair target_size_);

	void subscribe(FrameInput* obs);

	void renderFrame();

	void moveCamera(Vec3 dir, Float dtime);

private:
	Renderer renderer_;
	Camera camera_;
	Scene scene_;

	FrameOutput frame_out_;
};

} // namespace r3d
