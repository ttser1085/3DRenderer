#pragma once

#include "Inttypes/Inttypes.h"

#include <vector>

namespace r3d {

template<typename T>
class RectBuffer {
protected:
	using Storage = std::vector<T>;

public:
	explicit RectBuffer(SizePair size, const T& value = T())
		: size_(size), storage_(area(size), value) {}

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

	T& get(SizePair pos) { return storage_[area(pos.y, size_.x) + pos.x]; }

	const T& get(SizePair pos) const {
		return storage_[area(pos.y, size_.x) + pos.x];
	}

	void clear(const T& value = T()) {
		std::fill(storage_.begin(), storage_.end(), value);
	}

private:
	SizePair size_;
	Storage storage_;
};

} // namespace r3d
