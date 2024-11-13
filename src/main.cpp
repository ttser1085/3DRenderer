#include "Controller.h"
#include "Model.h"
#include "View.h"

#include <iostream>

int main() {
	r3d::Model model(800, 600);
	r3d::View view(800, 600, "My window");
	r3d::Controller controler(model);

	model.attachFramePort(view.getFramePort());
	view.attachEventPort(controler.getEventPort());

	view.run();

	return 0;
}
