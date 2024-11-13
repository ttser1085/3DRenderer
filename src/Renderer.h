#pragma once

#include <Eigen/Core>
#include <inttypes.h>
#include <memory>
#include <vector>

namespace r3d {

struct Color3;
struct Color4;

struct Color3 {
	Color3() noexcept = default;
	Color3(uint8_t r, uint8_t g, uint8_t b) noexcept;

	Color3(Color4 color4) noexcept;

	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;

	const static Color3 RED;
	const static Color3 GREEN;
	const static Color3 BLUE;
	const static Color3 BLACK;
	const static Color3 WHITE;
};

struct Color4 {
	Color4() noexcept = default;
	Color4(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) noexcept;

	Color4(Color3 color3) noexcept;

	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
	uint8_t a = 255;

	const static Color4 RED;
	const static Color4 GREEN;
	const static Color4 BLUE;
	const static Color4 BLACK;
	const static Color4 WHITE;
};

bool operator==(Color3, Color3);
bool operator==(Color4, Color4);

class Frame {
public:
	Frame(size_t width, size_t height) noexcept;

	void setColor(const Eigen::Vector2<size_t>& pos, Color3 color);
	void setColor(size_t x, size_t y, Color3 color);

	Color3 getColor(const Eigen::Vector2<size_t>& pos) const;
	Color3 getColor(size_t x, size_t y) const;

	size_t getWidth() const;
	size_t getHeight() const;

	void clear(Color3 color = Color3());

	uint8_t* data();

private:
	size_t width_;
	size_t height_;
	std::vector<Color4> data_;
};

class Renderer {
public:
	Renderer() = default;

	void operator()(Frame& frame);
};

} // namespace r3d
