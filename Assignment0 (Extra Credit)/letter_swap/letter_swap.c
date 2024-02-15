#include <stdio.h>
#include <string.h>

#define SIZE 50

int main() {
    char str[SIZE]; // String with space for 32 characters plus null terminator
    int index1, index2;

    printf("Enter a string (up to 32 characters): ");
    if (fgets(str, SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; // Exit with error code
    }

    if ((strlen(str)-1 > 32) || (strlen(str) == 1)) {
        printf("String too long or too short.\n");
        return 1;
    }

    printf("Enter index 1: ");
    scanf("%d", &index1);
    printf("Enter index 2: ");
    scanf("%d", &index2);

    // Validate the indices.
    int minIndex = 0;
    int maxIndex = strlen(str) - 1;
    if (index1 < minIndex || index2 < minIndex || index1 > maxIndex || index2 > maxIndex) {
        printf("Invalid index.\n");
        return 1;
    }

    // Swap characters
    char temp = str[index1];
    str[index1] = str[index2];
    str[index2] = temp;

    printf("%s\n", str);

    return 0;
}
