#pragma once

#include "Broker.h"
#include "ControllerManager.h"
#include "Model.h"
#include "Runtime.h"
#include "View.h"

namespace r3d {

class Application {
public:
	Application(int argc, char* argv[]);

	void run();

private:
	Runtime runtime_;

	Model model_;
	View view_;
	ControllerManager manager_;
	Broker broker_;
};

} // namespace r3d
