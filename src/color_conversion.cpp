#include <square_pixels/color_conversion.hpp>

#include <stdexcept>

std::string image2str(const Image<uint8_t> &image)
{
  if (image.channels_count != 3)
    throw std::runtime_error("Only 3 channels (RGB) images are supported");

  std::string ret;
  for (size_t row = 0; row < image.height; row += 2)
  {
    for (size_t col = 0; col < image.width * image.channels_count; col += 3)
    {
      uint8_t r = image.data[(row * image.width * image.channels_count) + col];
      uint8_t g =
          image.data[(row * image.width * image.channels_count) + col + 1];
      uint8_t b =
          image.data[(row * image.width * image.channels_count) + col + 2];
      int ansi_last = detail::rgb_to_escape_color(r, g, b);

      r = image.data[((row + 1) * image.width * image.channels_count) + col];
      g = image
              .data[((row + 1) * image.width * image.channels_count) + col + 1];
      b = image
              .data[((row + 1) * image.width * image.channels_count) + col + 2];
      int ansi_now = detail::rgb_to_escape_color(r, g, b);
      ret += "\033[38;5;" + std::to_string(ansi_last) + "m\033[48;5;" +
             std::to_string(ansi_now) + "m▀\033[0m";
    }
    ret += "\n";
  }

  return ret;
}

namespace detail
{
  int rgb_to_escape_color(uint8_t r_in, uint8_t g_in, uint8_t b_in)
  {
    uint8_t r = r_in / 51;
    uint8_t g = g_in / 51;
    uint8_t b = b_in / 51;

    if (r == g && g == b)
    {
      if (r_in == 255)
        return 231;
      else if (r_in == 0)
        return 16;
      else
        return int((r_in / 255.f) * 24) + 232;
    }
    else
    {
      // Find the nearest neighbor in XTerms 6x6x6 color cube
      return 16 + r * 36 + g * 6 + b;
    }
  }
} // namespace detail
