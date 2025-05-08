#pragma once

#include "Communication.h"
#include "ModelEvent.h"
#include "ViewEvent.h"

namespace r3d {

// User input component
class Input : public Sender<ModelEvent, ByRef>,
			  public Sender<ViewEvent, ByRef> {
public:
	using ModelSender = Sender<ModelEvent, ByRef>;
	using ViewSender = Sender<ViewEvent, ByRef>;

protected:
	void send(const ModelEvent& event);
	void send(const ViewEvent& event);
};

} // namespace r3d
