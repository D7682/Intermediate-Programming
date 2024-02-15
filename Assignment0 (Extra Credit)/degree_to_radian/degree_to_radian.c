#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/* 
 * I was confused by the example output in the assignment, which stated
 * that 720 degrees should correspond to 6.28 radians, and it seemed to contradict 
 * the requirement that the output radians should be in the range of [0, 2π]. 
 * I implemented the function like this:
 * - I converted degrees to radians using the formula degrees * (M_PI / 180.0).
 * - Verify that radians are in the range [0, 2π] by adding 
 * - I wrote a function to convert degrees to radians considering complete revolutions in a unit circle,
 * - which I think is what the original example output was doing (720 degrees -> 6.28 radians).
 */

/*
// Function to convert degrees to radians considering complete revolutions
float degrees_to_complete_revolution_radians(float degrees) {
    // Calculate the number of complete revolutions
    int revolutions = degrees / 360;

    // Calculate the remaining angle after complete revolutions
    float remaining_degrees = degrees - revolutions * 360;

    // Convert the remaining angle to radians using degrees_to_radians function
    float remaining_radians = degrees_to_radians(remaining_degrees);

    // Convert the complete revolutions to radians (each complete revolution is 2π radians)
    float revolution_radians = revolutions * (2 * M_PI);

    // Combine the radians for complete revolutions with the radians for the remaining angle
    // to get the total radians considering complete revolutions
    return revolution_radians + remaining_radians;
}
*/

float degrees_to_radians(float degrees) {
    // Convert degrees to radians
    float radians = degrees * (M_PI / 180.0);

    // Ensure radians are in the range [0, 2π]
    while (radians < 0) {
        radians += 2 * M_PI;
    }
    while (radians >= 2 * M_PI) {
        radians -= 2 * M_PI;
    }

    return radians;
}

int main() {
    float angle_degrees;
    printf("Enter an angle in degrees: ");
    scanf("%f", &angle_degrees);

    float angle_radians = degrees_to_radians(angle_degrees);
    printf("Radians using degrees_to_radians: %.2f\n", angle_radians);
    
    
    // float angle_complete_revolution_radians = degrees_to_complete_revolution_radians(angle_degrees);
    // printf("Radians using degrees_to_complete_revolution_radians: %.4f\n", angle_complete_revolution_radians);

    return 0;
}
