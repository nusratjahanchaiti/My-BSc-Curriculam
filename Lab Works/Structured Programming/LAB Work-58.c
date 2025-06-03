#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Input the first string: ");
    fgets(str1, sizeof(str1), stdin);

    str1[strcspn(str1, "\n")] = '\0';

    printf("Input the second string: ");
    fgets(str2, sizeof(str2), stdin);

    str2[strcspn(str2, "\n")] = '\0';

    int i, j = 0;
    for (i = 0; str1[i] != '\0'; i++) {
        printf("%c", str1[i]);
    }
    printf(" ");
    for (j = 0; str2[j] != '\0'; j++) {
        printf("%c", str2[j]);
    }

    return 0;
}

