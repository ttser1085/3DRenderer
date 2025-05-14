#include "Application.h"

#include "Loader.h"

#include "Controllers/KeyboardController.h"
#include "Controllers/MouseController.h"
#include "Controllers/TickController.h"

namespace r3d {

Application::Application(int argc, char* argv[])
	: runtime_("3D Renderer"), view_(runtime_.window()),
	  manager_(broker_, TickController, KeyboardController, MouseController) {
	model_.subscribe(&view_);
	broker_.subscribe(&model_);

	if (argc >= 2) {
		Loader loader(argv[1]);
		CoreConfig config = loader.parseCoreConfig();
		model_.initFromConfig(std::move(config));
	}

	runtime_.ModelSender::subscribe(&manager_);
	runtime_.ViewSender::subscribe(&view_);
}

void Application::run() { runtime_.run(); }

} // namespace r3d
