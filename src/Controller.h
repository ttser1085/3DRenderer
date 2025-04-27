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
	void handleTick(const Tick&);
	void handleKeyPressed(const KeyPressed&);
	void handleMouseMoved(const MouseMoved&);

	Broker& broker_;
};

} // namespace r3d
