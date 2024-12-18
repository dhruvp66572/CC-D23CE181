#include <stdio.h>
#include <string.h>

// Function to validate the string against the pattern a*bb
int checkString(char str[]) {
    int i = 0;
    int string_len = strlen(str);

    // If string length is less than 2, it can't match a*bb
    if (string_len < 2) {
        return 0; // Invalid
    }

    // Check if the string ends with "bb"
    if (str[string_len - 1] != 'b' || str[string_len - 2] != 'b') {
        return 0; // Invalid
    }

    // Check the remaining characters (should only contain 'a')
    for (i = 0; i < string_len - 2; i++) {
        if (str[i] != 'a') {
            return 0; // Invalid
        }
    }

    return 1; // Valid
}

int main() {
    char str[100];

    printf("Enter String: ");
    scanf("%s", str);

    if (checkString(str)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
