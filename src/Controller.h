#pragma once

#include "Linalg/LinalgBase.h"
#include "ModelEvent.h"

namespace r3d {

class Model;

class Controller {

	using ModelRef = Model&;

	using EventInput =
		NSLibrary::CColdInput<ModelEvent, NSLibrary::CByReference>;

public:
	explicit Controller(ModelRef model);

	EventInput* eventPort() noexcept;

private:
	class Visitor {
	public:
		explicit Visitor(ModelRef model);

		void operator()(const Tick&);
		void operator()(const KeyPressed&);

	private:
		ModelRef model_;

		linalg::Vec3 movement_dir_ = linalg::Vec3::Zero();
	};

	Visitor visitor_;
	EventInput event_in_;
};

} // namespace r3d
