#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int len1, len2, i, j, found = 0, not_found = 0;

    printf("Input the first String: ");
    scanf("%s", str1);

    printf("Input the second String: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 == len2) {
    for (i = 0; i < len1; i++) {
    found = 0;
    for (j = 0; j < len2; j++) {
    if (str1[i] == str2[j]) {
    found = 1;
    break;
    }
    }
    if (found == 0) {
    not_found = 1;
    break;
    }
    }
    if (not_found == 1) {
    printf("%s and %s are not Anagram.\n", str1, str2);
        } else {
            printf("%s and %s are Anagram.\n", str1, str2);
        }
    } else {
    printf("%s and %s are not Anagram.\n", str1, str2);
    }
    return 0;
}

