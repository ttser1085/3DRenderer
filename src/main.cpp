#include "Application.h"
#include "Except/Except.h"

int main() {
	try {
		r3d::Application app;
		app.run();
	} catch (...) {
		except::react();
	}

	return 0;
}
