#include "gtest/gtest.h"
#include "Image.hpp"


TEST(ImageTest, heightWidth)
{
Image im(3, 2);
  ASSERT_EQ(im.getWidth(), 3);
  ASSERT_EQ(im.getHeight(), 2);
  
  for (uint h = 0; h<im.getHeight(); h++)
  {
    for (uint w = 0; w<im.getWidth(); w++)
    {
      im.setPixel(w, h, Color(0, (h+1)/255.0, 0));
      
    }
  }
  im.generateImage("./test.ppm");
}