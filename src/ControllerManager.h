#pragma once

#include "Communication.h"
#include "Controller.h"
#include "CoreEvent.h"
#include "Linalg/LinalgBase.h"

namespace r3d {

class Broker;

class ControllerManager : public ColdReceiver<ModelEvent, ByRef> {
public:
	template<Controller... Cs>
	ControllerManager(Broker& broker, Cs... controllers)
		: broker_(broker),
		  BaseType([this, ... controllers = std::forward<Cs>(controllers)](
					   const ModelEvent& event) mutable {
			  using namespace std::placeholders;
			  utils::Visit(event,
						   std::bind(std::forward<Cs>(controllers),
									 std::ref(broker_), _1)...,
						   [](...) {});
		  }) {}

private:
	Broker& broker_;
};

} // namespace r3d
