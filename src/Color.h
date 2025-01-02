#pragma once

#include <inttypes.h>

namespace r3d {

struct Color3;
struct Color4;

struct Color3 {
	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;

	static Color3 fromColor4(Color4 color4);
};

struct Color4 {
	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
	uint8_t a = 255;

	static Color4 fromColor3(Color3 color3);
};

constexpr static Color3 kRed3 = Color3{255, 0, 0};
constexpr static Color3 kGreen3 = Color3{0, 255, 0};
constexpr static Color3 kBlue3 = Color3{0, 0, 255};
constexpr static Color3 kBlack3 = Color3{0, 0, 0};
constexpr static Color3 kWhite3 = Color3{255, 255, 255};

constexpr static Color4 kRed4 = Color4{255, 0, 0, 255};
constexpr static Color4 kGreen4 = Color4{0, 255, 0, 255};
constexpr static Color4 kBlue4 = Color4{0, 0, 255, 255};
constexpr static Color4 kBlack4 = Color4{0, 0, 0, 255};
constexpr static Color4 kWhite4 = Color4{255, 255, 255, 255};

bool operator==(Color3, Color3);
bool operator==(Color4, Color4);

} // namespace r3d
