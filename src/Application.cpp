#include "Application.h"

#include "Loader.h"

#include "Controllers/KeyboardController.h"
#include "Controllers/LoadController.h"
#include "Controllers/MouseController.h"
#include "Controllers/TickController.h"

namespace r3d {

Application::Application(int argc, char* argv[])
	: runtime_("3D Renderer"), model_(makeSizePair(1440, 900)),
	  view_(runtime_.window()),
	  manager_(broker_, TickController, KeyboardController, MouseController,
			   LoadController{}) {
	model_.subscribe(&view_);
	broker_.subscribe(&model_);

	if (argc >= 2) {
		Loader loader;
		loader.subscribe(&manager_);
		loader.ParseObject(argv[1], Vec3{0.0f, 0.0f, -7.0f});
		loader.ParseObject(argv[1], Vec3{4.0f, 0.0f, -7.0f});
		loader.unsubscribeAll();
	}

	runtime_.ModelSender::subscribe(&manager_);
	runtime_.ViewSender::subscribe(&view_);
}

void Application::run() { runtime_.run(); }

} // namespace r3d
