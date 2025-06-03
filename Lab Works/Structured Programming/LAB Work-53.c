#include <stdio.h>

void findMinMax(int arr[], int n, int *min, int *max);

int main() {
    int n, arr[100], i, min, max;

    printf("Input number of values: ");
    scanf("%d", &n);

    printf("Input %d values: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, n, &min, &max);

    printf("Minimum value is: %d\n", min);
    printf("Maximum value is: %d\n", max);

    return 0;
}

void findMinMax(int arr[], int n, int *min, int *max) {
    *min = *max = arr[0];

    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

