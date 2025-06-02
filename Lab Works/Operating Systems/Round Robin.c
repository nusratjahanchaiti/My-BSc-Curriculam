#include <stdio.h>

int main() {
    int n = 3;
    int id[3], at[3], bt[3], rt[3];  // Process ID, Arrival Time, Burst Time, Remaining Time
    int wt[3] = {0}, tat[3] = {0};
    int tq;
    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("Enter Arrival Time for Process %d: ", id[i]);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for Process %d: ", id[i]);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0;
    int done = 0;
    while (done < n) {
        int all_idle = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                all_idle = 0;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i];
                    tat[i] = wt[i] + bt[i];
                    rt[i] = 0;
                    done++;
                }
            }
        }
        if (all_idle) time++;
    }
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", id[i], at[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}


