# Square pixels

Inspired by
["(Almost) square pixels in the terminal"](https://www.uninformativ.de/blog/postings/2016-12-17/0/POSTING-en.html),
this repo implements a method to draw images directly in the terminal with
colors and... square pixels.

It relies on the famous
[stb single-file public domain libraries](https://github.com/nothings/stb)
for C/C++, and in particular the [stb image loader](src/stb_image.hpp) and the
[stb image resizer](src/stb_image_resize.hpp) to provide basic image
manipulation utilities.

## Examples

![original image](tests/resources/Bouvier_Bernois_BE.jpeg)

![result in the terminal](tests/resources/Bouvier_Bernois_BE_screenshot.png)

![original image](tests/resources/color_circle.png)

![result in the terminal](tests/resources/color_circle_screenshot.png)

These examples can be reproduced by compiling and running the unit tests.

## How to build

```
cmake -S. -Bbuild [-DBUILD_SHARED_LIBS=ON]
cmake --build build
# Optionnaly run the tests/examples
[cmake --build build --target test]
```
