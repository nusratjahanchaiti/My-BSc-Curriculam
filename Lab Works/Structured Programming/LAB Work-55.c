#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int lowerLimit, upperLimit;

    printf("Input lowest search limit of perfect numbers: ");
    scanf("%d", &lowerLimit);

    printf("Input highest search limit of perfect numbers: ");
    scanf("%d", &upperLimit);

    printf("The perfect numbers between %d to %d are: \n", lowerLimit, upperLimit);

    for (int i = lowerLimit; i <= upperLimit; i++) {
        if (isPerfect(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}

