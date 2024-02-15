#include <stdio.h>

// Define the target base for conversion.
// This program allows you to convert from base 10 to any other base easily by changing the value of TARGET_BASE.
#define TARGET_BASE 8

// Define color codes for output formatting. (used for testing)
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

void base_conversion(int base_ten_integer) {
    int target_base_integer = 0;
    int remainder;
    int position_multiplier = 1;

    while (base_ten_integer != 0) {
        // Store the remainder after division by the target base.
        remainder = base_ten_integer % TARGET_BASE;

        // Update the integer part of the quotient.
        base_ten_integer /= TARGET_BASE;

        // Add the product of remainder and positional value to the target_base_integer.
        target_base_integer += remainder * position_multiplier;
        position_multiplier *= 10;
    }

    printf("The base %d equivalent is: %d\n", TARGET_BASE, target_base_integer);
}

int main() {
    int base_ten_integer;
    
    // Prompt user for input
    printf("Enter an integer: ");
    
    // Read input and check for errors
    if (scanf("%d", &base_ten_integer) != 1) {
        printf("INVALID INPUT\n");
        return 1;
    }

    // Check if the input is a non-negative.
    if (base_ten_integer < 0) {
        printf("INVALID INPUT\n");
        return 1;
    }

    // Perform base conversion by calling our base_conversion function.
    base_conversion(base_ten_integer);

    // Uncomment this line to print the format specifier verification test.
    // printf(GREEN"[Format Specifier Verification Test]"RESET": base 10 equivalent in octal is %o\n", base_ten_integer);
    return 0;
}
