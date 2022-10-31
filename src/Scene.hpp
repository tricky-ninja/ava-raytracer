#pragma once

#include "Camera.hpp"

struct Scene
{
  Image img;
  Camera cam;

  Scene(uint width, double aspectRatio) : img(width, aspectRatio), cam(img)
  {}
};