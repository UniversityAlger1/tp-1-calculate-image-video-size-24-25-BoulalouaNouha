#include <string.h>
#include "config/coloredBitmap.h"
#include <stdio.h>
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) { 
      // Each colored pixel occupies 24 bits (3 bytes)
    float sizeInBits = w * h * 24;
   // Conversion based on the specified unit
    if (strcmp(unit, "bt") == 0) {
        return sizeInBits; // Return directly in bits
    } else if (strcmp(unit, "kb") == 0) { // 'kb' for kilobits
        return sizeInBits / 1024;
    } else if (strcmp(unit, "mb") == 0) { // 'mb' for megabits
        return sizeInBits / (1024 * 1024);
    } else if (strcmp(unit, "gb") == 0) { // 'gb' for gigabits
        return sizeInBits / (1024 * 1024 * 1024);
    } else {
        printf("Invalid unit: %s\n", unit);
        return -1; // Error for an unrecognized unit
    }
}


int main() {
    int width, height;
    char unit[10];

    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the unit ('bt' for bits, 'kb' for kilobits, 'mb' for megabits, 'gb' for gigabits): ");
    scanf("%s", unit);


    float size = coloredBitmap(width, height, unit);
    if (size != -1) {
        printf("The size of the colored image is: %.2f %s\n", size, unit);
    }

    return 0;
}
