#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
long totalBits = (long)w * h * 24;
// Convert to the requested unit
    if (strcmp(unit, "bt") == 0) {
        // Return the size in bits (already calculated)
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
  
}