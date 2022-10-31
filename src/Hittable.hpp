#pragma once

#include "Vector3.hpp"
#include "Ray.hpp"

struct HitData
{
  Point3 pos;
  Vector3 normal;
  double time;
};

class Hittable
{
  public:
    virtual bool hit(const Ray &ray, double tMin, double tMax, HitData &hitData) const = 0;
};