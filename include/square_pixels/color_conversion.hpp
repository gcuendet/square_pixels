#pragma once

#include <square_pixels/image.hpp>

#include <cstdint>
#include <string>

std::string image2str(const Image<uint8_t> &image);

namespace detail
{
    int rgb_to_escape_color(uint8_t r, uint8_t g, uint8_t b);
}
