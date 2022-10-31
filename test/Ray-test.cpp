#include "gtest/gtest.h"
#include "Ray.hpp"


TEST(RayTest, atTimeTest)
{
  Ray ray(Point3(0, 0, 0), Vector3(1, 0, 0));
  ASSERT_EQ(ray.at(2), Point3(2, 0, 0));
}
