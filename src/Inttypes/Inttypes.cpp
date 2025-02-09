#include "Inttypes.h"

namespace inttypes {

// Screen size

SizePair makeSizePair(ScreenSize w, ScreenSize h) {
	return SizePair{static_cast<Width>(w), static_cast<Height>(h)};
}

// Screen diff

ScreenSize sum(ScreenSize s, ScreenDiff d) {
	return s + static_cast<ScreenSize>(d);
}

ScreenDiff diff(ScreenSize s1, ScreenSize s2) {
	return static_cast<ScreenDiff>(static_cast<int32_t>(s1) -
								   static_cast<int32_t>(s2));
}

ScreenDiff abs(ScreenDiff d) {
	return static_cast<ScreenDiff>(std::abs(static_cast<ScreenDiff>(d)));
}

} // namespace inttypes
