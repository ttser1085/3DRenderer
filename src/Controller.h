#pragma once

#include "Communication.h"
#include "CoreEvent.h"
#include "Linalg/LinalgBase.h"
#include "ModelEvent.h"

namespace r3d {

class Broker;

class Controller : public ColdReceiver<ModelEvent, NSLibrary::CByReference> {
public:
	explicit Controller(Broker& broker);

private:
	class Visitor {
	public:
		explicit Visitor(Broker& broker);

		void operator()(const Tick&);
		void operator()(const KeyPressed&);
		void operator()(const MouseMoved&);

	private:
		Broker& broker_;
	};

	Visitor visitor_;
};

} // namespace r3d
