#include <stdio.h>

#define MAX_LENGTH 32

void swapping(float arr1[MAX_LENGTH], float arr2[MAX_LENGTH]) {
    int len1 = MAX_LENGTH;
    int len2 = MAX_LENGTH;
    if (len1 != len2) {
        printf("SIZE MISMATCH\n");
        return;
    }

    printf("Array 1 (before swap): ");
    for (int i = 0; i < len1; i++) {
        printf("%.2f ", arr1[i]);
    }
    printf("\n");

    printf("Array 2 (before swap): ");
    for (int i = 0; i < len2; i++) {
        printf("%.2f ", arr2[i]);
    }
    printf("\n");

    float temp[32];
    for (int i = 0; i < len1; i++) {
        temp[i] = arr1[i];
        arr1[i] = arr2[len2 - 1 - i];
    }

    for (int i = 0; i < len2; i++) {
        arr2[i] = temp[i];
    }

    printf("Array 1 (after swap): ");
    for (int i = 0; i < len1; i++) {
        printf("%.2f ", arr1[i]);
    }
    printf("\n");

    printf("Array 2 (after swap): ");
    for (int i = 0; i < len2; i++) {
        printf("%.2f ", arr2[i]);
    }
    printf("\n");
}

int main() {
    float arr1[MAX_LENGTH] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float arr2[MAX_LENGTH] = {6.0, 7.0, 8.0, 9.0, 10.0};

    swapping(arr1, arr2);

    return 0;
}
