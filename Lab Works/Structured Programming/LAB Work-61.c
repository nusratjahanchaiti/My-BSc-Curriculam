#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char sentence[100];
    int i;

    printf("Input the string : ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    printf("The given sentence : %s\n", sentence);

    for (i = 0; sentence[i] != '\0'; i++) {
        if (islower(sentence[i])) {
            sentence[i] = toupper(sentence[i]);
        } else if (isupper(sentence[i])) {
            sentence[i] = tolower(sentence[i]);
        }
    }

    printf("After Case changed the string is: %s\n", sentence);

    return 0;
}

