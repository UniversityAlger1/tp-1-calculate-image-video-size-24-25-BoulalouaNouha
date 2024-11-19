#include "config/grayScaleImage.h"

// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
       // Each pixel is encoded in 8 bits (1 byte)
    // The size in bytes is simply width * height
    return (float)(w * h);
}


