#include "Color.h"

#include <assert.h>

namespace r3d {

// Color3b

Color3b Color3b::fromColor4b(Color4b color4b) {
	return Color3b{color4b.r, color4b.g, color4b.b};
}

Color3b Color3b::fromColor3f(const Color3f& color3f) {
	return Color3b{static_cast<Byte>(color3f.r * 255.0f),
				   static_cast<Byte>(color3f.g * 255.0f),
				   static_cast<Byte>(color3f.b * 255.0f)};
}

Color3b Color3b::fromColor4f(const Color4f& color4f) {
	return Color3b{static_cast<Byte>(color4f.r * 255.0f),
				   static_cast<Byte>(color4f.g * 255.0f),
				   static_cast<Byte>(color4f.b * 255.0f)};
}

// COlor4b

Color4b Color4b::fromColor3b(Color3b color3b) {
	return Color4b{color3b.r, color3b.g, color3b.b, 255};
}

Color4b Color4b::fromColor3f(const Color3f& color3f) {
	return Color4b{static_cast<Byte>(color3f.r * 255.0f),
				   static_cast<Byte>(color3f.g * 255.0f),
				   static_cast<Byte>(color3f.b * 255.0f), 255};
}

Color4b Color4b::fromColor4f(const Color4f& color4f) {
	return Color4b{static_cast<Byte>(color4f.r * 255.0f),
				   static_cast<Byte>(color4f.g * 255.0f),
				   static_cast<Byte>(color4f.b * 255.0f),
				   static_cast<Byte>(color4f.a * 255.0f)};
}

// Color3f

Color3f Color3f::fromColor4f(const Color4f& color4f) {
	return Color3f{color4f.r, color4f.g, color4f.b};
}

Color3f Color3f::fromColor4b(Color4b color4b) {
	return Color3f{static_cast<Float>(color4b.r) / 255.0f,
				   static_cast<Float>(color4b.g) / 255.0f,
				   static_cast<Float>(color4b.b) / 255.0f};
}

Color3f Color3f::fromColor3b(Color3b color3b) {
	return Color3f{static_cast<Float>(color3b.r) / 255.0f,
				   static_cast<Float>(color3b.g) / 255.0f,
				   static_cast<Float>(color3b.b) / 255.0f};
}

// Color4f

Color4f Color4f::fromColor3f(const Color3f& color3f) {
	return Color4f{color3f.r, color3f.g, color3f.b, 1.0f};
}

Color4f Color4f::fromColor4b(Color4b color4b) {
	return Color4f{static_cast<Float>(color4b.r) / 255.0f,
				   static_cast<Float>(color4b.g) / 255.0f,
				   static_cast<Float>(color4b.b) / 255.0f,
				   static_cast<Float>(color4b.a) / 255.0f};
}

Color4f Color4f::fromColor3b(Color3b color3b) {
	return Color4f{static_cast<Float>(color3b.r) / 255.0f,
				   static_cast<Float>(color3b.g) / 255.0f,
				   static_cast<Float>(color3b.b) / 255.0f, 1.0f};
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

// Binary ops

Color3f operator+(const Color3f& c1, const Color3f& c2) {
	return Color3f{c1.r + c2.r, c1.g + c2.g, c1.b + c2.b};
}

Color4f operator+(const Color4f& c1, const Color4f& c2) {
	return Color4f{c1.r + c2.r, c1.g + c2.g, c1.b + c2.b, c1.a + c2.a};
}

Color3f operator*(const Color3f& color, Float x) {
	return Color3f{color.r * x, color.g * x, color.b * x};
}

Color3f operator*(Float x, const Color3f& color) { return color * x; }

Color4f operator*(const Color4f& color, Float x) {
	return Color4f{color.r * x, color.g * x, color.b * x, color.a * x};
}

Color4f operator*(Float x, const Color4f& color) { return color * x; }

} // namespace r3d
