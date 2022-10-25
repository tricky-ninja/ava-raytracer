#include <iostream>
#include <Image.hpp>

int main()
{
  Image im(1080, 720);

  //  lower left corner is (0, 0)
  //  upper right corner is (1, 1)
  for (uint h = 0; h < im.getHeight(); h++)
  {
    for (uint w = 0; w < im.getWidth(); w++)
    {
      im.setPixel(w, h, Color( (double)h/im.getHeight(), (double)w/im.getWidth(), .5 ));
    }
  }
  im.generateImage("./main.ppm");
}