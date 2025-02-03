#pragma once

#include "Inttypes/Inttypes.h"
#include "Linalg/LinalgBase.h"

namespace r3d {

using linalg::Float;

struct Color3b;
struct Color4b;

struct Color3f;
struct Color4f;

struct Color3b {
	using Byte = inttypes::Byte;

	Byte r = 0;
	Byte g = 0;
	Byte b = 0;

	static Color3b fromColor4b(Color4b);
	static Color3b fromColor3f(const Color3f&);
	static Color3b fromColor4f(const Color4f&);
};

struct Color4b {
	using Byte = inttypes::Byte;

	Byte r = 0;
	Byte g = 0;
	Byte b = 0;
	Byte a = 255;

	static Color4b fromColor3b(Color3b);
	static Color4b fromColor3f(const Color3f&);
	static Color4b fromColor4f(const Color4f&);
};

struct Color3f {
	Float r = 0.0f;
	Float g = 0.0f;
	Float b = 0.0f;

	static Color3f fromColor4f(const Color4f&);
	static Color3f fromColor4b(Color4b);
	static Color3f fromColor3b(Color3b);
};

struct Color4f {
	Float r = 0.0f;
	Float g = 0.0f;
	Float b = 0.0f;
	Float a = 1.0f;

	static Color4f fromColor3f(const Color3f&);
	static Color4f fromColor4b(Color4b);
	static Color4f fromColor3b(Color3b);
};

constexpr static Color3b kRed3b = Color3b{255, 0, 0};
constexpr static Color3b kGreen3b = Color3b{0, 255, 0};
constexpr static Color3b kBlue3b = Color3b{0, 0, 255};
constexpr static Color3b kBlack3b = Color3b{0, 0, 0};
constexpr static Color3b kWhite3b = Color3b{255, 255, 255};

constexpr static Color4b kRed4b = Color4b{255, 0, 0, 255};
constexpr static Color4b kGreen4b = Color4b{0, 255, 0, 255};
constexpr static Color4b kBlue4b = Color4b{0, 0, 255, 255};
constexpr static Color4b kBlack4b = Color4b{0, 0, 0, 255};
constexpr static Color4b kWhite4b = Color4b{255, 255, 255, 255};

constexpr static Color3f kRed3f = Color3f{1.0f, 0.0f, 0.0f};
constexpr static Color3f kGreen3f = Color3f{0.0f, 1.0f, 0.0f};
constexpr static Color3f kBlue3f = Color3f{0.0f, 0.0f, 1.0f};
constexpr static Color3f kBlack3f = Color3f{0.0f, 0.0f, 0.0f};
constexpr static Color3f kWhite3f = Color3f{1.0f, 1.0f, 1.0f};

constexpr static Color4f kRed4f = Color4f{1.0f, 0.0f, 0.0f, 1.0f};
constexpr static Color4f kGreen4f = Color4f{0.0f, 1.0f, 0.0f, 1.0f};
constexpr static Color4f kBlue4f = Color4f{0.0f, 0.0f, 1.0f, 1.0f};
constexpr static Color4f kBlack4f = Color4f{0.0f, 0.0f, 0.0f, 1.0f};
constexpr static Color4f kWhite4f = Color4f{1.0f, 1.0f, 1.0f, 1.0f};

bool operator==(Color3b, Color3b);
bool operator==(Color4b, Color4b);

bool operator==(const Color3f&, const Color3f&);
bool operator==(const Color4f&, const Color4f&);

Color3f operator+(const Color3f&, const Color3f&);
Color4f operator+(const Color4f&, const Color4f&);

Color3f operator*(const Color3f&, Float);
Color3f operator*(Float, const Color3f&);

Color4f operator*(const Color4f&, Float);
Color4f operator*(Float, const Color4f&);

} // namespace r3d
