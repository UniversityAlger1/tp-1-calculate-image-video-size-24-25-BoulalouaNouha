#include "config/grayScaleImage.h"
#include <stdio.h>
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

int main() {
    int width, height;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    
    // Call the function and display the result
    float size = grayScaleImage(width, height);
    printf("grayScale size of the image Bitmap is: %.0f bytes\n", size);

    return 0;
}
