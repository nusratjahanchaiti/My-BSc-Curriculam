#include <stdio.h>
#include <stdlib.h>

void permute(int *arr, int l, int r, int *sum) {
    if (l == r) {
        int num = 0;
        for (int i = 0; i <= r; i++) {
            num = num * 10 + arr[i];
        }
        *sum += num;
    } else {
        for (int i = l; i <= r; i++) {

            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;


            permute(arr, l + 1, r, sum);

            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 1 || n > 9) {

        return 1;
    }

    int digits[n];
    for (int i = 0; i < n; i++) {
        digits[i] = i + 1;
    }

    int sum = 0;
    permute(digits, 0, n - 1, &sum);

    printf("%d", sum);

    return 0;
}
