#include <square_pixels/image.hpp>

#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.hpp"

Image<uint8_t> load_image(const std::filesystem::path &filepath)
{
  if (!std::filesystem::exists(filepath))
  {
    throw std::invalid_argument("Image file " + filepath.string() + " does not exist!");
  }

  int x, y, n;
  unsigned char *data = stbi_load(filepath.string().c_str(), &x, &y, &n, 0);

  if (n != 3)
  {
    throw std::runtime_error("Only 3 channels images are supported");
  }

  Image<uint8_t> res(x, y, n, x * n, n, 1, data);
  stbi_image_free(data);

  return res;
}

Image<uint8_t> resize_image(const Image<uint8_t> &image, size_t new_width,
                            size_t new_height)
{
  Image<uint8_t> new_img(new_width, new_height, image.channels_count);
  // Medium API
  // stbir_edge edge_wrap_mode = STBIR_EDGE_CLAMP;
  // stbir_filter filter = STBIR_FILTER_MITCHELL; //STBIR_FILTER_TRIANGLE;
  // stbir_colorspace space = STBIR_COLORSPACE_LINEAR;
  // stbir_resize_uint8_generic(image.data.get(), image.width, image.height, 0,
  //                            new_img.data.get(), new_img.width,
  //                            new_img.height, 0, image.channels_count, -1, 0,
  //                            edge_wrap_mode, filter, space,
  //                            nullptr);
  stbir_resize_uint8(image.data.get(), image.width, image.height,
                     image.row_stride, new_img.data.get(), new_img.width,
                     new_img.height, new_img.row_stride, 3);

  return new_img;
}