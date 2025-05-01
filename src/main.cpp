#include "Application.h"
#include "Except/Except.h"

int main(int argc, char* argv[]) {
	try {
		r3d::Application app(argc, argv);
		app.run();
	} catch (...) {
		except::react();
	}

	return 0;
}
