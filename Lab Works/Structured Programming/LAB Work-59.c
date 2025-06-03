#include <stdio.h>
#include <string.h>

int main() {
    char string[100], ch;
    int i, count = 0;

    printf("Input the string : ");
    fgets(string, sizeof(string), stdin);

    string[strcspn(string, "\n")] = '\0';

    printf("Input the character to find frequency : ");
    scanf("%c", &ch);

    printf("The given string : %s\n", string);

    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == ch) {
            count++;
        }
    }

    printf("The frequency of '%c' is %d\n", ch, count);

    return 0;
}

