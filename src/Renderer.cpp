#include "Renderer.h"

namespace r3d {

// Colors

const Color3 Color3::RED = Color3(255, 0, 0);
const Color3 Color3::GREEN = Color3(0, 255, 0);
const Color3 Color3::BLUE = Color3(0, 0, 255);
const Color3 Color3::BLACK = Color3(0, 0, 0);
const Color3 Color3::WHITE = Color3(255, 255, 255);

const Color4 Color4::RED = Color4(255, 0, 0);
const Color4 Color4::GREEN = Color4(0, 255, 0);
const Color4 Color4::BLUE = Color4(0, 0, 255);
const Color4 Color4::BLACK = Color4(0, 0, 0);
const Color4 Color4::WHITE = Color4(255, 255, 255);

Color3::Color3(uint8_t r, uint8_t g, uint8_t b) noexcept : r(r), g(g), b(b) {}

Color3::Color3(Color4 color4) noexcept
	: r(color4.r), g(color4.g), b(color4.b) {}

Color4::Color4(uint8_t r, uint8_t g, uint8_t b, uint8_t a) noexcept
	: r(r), g(g), b(b), a(a) {}

Color4::Color4(Color3 color3) noexcept
	: r(color3.r), g(color3.g), b(color3.b) {}

bool operator==(Color3 c1, Color3 c2) {
	return c1.r == c2.r && c1.b == c2.b && c1.g == c2.g;
}

bool operator==(Color4 c1, Color4 c2) {
	return c1.r == c2.r && c1.b == c2.b && c1.g == c2.g && c1.a == c2.a;
}

// Frame

Frame::Frame(size_t width, size_t height) noexcept
	: width_(width), height_(height), data_(width * height) {}

void Frame::setColor(const Eigen::Vector2<size_t>& pos, Color3 color) {
	data_[pos(1) * width_ + pos(0)] = color;
}

void Frame::setColor(size_t x, size_t y, Color3 color) {
	data_[y * width_ + x] = Color4(color);
}

Color3 Frame::getColor(const Eigen::Vector2<size_t>& pos) const {
	return data_[pos(1) * width_ + pos(0)];
}

Color3 Frame::getColor(size_t x, size_t y) const {
	return data_[y * width_ + x];
}

size_t Frame::getWidth() const { return width_; }

size_t Frame::getHeight() const { return height_; }

void Frame::clear(Color3 color) {
	for (auto& c : data_) {
		c = color;
	}
}

uint8_t* Frame::data() { return reinterpret_cast<uint8_t*>(data_.data()); }

// Renderer

void Renderer::operator()(Frame& frame) { frame.clear(Color3::BLUE); }

} // namespace r3d