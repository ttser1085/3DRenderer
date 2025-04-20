#include "Vertex.h"
#include "ZBuffer.h"

#include <memory>

namespace r3d {

template<typename T>
concept Test = requires(T t, SizePair pos, const Vertex& vertex) {
	{ t(pos, vertex) } -> std::same_as<bool>;
};

template<Test T>
auto negation(T&& test) {
	return [test = std::forward<T>(test)](
			   SizePair pos, const Vertex& vertex) mutable -> bool {
		return !test(pos, vertex);
	};
}

template<Test... Ts>
auto conjunction(Ts&&... tests) {
	return [... tests = std::forward<Ts>(tests)](
			   SizePair pos, const Vertex& vertex) mutable -> bool {
		return (tests(pos, vertex) && ...);
	};
}

template<Test... Ts>
auto disjunction(Ts&&... tests) {
	return [... tests = std::forward<Ts>(tests)](
			   SizePair pos, const Vertex& vertex) mutable -> bool {
		return (tests(pos, vertex) || ...);
	};
}

// Common tests:

class BorderTest {
	using SizePair = SizePair;

public:
	BorderTest(SizePair left_top, SizePair size)
		: left_top_(left_top), size_(size) {}

	bool operator()(SizePair pos, const Vertex&) {
		return pos.x >= left_top_.x && pos.y >= left_top_.y &&
			   pos.x < left_top_.x + size_.x && pos.y <= left_top_.y + size_.y;
	}

private:
	SizePair left_top_;
	SizePair size_;
};

class DepthTest {
public:
	DepthTest(SizePair size) : zbuff_(std::make_unique<ZBuffer>(size)) {}

	bool operator()(SizePair pos, const Vertex& vertex) {
		return zbuff_->set(pos, vertex.pos(2));
	}

private:
	std::unique_ptr<ZBuffer> zbuff_;
};

// class AlphaTest {
// public:
// 	AlphaTest(linalg::Float threshold) : threshold_(threshold) {}

// 	bool operator()(inttypes::SizePair pos, const Vertex& vertex) {
// 		return vertex.color.a > threshold_;
// 	}

// private:
// 	linalg::Float threshold_;
// };

} // namespace r3d
