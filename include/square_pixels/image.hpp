#pragma once

#include <cstddef>
#include <filesystem>
#include <memory>

template <typename T>
struct Image
{
    Image(size_t w, size_t h, size_t num_channels)
        : width(w), height(h), channels_count(num_channels),
          row_stride(w * num_channels), col_stride(num_channels),
          channel_stride(1)
    {
        data = std::make_unique<T[]>(width * height * channels_count);
    }

    Image(size_t w, size_t h, size_t num_channels, size_t row_s, size_t col_s,
          size_t channel_s, T *raw_data)
        : width(w), height(h), channels_count(num_channels), row_stride(row_s),
          col_stride(col_s), channel_stride(channel_s)
    {
        data = std::make_unique<T[]>(width * height * channels_count);
        std::copy(raw_data, raw_data + width * height * channels_count, data.get());
    }

    size_t width;
    size_t height;
    size_t channels_count;
    size_t row_stride;
    size_t col_stride;
    size_t channel_stride;
    std::unique_ptr<T[]> data;
};

Image<uint8_t> load_image(const std::filesystem::path &filepath);

Image<uint8_t> resize_image(const Image<uint8_t> &image, size_t new_width,
                            size_t new_height);
