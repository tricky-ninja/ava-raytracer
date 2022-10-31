#include <iostream>
#include "Camera.hpp"
#include "Scene.hpp"

Color blueSky(const Ray &ray)
{
  auto t = 0.5 * (ray.dir.y + 1.0);
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main()
{

  Scene testScene(1080, 1.5);

  //  lower left corner is (0, 0)
  //  upper right corner is (1, 1)
  for (uint h = 0; h < testScene.img.getHeight(); h++)
  {
    for (uint w = 0; w < testScene.img.getWidth(); w++)
    {
      auto x = double(w) / (testScene.img.getWidth() - 1);
      auto y = double(h) / (testScene.img.getHeight() - 1);
      auto ray = testScene.cam.generateRay(x, y);
      testScene.img.setPixel(w, h, blueSky(ray));
    }
  }
  testScene.img.generateImage("./main.ppm");
}