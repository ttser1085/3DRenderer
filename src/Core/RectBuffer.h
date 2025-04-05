#pragma once

#include "Inttypes/Inttypes.h"

#include <vector>

namespace r3d {

template<typename T>
class RectBuffer {
protected:
	using Width = inttypes::Width;
	using Height = inttypes::Height;
	using SizePair = inttypes::SizePair;
	using Byte = inttypes::Byte;
	using Storage = std::vector<T>;

public:
	explicit RectBuffer(SizePair size)
		: size_(size), storage_(inttypes::area(size)) {}

	inline Width width() const noexcept { return size_.x; }

	inline Height height() const noexcept { return size_.y; }

	inline SizePair size() const noexcept { return size_; }

protected:
	const Byte* data() const {
		if (storage_.empty()) {
			return nullptr;
		}

		return reinterpret_cast<const Byte*>(storage_.data());
	}

	T& get(SizePair pos) {
		return storage_[inttypes::area(pos.y, size_.x) + pos.x];
	}

	const T& get(SizePair pos) const {
		return storage_[inttypes::area(pos.y, size_.x) + pos.x];
	}

	void clear(const T& value) {
		std::fill(storage_.begin(), storage_.end(), value);
	}

private:
	SizePair size_;
	Storage storage_;
};

} // namespace r3d
