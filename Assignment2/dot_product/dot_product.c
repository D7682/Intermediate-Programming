#include <stdio.h>

// dot_product takes in two arrays of floating-point numbers and their size
// we assume that the size of the arrays has been verified already in the main function.
float dot_product(float *arr1, float *arr2, int size) {
    float result = 0;
    float *ptr1 = arr1; // Pointer to the beginning of arr1
    float *ptr2 = arr2; // Pointer to the beginning of arr2
    
    /*
    The loop iterates through each element of each array pointed to by ptr1 and ptr2,
    we then actually multiply the two values together and add it to the result repeatedly. 
    Finally, we increase ptr1 and ptr2 to point to the next element of arr1 and arr2.
    */
    for (int i = 0; i < size; i++) {
        result += (*ptr1) * (*ptr2); // Dereference the pointers (Get the value) and multiply.
        ptr1++;
        ptr2++;
    }
    
    return result;
}

void clear() {
    // Clear the terminal screen using ANSI escape sequence, since I may
    // not be allowed to use system("clear") in the final submission
    // because it imports the stdlib library.
    printf("\033[2J\033[H");
}

void print_array(float *arr, int size) {
    printf("> ");
    for (int i = 0; i < size; i++) { 
        printf("%.2f", arr[i]);
    }
    printf("\n");
}

int main() {
    // Define two float arrays of size 6
    float arr1[6], arr2[6];
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    // First we implement our verification logic to ensure that the two arrays are of equal size.
    if (size1 != size2) {
        printf("SIZE MISMATCH\n");
        return 1;
    }

    // Read in array1
    printf("Enter %d floating-point numbers separated by spaces: ", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%f", &arr1[i]);
    }
    clear();
    print_array(arr1, size1);

    // Read in array2
    printf("Enter %d floating-point numbers separated by spaces: ", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%f", &arr2[i]);
    }
    clear();

    // Display the array contents appropriately.
    print_array(arr1, size1);
    print_array(arr2, size2);

    // Calculate dot product
    float result;
    result = dot_product(arr1, arr2, size1);

    // Display the result
    printf("Dot product: %.2f\n", result);

    return 0;
}
