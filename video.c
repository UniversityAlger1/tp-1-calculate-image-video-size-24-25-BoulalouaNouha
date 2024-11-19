#include <string.h>
#include <stdio.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
       // Calculate the frame sizes
    float sizePerColoredFrame = w * h * 24;   // Size of one colored frame in bits (24 bits per pixel)
    float sizePerBWFrame = w * h * 8;         // Size of one BW frame in bits (8 bits per pixel)

    // Calculate total frames for each section
    int totalColoredFrames = durationMovie * fps;
    int totalBWFrames = durationCredits * fps;

    // Calculate total video size in bits
    float totalSizeInBits = (totalColoredFrames * sizePerColoredFrame) + (totalBWFrames * sizePerBWFrame);

  // Conversion based on the unit specified
    if (strcmp(unit, "bt") == 0) { // 'bt' for bytes
        return totalSizeInBits / 8; // Convert bits to bytes
    } else if (strcmp(unit, "ko") == 0) { // 'ko' for kilobytes
        return totalSizeInBits / 8 / 1024; // Convert bits to bytes, then bytes to kilobytes
    } else if (strcmp(unit, "mo") == 0) { // 'mo' for megabytes
        return totalSizeInBits / 8 / 1024 / 1024; // Convert bits to bytes, then bytes to megabytes
    } else if (strcmp(unit, "go") == 0) { // 'go' for gigabytes
        return totalSizeInBits / 8 / 1024 / 1024 / 1024; // Convert bits to bytes, then bytes to gigabytes
    } else {
        return 0; // invalid unit
    }
}


