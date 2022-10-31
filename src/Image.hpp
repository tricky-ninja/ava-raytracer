#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Vector3.hpp"

class Image
{
public:

  Image(uint width, float aspRatio);

  ~Image();

  inline uint getHeight() const { return m_imgHeight; }
  inline uint getWidth() const { return m_imgWidth; }

  inline void setPixel(uint x, uint y, Color color)
  {
    if ((x > m_imgWidth) || (y>m_imgHeight)) return;
    image[y][x] = color;
  }

  void generateImage(const std::string &filename) const;

public:
  double aspectRatio;

private:
  uint m_imgWidth;
  uint m_imgHeight;
  Color **image;
};