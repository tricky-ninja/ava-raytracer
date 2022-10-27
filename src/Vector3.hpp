#pragma once
#include <ostream>
#include <cmath>


class Vector3
{
public:
  Vector3() : x(0), y(0), z(0) {}
  Vector3(double x, double y, double z) : x(x), y(y), z(z){};

  inline bool operator==(const Vector3 &other) const
  {
    return x == other.x && y == other.y && z == other.z;
  }

  inline bool operator!=(const Vector3 &other) const
  {
    return x != other.x || y != other.y || z != other.z;
  }

  inline Vector3 &operator+=(const Vector3 &v)
  {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  inline Vector3 &operator*=(const double k)
  {
    x += k;
    y += k;
    z += k;
    return *this;
  }

  inline Vector3 &operator/=(const double k)
  {
    if (k == 0)
    {
      std::cout << "Division by 0\n";
      return *this;
    }
    return *this *= 1 / k;
  }

  inline Vector3 operator-() const { return Vector3(-x, -y, -z); }

  inline Vector3 operator+(const Vector3 &other) const { return Vector3(x + other.x, y + other.y, z + other.z); }

  inline Vector3 operator-(const Vector3 &other) const { return Vector3(x - other.x, y - other.y, z - other.z); }

  inline Vector3 operator*(const Vector3 &other) const { return Vector3(x * other.x, y * other.y, z * other.z); }

  double operator[](int index) const
  {
    switch (index)
    {
    case 0:
      return x;
      break;

    case 1:
      return y;
      break;

    case 2:
      return z;
      break;

    default:
      std::cout << "Inavalid index " << index << "\n";
      return 0.0;
      break;
    }
  }

  inline double length() const { return sqrt(lengthSquare()); }

  inline double lengthSquare() const { return x*x + y*y + z*z;}

  inline double dot(const Vector3& other)
  {
    return x*other.x + y*other.y + z*other.z;
  }

  inline Vector3 cross(const Vector3& other)
  {
    return Vector3(y * other.z - z * other.y,
                   z * other.x - x * other.z,
                   x * other.y - y * other.x);
  }

public:
  double x, y, z;
};

inline std::ostream &operator<<(std::ostream &out, const Vector3 &v) { return out << "(" << v.x << "," << v.y << "," << v.z << ")"; }

inline Vector3 operator*(double k, const Vector3 &v) { return Vector3(k * v.x, k * v.y, k * v.z); }

inline Vector3 operator*(const Vector3 &v, double k) { return k * v; }

inline Vector3 operator/(Vector3 v, double k) {
    if (k == 0) {
      std::cout<<"Division by 0\n";
      return Vector3(0,0,0);
    }
   return (1 / k) * v; 
}

inline Vector3 operator/(double k, Vector3 v) { return v / k; }

inline Vector3 normalise(const Vector3 &v) {return v/v.length();}

using Point3 = Vector3;
using Color = Vector3;