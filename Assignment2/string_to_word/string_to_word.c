#include <stdio.h>

int string_to_word(char* str, char** words) {
    int count = 0;
    while (*str != '\0') {
        while (*str == ' ') {
            *str = '\0';
            str++;
        }
        if (*str != '\0') {
            words[count++] = str;
            while (*str != '\0' && *str != ' ') {
                str++;
            }
        }
    }
    return count;
}

int main() {
    char str[100];
    char* words[50];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline
    for (int i = 0; i < sizeof(str); i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    int count = string_to_word(str, words);

    printf("%d word(s) found.\n", count);

    return 0;
}
