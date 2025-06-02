#include <stdio.h>
#include <string.h>
/* Utility function to get max of 2 integers */
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
/* Function to find the LCS and its length */
void lcs(char* X, char* Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;
    // Build the LCS table
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    // Length of LCS
    int length = L[m][n];
    // Backtrack to find the LCS string
    char lcs[length + 1];
    lcs[length] = '\0'; // Null-terminate the string
    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[--length] = X[i - 1]; // Add character to LCS and move diagonally
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }
    // Print the LCS and its length
    printf("LCS: %s\n", lcs);
    printf("Length of LCS is %d\n", L[m][n]);
}
/* Driver program to test the function */
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    lcs(X, Y, m, n);
    return 0;
}
