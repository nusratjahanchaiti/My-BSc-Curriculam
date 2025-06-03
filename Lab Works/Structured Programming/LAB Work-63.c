#include <stdio.h>
#include <string.h>

int main() {
    char str[1000], substr[1000];
    int pos, len, i;

    printf("Input the string: ");
    fgets(str, sizeof(str), stdin);
    printf("Input the position to start extraction: ");
    scanf("%d", &pos);
    printf("Input the length of substring: ");
    scanf("%d", &len);

    for (i = 0; i < len && str[pos + i] != '\0'; i++) {
        substr[i] = str[pos + i];
    }
    substr[i] = '\0';

    printf("The substring retrieved from the string is \"%s\"\n", substr);

    return 0;
}

