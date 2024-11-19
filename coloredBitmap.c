#include <string.h>
#include "config/coloredBitmap.h"
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
    if (strcmp(unit, "bt") == 0) { // 'bt' for bits
        return sizeInBits; // Return size in bits
    } else if (strcmp(unit, "ko") == 0) { // 'ko' for kilobytes
        return sizeInBits / 8 / 1024; // Convert bits to bytes, then bytes to kilobytes
    } else if (strcmp(unit, "mo") == 0) { // 'mo' for megabytes
        return sizeInBits / 8 / 1024 / 1024; // Convert bits to bytes, then bytes to megabytes
    } else if (strcmp(unit, "go") == 0) { // 'go' for gigabytes
        return sizeInBits / 8 / 1024 / 1024 / 1024; // Convert bits to bytes, then bytes to gigabytes
    } else {
        return 0; // E for an unrecognized unit
    }
}


