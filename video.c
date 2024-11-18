#include <string.h>
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
   // YOUR CODE HERE - BEGIN
 // Calculate the size of the colored section
    long totalColoredBits = (long)w * h * 24 * durationMovie * fps;  // 24 bits per pixel (RGB)
    
    // Calculate the size of the black-and-white section (grayscale, 8 bits per pixel)
    long totalBwBits = (long)w * h * 8 * durationCredits * fps;  // 8 bits per pixel (grayscale)
    
    // Total size in bits
    long totalBits = totalColoredBits + totalBwBits;
    
    // Convert to the requested unit
    if (strcmp(unit, "bt") == 0) {
        // Return size in bits (already calculated)
        return (float)totalBits;
    } else if (strcmp(unit, "ko") == 0) {
        // Convert bits to kilobits (1 kilobit = 1024 bits)
        return (float)(totalBits / 1024);
    } else if (strcmp(unit, "mo") == 0) {
        // Convert bits to megabits (1 megabit = 1024 kilobits)
        return (float)(totalBits / (1024 * 1024));
    } else if (strcmp(unit, "go") == 0) {
        // Convert bits to gigabits (1 gigabit = 1024 megabits)
        return (float)(totalBits / (1024 * 1024 * 1024));
    } else {
        // If an unknown unit is passed, return 0 or handle as needed
        return 0.0;
    }
   // YOUR CODE HERE - END
   return 0;
}