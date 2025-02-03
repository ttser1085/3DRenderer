#include "Except.h"

#include <exception>
#include <iostream>

namespace except {

void react() {
	try {
		throw;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	} catch (...) {
		std::cerr << "Unknown error!\n";
	}
}

} // namespace except
