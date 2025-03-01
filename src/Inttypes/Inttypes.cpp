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

// ScreenSize sum(ScreenSize s, ScreenDiff d) {
// 	return s + static_cast<ScreenSize>(d);
// }

// ScreenDiff diff(ScreenSize s1, ScreenSize s2) {
// 	return static_cast<ScreenDiff>(static_cast<int32_t>(s1) -
// 								   static_cast<int32_t>(s2));
// }

// ScreenDiff abs(ScreenDiff d) {
// 	return static_cast<ScreenDiff>(std::abs(static_cast<ScreenDiff>(d)));
// }

} // namespace inttypes
