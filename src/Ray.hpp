#pragma once

#include "Vector3.hpp"

class Ray
{
public:
  Ray()
  {
  }
  Ray(const Vector3 &org, const Vector3 &direction) : origin(org), dir(normalise(direction))
  {
  }

  Point3 at(double time) const
  {
    return origin + dir * time;
  }

public:
  Point3 origin;
  Vector3 dir;
};