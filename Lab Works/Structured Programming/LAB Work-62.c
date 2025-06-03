#include <stdio.h>
#include <string.h>

int main() {
    char string[100], substring[20];
    int i, j, flag;

    printf("Input the string : ");
    fgets(string, sizeof(string), stdin);
    printf("Input the substring to be searched : ");
    fgets(substring, sizeof(substring), stdin);

    string[strcspn(string, "\n")] = '\0';
    substring[strcspn(substring, "\n")] = '\0';

    int len1 = strlen(string);
    int len2 = strlen(substring);

    for (i = 0; i <= len1 - len2; i++) {
        flag = 1;
        for (j = 0; j < len2; j++) {
            if (string[i+j] != substring[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            printf("The substring exists in the string.\n");
            return 0;
        }
    }
    printf("The substring does not exist in the string.\n");
    return 0;
}

