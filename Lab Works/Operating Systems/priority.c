#include <stdio.h>

int main() {
    int id[3], bt[3], pr[3], wt[3], tat[3];
    float total_wt = 0, total_tat = 0;

  printf("Enter the Burst Times for 3 Processes:\n");
    for (int i = 0; i < 3; i++) {
        id[i] = i + 1;
        printf("Process ID %d: ", id[i]);
        scanf("%d", &bt[i]);

        printf("Enter Priority for Process %d: ", id[i]);
        scanf("%d", &pr[i]);
    }

    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (pr[j] > pr[j + 1]) {
                int temp;
                temp = pr[j]; pr[j] = pr[j + 1]; pr[j + 1] = temp;
                temp = bt[j];bt[j] = bt[j + 1];bt[j + 1] = temp;
                temp = id[j];id[j] = id[j + 1];id[j + 1] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[0];

    for (int i = 1; i < 3; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }
    printf("\nPID\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n", id[i], bt[i], pr[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / 3);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / 3);

    return 0;
}
