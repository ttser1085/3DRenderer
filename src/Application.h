#pragma once

#include "Broker.h"
#include "Model.h"
#include "Runtime.h"
#include "View.h"

#include "Controllers/KeyboardController.h"
#include "Controllers/MouseController.h"
#include "Controllers/TickController.h"

namespace r3d {

class Application {
public:
	Application(int argc, char* argv[]);

	void run();

private:
	Runtime runtime_;

	Model model_;
	View view_;
	
	TickController tick_controller;
	KeyboardController key_controller;
	MouseController mouse_controller;

	Broker broker_;
};

} // namespace r3d
