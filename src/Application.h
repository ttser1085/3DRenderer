#pragma once

#include "Model.h"
#include "Printer.h"
#include "Runtime.h"
#include "View.h"

#include "Controllers/Broker.h"
#include "Controllers/KeyboardController.h"
#include "Controllers/MouseController.h"
#include "Controllers/PrintController.h"
#include "Controllers/TickController.h"

namespace r3d {

class Application {
public:
	Application(int argc, char* argv[]);

	void run();

private:
	Runtime runtime_;

	// models:
	Model model_;
	Printer printer_;

	// views:
	View view_;

	// controllers:
	TickController tick_controller_;
	KeyboardController key_controller_;
	MouseController mouse_controller_;
	PrintController print_controller_;
	Broker broker_;
};

} // namespace r3d
