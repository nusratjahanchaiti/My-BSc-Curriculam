#include <stdio.h>

int main() {
    int m, n;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int matrix[100][100]; // Adjust size as needed
    int row_sum[100] = {0}, col_sum[100] = {0};
    int total_sum = 0;

    // Input matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate row sums
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            row_sum[i] += matrix[i][j];
        }
        total_sum += row_sum[i];
    }

    // Calculate column sums
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            col_sum[j] += matrix[i][j];
        }
    }

    // Print results
    printf("\nRow sums:\n");
    for (int i = 0; i < m; i++) {
        printf("Row %d sum = %d\n", i + 1, row_sum[i]);
    }

    printf("\nColumn sums:\n");
    for (int j = 0; j < n; j++) {
        printf("Column %d sum = %d\n", j + 1, col_sum[j]);
    }

    printf("\nTotal sum of all elements = %d\n", total_sum);

    return 0;
}



