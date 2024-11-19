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
    if (strcmp(unit, "bt") == 0) {
        return totalSizeInBits / 8;  // Convert bits to bytes
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeInBits / 8 / 1024;  // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeInBits / 8 / 1024 / 1024;  // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeInBits / 8 / 1024 / 1024 / 1024;  // Convert to gigabits
    } else {
        printf("Invalid unit: %s\n", unit);
        return -1;  // Return error for invalid unit
    }
}

int main() {
    int w, h, durationMovie, durationCredits, fps;
    char unit[10];

    // Get user input for video dimensions and duration
    printf("Enter the width of the image: ");
    scanf("%d", &w);
    printf("Enter the height of the image: ");
    scanf("%d", &h);
    printf("Enter the duration of the colored movie section (in seconds): ");
    scanf("%d", &durationMovie);
    printf("Enter the duration of the credits section (in seconds): ");
    scanf("%d", &durationCredits);
    printf("Enter the frames per second (fps): ");
    scanf("%d", &fps);
    printf("Enter the unit ('bt' for bytes, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits): ");
    scanf("%s", unit);

    // Calculate the size of the video
    float size = video(w, h, durationMovie, durationCredits, fps, unit);
    if (size != -1) {
        printf("The total video size is: %.2f %s\n", size, unit);
    }

    return 0;
}
