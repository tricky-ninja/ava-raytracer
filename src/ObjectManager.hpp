#pragma once

#include "Hittable.hpp"
#include <memory>
#include <vector>

class ObjectManager : public Hittable
{
  public:
    ObjectManager() {}
    ObjectManager(std::shared_ptr<Hittable> object) { add(object); }

    void clear() { objects.clear(); }
    void add(std::shared_ptr<Hittable> object) { objects.push_back(object); }

    virtual bool hit(
        const Ray &ray, double tMin, double tMax, HitData& hitData) const override;

  private:
    std::vector<std::shared_ptr<Hittable>> objects;
};

bool ObjectManager::hit(const Ray &ray, double tMin, double tMax, HitData& hitData) const
{
  HitData temp;
  bool hit = false;
  auto closestHit = tMax;

  for (const auto &object : objects)
  {
    if (object->hit(ray, tMin, closestHit, temp))
    {
      hit = true;
      closestHit = temp.time;
      hitData = temp;
    }
  }

  return hit;
}
