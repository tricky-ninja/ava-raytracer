#pragma once

#include <string>
#include <iostream>
#include <fstream>

// Just a temporary struct, will replace with a more versatile class
struct Color
{
  double red, green, blue;
  Color()
  {
    red = 0;
    green = 0;
    blue = 0;
  }
  Color(double r, double g, double b)
  {
    red = r;
    green = b;
    blue = g;

  }
};

class Image
{
public:

  Image(uint width, uint height);

  ~Image();

  inline uint getHeight() const { return m_imgHeight; }
  inline uint getWidth() const { return m_imgWidth; }

  inline void setPixel(uint x, uint y, Color color)
  {
    if ((x > m_imgWidth) || (y>m_imgHeight)) return;
    image[y][x] = color;
  }

  void generateImage(const std::string &filename) const;

private:
  uint m_imgWidth;
  uint m_imgHeight;
  Color **image;
};