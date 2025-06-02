#include <stdio.h>

int main() {
    int id[4], bt[4], wt[4], tat[4];
    int i;
    float total_wt = 0, total_tat = 0;

    printf("Enter the Burst Times for 4 Processes:\n");
    for (i = 0; i < 4; i++) {
        id[i] = i + 1;
        printf("Process ID %d: ", id[i]);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < 4; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < 4; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", id[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = total_wt / 4;
    float avg_tat = total_tat / 4;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);

    return 0;
}


