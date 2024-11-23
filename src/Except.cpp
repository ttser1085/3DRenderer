#include "Except.h"

#include <exception>
#include <iostream>

namespace except {

void react() {
	try {
		throw;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

} // namespace except
