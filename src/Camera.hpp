#pragma once

#include "Vector3.hpp"
#include "Ray.hpp"
#include "Image.hpp"

class Camera
{
public:
  Camera(const Image& im)
  {
    auto aspectRatio = im.aspectRatio;
    auto focalLength = 1.0;
    auto viewPortHeight = 2.0;
    auto viewPortWidth = viewPortHeight * aspectRatio;
    
    m_origin = Point3(0, 0, 0);
    m_horizontal = Vector3(viewPortWidth, 0, 0);
    m_vertical = Vector3(0, viewPortHeight, 0);
    m_lower_left_corner = m_origin - m_horizontal/2 - m_vertical/2 - Vector3(0,  0, focalLength);
  }

  Ray generateRay(const double x, const double y) const { return Ray(m_origin, m_lower_left_corner + x*m_horizontal + y*m_vertical - m_origin); }

private:
  Point3  m_origin;
  Point3  m_lower_left_corner;
  Vector3 m_horizontal;
  Vector3 m_vertical;
};