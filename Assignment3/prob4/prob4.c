#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for a float array
float* allocate_float_array(int size) {
    float* array = (float*)malloc(sizeof(float) * size);
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    return array;
}

// Function to count the number of values in a string
int count_values(const char* input) {
    int count = 0;
    int in_number = 0;

    while (*input) {
        if ((*input >= '0' && *input <= '9') || *input == '-' || *input == '.') {
            if (!in_number) {
                in_number = 1;
                count++;
            }
        } else {
            in_number = 0;
        }
        input++;
    }

    return count;
}

// Function to parse a string of space-separated float values
// and dynamically allocate memory for the float array
float* parse_and_allocate(const char* input, int* size) {
    int count = count_values(input);

    // Allocate memory for the float array
    float* array = allocate_float_array(count);

    // Parse the string and store float values in the array
    for (int i = 0; i < count; i++) {
        sscanf(input, "%f", &array[i]);
        while (*input && ((*input >= '0' && *input <= '9') || *input == '-' || *input == '.')) {
            input++;
        }
        while (*input && (*input == ' ' || *input == '\t')) {
            input++;
        }
    }

    // Update the size
    *size = count;

    return array;
}

int main() {
    char input[1024]; // Allocated an input buffer of 1 kilobyte.
    int size_x, size_y, size_z;
    float *all_values[3]; // Array to hold pointers to x_values, y_values, and z_values

    // The value of the three dimensions of the array are taken as the user input from the terminal as requested.
    printf("Enter values for X: ");
    fgets(input, sizeof(input), stdin);
    all_values[0] = parse_and_allocate(input, &size_x);

    printf("Enter values for Y: ");
    fgets(input, sizeof(input), stdin);
    all_values[1] = parse_and_allocate(input, &size_y);

    printf("Enter values for Z: ");
    fgets(input, sizeof(input), stdin);
    all_values[2] = parse_and_allocate(input, &size_z);

    // Calculate the sum
    float sum = 0;
    for (int i = 0; i < size_x; i++) {
        sum += all_values[0][i];
    }

    for (int j = 0; j < size_y; j++) {
        sum += all_values[1][j];
    }

    for (int k = 0; k < size_z; k++) {
        sum += all_values[2][k];
    }

    // Print the sum
    printf("Sum of all values: %.2f\n", sum);
    
    for (int i = 0; i < 3; i++) {
        free(all_values[i]);
    }

    return 0;
}
