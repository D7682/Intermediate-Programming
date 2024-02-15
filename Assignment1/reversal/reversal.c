#include <stdio.h>
#include <string.h> // Include the string library to use the strlen function.

// Define the maximum length of the string. (allows us to change the length of the string easily)
#define MAX_LENGTH 32

void reversal(char str[MAX_LENGTH]) {
    int length = strlen(str)-1; // Subtract 1 to ignore the newline character
    int start = (length/2) == 0 ? length/2 : (length/2)+1; // start in the middle of the string.
    int end = length - 1;

    while (start < end) {
        // Skip newline characters
        while (start < end && str[start] == '\n') {
            start++;
        }
        while (start < end && str[end] == '\n') {
            end--;
        }

        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("Modified string: %s\n", str);
}

void waitForEnter() {
    printf("Press Enter to close.\n");
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


int main() {
    // Defined MAX_LENGTH at the top of the file to make it easier to change the length of the string.
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    
    if (fgets(input, MAX_LENGTH, stdin) == NULL || input[strlen(input) -1 ] != '\n') {
        printf("INVALID INPUT\n");
        waitForEnter();

        // Wait for the Enter key
        int enterKey;
        do {
            enterKey = getchar();
        } while (enterKey != '\n' && enterKey != EOF);
        return 1;
    }

    // Perform reversal
    reversal(input);

    waitForEnter();

    return 0;
}
