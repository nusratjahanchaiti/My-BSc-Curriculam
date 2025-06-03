#include <stdio.h>

int main() {
    int squares[101];

    for (int i = 0; i < 101; i++) {
        squares[i] = i * i;
    }

    for (int i = 0; i < 101; i++) {
        if (i < 10) {
            printf("0");
        }
        printf("%d ", squares[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }

    return 0;
}

