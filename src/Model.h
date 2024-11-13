#pragma once

#include "Renderer.h"

#include <Observer.h>

namespace r3d {

class Controller;

class Model {
	friend Controller;

public:
	Model(size_t frame_width, size_t frame_height) noexcept;

	void attachFramePort(NSLibrary::CObserver<uint8_t*>* obs);

private:
	void startRender();

	Frame current_frame_;
	Renderer renderer_;

	NSLibrary::CObservable<uint8_t*> frame_port_out_;
};

} // namespace r3d
