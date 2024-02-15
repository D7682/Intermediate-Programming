#include <stdio.h>

void swap_pointers(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {
    // Declare two integers, num1 and num2, then input values into each.
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Before swapping: %d %d\n", num1, num2);

    // Call the function and print the output.
    swap_pointers(&num1, &num2);

    // Print the integers after swapping the contents within memory.
    printf("After swapping: %d %d\n", num1, num2);

    return 0;
}
