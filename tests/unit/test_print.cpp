#include <gtest/gtest.h>

#include <square_pixels/color_conversion.hpp>
#include <square_pixels/image.hpp>

#include <cmath>
#include <filesystem>

TEST(DontTestBut, drawsColorCircle)
{
    std::filesystem::path image_path = "color_circle.png";
    const auto img = load_image(image_path);
    const auto rsz_img = resize_image(img, 120, 120);
    const std::string res = image2str(rsz_img);
    std::cout << res << std::endl;
    ASSERT_TRUE(true);
}

std::array<size_t, 2> compute_width_height(size_t max_width, size_t im_width,
                                           size_t im_height)
{
    float factor = float(max_width) / im_width;
    size_t new_width = static_cast<size_t>(std::round(factor * im_width));
    size_t new_height = static_cast<size_t>(std::round(factor * im_height));
    return {new_width, new_height};
}

TEST(DontTestBut, drawsADog)
{
    std::filesystem::path image_path = "Bouvier_Bernois_BE.jpeg";
    const auto img = load_image(image_path);

    size_t max_width = 150;
    const auto new_sz = compute_width_height(max_width, img.width, img.height);
    const auto rsz_img = resize_image(img, new_sz[0], new_sz[1]);
    const std::string res = image2str(rsz_img);
    std::cout << res << std::endl;
    ASSERT_TRUE(true);
}
