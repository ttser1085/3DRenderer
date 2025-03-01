#include "Inttypes.h"

namespace inttypes {

// Screen size

// Screen diff

Width toUnsigned(SignedWidth w) {
	assert(w >= 0);
	return static_cast<Width>(w);
}

Height toUnsigned(SignedHeight h) {
	assert(h >= 0);
	return static_cast<Height>(h);
}

SizePair toSizePair(DiffPair dp) {
	return SizePair{toUnsigned(dp.x), toUnsigned(dp.y)};
}

} // namespace inttypes
