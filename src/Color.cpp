#include "Color.h"

namespace r3d {

// Color3b

Color3b Color3b::fromColor4b(Color4b color4b) {
	return Color3b{color4b.r, color4b.g, color4b.b};
}

Color3b Color3b::fromColor3f(const Color3f& color3f) {
	return Color3b{static_cast<uint8_t>(color3f.r * 255.0f),
				   static_cast<uint8_t>(color3f.g * 255.0f),
				   static_cast<uint8_t>(color3f.b * 255.0f)};
}

Color3b Color3b::fromColor4f(const Color4f& color4f) {
	return Color3b{static_cast<uint8_t>(color4f.r * 255.0f),
				   static_cast<uint8_t>(color4f.g * 255.0f),
				   static_cast<uint8_t>(color4f.b * 255.0f)};
}

// COlor4b

Color4b Color4b::fromColor3b(Color3b color3b) {
	return Color4b{color3b.r, color3b.g, color3b.b, 255};
}

Color4b Color4b::fromColor3f(const Color3f& color3f) {
	return Color4b{static_cast<uint8_t>(color3f.r * 255.0f),
				   static_cast<uint8_t>(color3f.g * 255.0f),
				   static_cast<uint8_t>(color3f.b * 255.0f), 255};
}

Color4b Color4b::fromColor4f(const Color4f& color4f) {
	return Color4b{static_cast<uint8_t>(color4f.r * 255.0f),
				   static_cast<uint8_t>(color4f.g * 255.0f),
				   static_cast<uint8_t>(color4f.b * 255.0f),
				   static_cast<uint8_t>(color4f.a * 255.0f)};
}

// Color3f

Color3f Color3f::fromColor4f(const Color4f& color4f) {
	return Color3f{color4f.r, color4f.g, color4f.b};
}

Color3f Color3f::fromColor4b(Color4b color4b) {
	return Color3f{static_cast<float>(color4b.r) / 255.0f,
				   static_cast<float>(color4b.g) / 255.0f,
				   static_cast<float>(color4b.b) / 255.0f};
}

Color3f Color3f::fromColor3b(Color3b color3b) {
	return Color3f{static_cast<float>(color3b.r) / 255.0f,
				   static_cast<float>(color3b.g) / 255.0f,
				   static_cast<float>(color3b.b) / 255.0f};
}

// Color4f

Color4f Color4f::fromColor3f(const Color3f& color3f) {
	return Color4f{color3f.r, color3f.g, color3f.b, 1.0f};
}

Color4f Color4f::fromColor4b(Color4b color4b) {
	return Color4f{static_cast<float>(color4b.r) / 255.0f,
				   static_cast<float>(color4b.g) / 255.0f,
				   static_cast<float>(color4b.b) / 255.0f,
				   static_cast<float>(color4b.a) / 255.0f};
}

Color4f Color4f::fromColor3b(Color3b color3b) {
	return Color4f{static_cast<float>(color3b.r) / 255.0f,
				   static_cast<float>(color3b.g) / 255.0f,
				   static_cast<float>(color3b.b) / 255.0f, 1.0f};
}

// Comparators

bool operator==(const Color3b c1, const Color3b c2) {
	return c1.r == c2.r && c1.b == c2.b && c1.g == c2.g;
}

bool operator==(const Color4b c1, const Color4b c2) {
	return c1.r == c2.r && c1.b == c2.b && c1.g == c2.g && c1.a == c2.a;
}

bool operator==(const Color3f& c1, const Color3f& c2) {
	return c1.r == c2.r && c1.b == c2.b && c1.g == c2.g;
}

bool operator==(const Color4f& c1, const Color4f& c2) {
	return c1.r == c2.r && c1.b == c2.b && c1.g == c2.g && c1.a == c2.a;
}

} // namespace r3d
