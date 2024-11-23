#include "Color.h"

namespace r3d {

Color3 Color3::fromColor4(Color4 color4) {
	return Color3{color4.r, color4.g, color4.b};
}

Color4 Color4::fromColor3(Color3 color3) {
	return Color4{color3.r, color3.g, color3.b, 255};
}

bool operator==(const Color3 c1, const Color3 c2) {
	return c1.r == c2.r && c1.b == c2.b && c1.g == c2.g;
}

bool operator==(const Color4 c1, const Color4 c2) {
	return c1.r == c2.r && c1.b == c2.b && c1.g == c2.g && c1.a == c2.a;
}

} // namespace r3d
