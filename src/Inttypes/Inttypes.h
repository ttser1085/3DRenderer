#pragma once

#include <cstdlib>
#include <inttypes.h>
#include <utility>

namespace inttypes {

// Bytes

using Byte = uint8_t;

// Screen size

using ScreenSize = uint32_t;

enum Width : ScreenSize;
enum Height : ScreenSize;

struct SizePair {
	Width x;
	Height y;
};

SizePair makeSizePair(ScreenSize w, ScreenSize h);

// Screen diff

using ScreenDiff = int32_t;

ScreenSize sum(ScreenSize s, ScreenDiff d);

ScreenDiff diff(ScreenSize s1, ScreenSize s2);

ScreenDiff abs(ScreenDiff d);

// Index

using Index = size_t;

} // namespace inttypes
