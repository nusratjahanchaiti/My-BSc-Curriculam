#include <stdio.h>

int main() {
    int i;
    int id[3], bt[3], wt[3], tat[3];
    float total_wt = 0, total_tat = 0;

    printf("Enter the Burst Times for 3 Processes:\n");
    for (i = 0; i < 3; i++) {
        id[i] = i + 1;
        printf("Process ID %d: ", id[i]);
        scanf("%d", &bt[i]);
    }

    // Sort by Burst Time (simple bubble sort)
    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp;
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = id[j]; id[j] = id[j + 1]; id[j + 1] = temp;
            }
        }
    }

    // Calculate WT and TAT
    wt[0] = 0;
    tat[0] = bt[0];
    for (int i = 1; i < 3; i++) {
       wt[i] = wt[i - 1] + bt[i - 1];
       tat[i] = bt[i] + wt[i];
    }

    // Output
    printf("\nPID\tBT\tWT\tTAT\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t%d\t%d\t%d\n", id[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / 3);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat /3 );

    return 0;
}


