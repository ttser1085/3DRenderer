#pragma once

#include <cstdlib>
#include <inttypes.h>
#include <utility>

#include <assert.h>
#include <functional>

namespace inttypes {

// Bytes

using Byte = uint8_t;

// Screen size

using ScreenSize = uint32_t;

enum Width : ScreenSize {};
enum Height : ScreenSize {};

struct SizePair {
	Width x;
	Height y;
};

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template<Arithmetic Tx, Arithmetic Ty>
SizePair makeSizePair(Tx x, Ty y) {
	assert(x >= 0 && y >= 0);
	return SizePair{static_cast<Width>(x), static_cast<Height>(y)};
}

// Screen diff

using ScreenDiff = int32_t;

enum SignedWidth : ScreenDiff {};
enum SignedHeight : ScreenDiff {};

struct DiffPair {
	SignedWidth x;
	SignedHeight y;
};

template<Arithmetic Tx, Arithmetic Ty>
DiffPair makeDiffPair(Tx x, Ty y) {
	return DiffPair{static_cast<SignedWidth>(x), static_cast<SignedHeight>(y)};
}

Width toUnsigned(SignedWidth w);
Height toUnsigned(SignedHeight h);

SizePair toSizePair(DiffPair dp);

// Index

using Index = size_t;

} // namespace inttypes
