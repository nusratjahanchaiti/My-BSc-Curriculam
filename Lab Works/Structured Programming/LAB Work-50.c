#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &rows, &cols);

    int arr[rows][cols];
    printf("Enter array elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        int row_sum = 0;
        for (int j = 0; j < cols; j++) {
            row_sum += arr[i][j];
        }
        printf("Sum of row %d: %d\n", i, row_sum);
        printf("Average of row %d: %.1f\n", i, (float)row_sum / cols);
    }

    for (int j = 0; j < cols; j++) {
        int col_sum = 0;
        for (int i = 0; i < rows; i++) {
            col_sum += arr[i][j];
        }
        printf("Sum of column %d: %d\n", j, col_sum);
        printf("Average of column %d: %.1f\n", j, (float)col_sum / rows);
    }

    return 0;
}

