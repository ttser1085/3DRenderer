#include "Application.h"

#include "Loader.h"

#include <iostream>

namespace r3d {

Application::Application(int argc, char* argv[])
	: runtime_("3D Renderer"), view_(runtime_.window()) {
	model_.subscribe(view_.frameInput());
	broker_.subscribe(model_.input());

	printer_.subscribe(view_.textInput());

	tick_controller_.subscribe(broker_.updateInput());
	mouse_controller_.subscribe(broker_.rotateInput());
	key_controller_.subscribe(broker_.moveInput());
	print_controller_.subscribe(printer_.input());

	runtime_.subscribe(tick_controller_.input());
	runtime_.subscribe(mouse_controller_.input());
	runtime_.subscribe(key_controller_.input());
	runtime_.subscribe(print_controller_.input());
	runtime_.subscribe(view_.resizeInput());

	if (argc >= 2) {
		try {
			Loader loader(argv[1]);
			CoreConfig config = loader.parseCoreConfig();
			model_.initFromConfig(std::move(config));
			printer_.setFont(loader.parseFont());
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}

void Application::run() { runtime_.run(); }

} // namespace r3d
