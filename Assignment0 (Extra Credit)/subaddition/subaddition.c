#include <stdio.h>

#define SIZE 6

float subaddition(float arr1[SIZE], float arr2[SIZE], int arrSize) {
    float result;
    for (int i = 0; i < arrSize; i++) {
        // Add the values of arr1 and arr2 if hte index is even; otherwise, subtract for not even (i.e., odd) indices.
        if (i%2 == 0) {
            result -= arr1[i] + arr2[i];
            continue;
        }
        result += arr1[i] + arr2[i];

        // Uncomment the following line to use a ternary operator instead of the if-else statement above.
        // result += (i%2 == 0) ? -(arr1[i]+arr2[i]) : arr1[i]+arr2[i];
    }

    return result;
}

int main() {
    float arr1[SIZE];
    float arr2[SIZE];

    printf("Enter 12 numbers: ");

    // Reading all 12 numbers and storing in the arrays.
    for (int i = 0; i < SIZE*2; i++) {
        // Using a ternary operator to shorten the if-else statement.
        scanf("%f", i < SIZE ? &arr1[i] : &arr2[i-SIZE]);
    }

    float result = subaddition(arr1, arr2, SIZE);

    // Printing the result in the same manner as the example run.
    // I printed it with 0 precision because of the Example run.
    // But I can change it to 2 decimal places by changing the format specified %0f to %.2f.
    // But the example run has 0 decimal places, so I kept it that way.
    printf("%.0f", result);

    return 0;
}
