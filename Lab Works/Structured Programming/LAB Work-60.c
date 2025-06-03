#include <stdio.h>
#include <string.h>

int main() {
    char string[100], search[10];
    int i, count = 0;

    printf("Input the string : ");
    fgets(string, sizeof(string), stdin);

    string[strcspn(string, "\n")] = '\0';

    printf("The given string : %s\n", string);

    strcpy(search, "the");
    for (i = 0; search[i]; i++) {
        search[i] = tolower(search[i]);
    }

    for (i = 0; string[i]; i++) {
        char temp[10];
        int j, k;
        for (j = i, k = 0; string[j] && k < 3; j++, k++) {
            temp[k] = tolower(string[j]);
        }
        temp[k] = '\0';
        if (strcmp(temp, search) == 0) {
            count++;
        }
    }
    printf("The frequency of the word 'the' is %d\n", count);
    return 0;
}

