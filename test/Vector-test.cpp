#include <gtest/gtest.h>
#include "Vector3.hpp"

TEST(VectorTest, relational)
{
  Vector3 a(1, 2, 2), b(1, 3, 2);
  ASSERT_TRUE(a == a);
  ASSERT_FALSE(a == b);

  ASSERT_TRUE(a != b);
  ASSERT_FALSE(a == b);
}

TEST(VectorTest, addSubtract)
{
  Vector3 a(2, 3, 6), b(4, 6, 6);
  ASSERT_EQ(a + b, Vector3(6, 9, 12));
  ASSERT_EQ(b + a, Vector3(6, 9, 12));
  ASSERT_EQ(b + Vector3(-1, -2, -3), Vector3(3, 4, 3));

  ASSERT_EQ(a - b, Vector3(-2, -3, 0));
  ASSERT_EQ(b - a, Vector3(2, 3, 0));
  ASSERT_EQ(b - Vector3(-1, -2, -3), Vector3(5, 8, 9));
}

TEST(VectorTest, multiplyDivide)
{
  Vector3 a(2, 3, 6), b(4, 6, 6);
  ASSERT_EQ(a * 2, Vector3(4, 6, 12));
  ASSERT_EQ(b * 3, Vector3(12, 18, 18));

  ASSERT_EQ(a / 3, Vector3(2.0 / 3.0, 1, 2));
  ASSERT_EQ(b / 2, Vector3(2, 3, 3));
  ASSERT_EQ(b / 0, Vector3(0,0,0));
}

TEST(VectorTest, length)
{
 { 
  Vector3 a(1, 0, 0), b(0, 2, 0), c(0, 0, 3.25);

  ASSERT_EQ(a.lengthSquare(), 1);
  ASSERT_EQ(b.lengthSquare(), 4);
  ASSERT_EQ(c.lengthSquare(), 3.25*3.25);

  ASSERT_EQ(a.length(), 1);
  ASSERT_EQ(b.length(), 2);
  ASSERT_EQ(c.length(), 3.25);
}

  Vector3 a(1, 3.2, 4.5), b(-2.0, 3.2,-5.23);
  ASSERT_EQ(a.length(), sqrt(31.49));
  ASSERT_EQ(b.length(), sqrt(41.5929));
}

TEST(VectorTest, normalise)
{
  Vector3 a(10, 0, 0), b(0, 2.3, 0), c(0, 0, 3.4);

  ASSERT_EQ(normalise(a), Vector3(1, 0, 0));
  ASSERT_EQ(normalise(b), Vector3(0, 1, 0));
  ASSERT_EQ(normalise(c), Vector3(0, 0, 1));
}

TEST(VectorTest, dotProduct)
{
  Vector3 a(1, 3, 2), b(2, 1, 2);
  ASSERT_EQ(a.dot(b), 9);
  ASSERT_EQ(b.dot(a), 9);
}

TEST(VectorTest, crossProduct)
{
  Vector3 a(1, 3, 2), b(2, 1, 2);
  ASSERT_EQ(a.cross(b), Vector3(4, 2, -5));
  ASSERT_EQ(b.cross(a), Vector3(-4, -2, 5));
}