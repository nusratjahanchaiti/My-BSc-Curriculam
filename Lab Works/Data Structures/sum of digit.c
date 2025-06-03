#include <stdio.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0; // initialize sum to 0
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int N;
    printf("Enter how many numbers: ");
    scanf("%d", &N);

    int results[N];

    for (int i = 0; i < N; i++) {
        int P;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &P);

        int totalSum = 0;
        for (int j = 1; j <= P; j++) {
            totalSum += sumOfDigits(j);
        }
        results[i] = totalSum;
    }

    printf("\nSum of digits from 1 to each number:\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}
