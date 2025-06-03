#include <stdio.h>

int isArmstrong(int num) {
    int digit, sum = 0, temp = num;
    while (temp > 0) {
        digit = temp % 10;
        sum += (digit * digit * digit);
        temp /= 10;
    }
    if (num == sum) {
        return 1;
    } else {
        return 0;
    }
}
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
    int num;

    printf("Input any number: ");
    scanf("%d", &num);
    if (isArmstrong(num)) {
        printf("The %d is an Armstrong number. ", num);
    } else {
        printf("The %d is not an Armstrong number. ", num);
    }

    if (isPerfect(num)) {
        printf("The %d is a Perfect number.", num);
    } else {
        printf("The %d is not a Perfect number.", num);
    }
    return 0;
}

