#pragma once

#include "Camera.hpp"
#include "ObjectManager.hpp"

struct Scene
{
  Image img;
  Camera cam;
  ObjectManager obj();

  Scene(uint width, double aspectRatio) : img(width, aspectRatio), cam(img)
  {}
};