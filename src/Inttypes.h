#pragma once

#include <inttypes.h>
#include <cstdlib>
#include <utility>

namespace r3d {

using screen_size_t = uint32_t;

enum Width : screen_size_t;
enum Height : screen_size_t;

using SizePair = std::pair<Width, Height>;

using Index = size_t;

} // namespace r3d
