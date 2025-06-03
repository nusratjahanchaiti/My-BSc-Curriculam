#include <stdio.h>

int main() {
    char str[1000];
    int i, max = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (i > max) {
            max = i;
        }
    }

    printf("Maximum number of characters in the string: %d\n", max);

    return 0;
}

