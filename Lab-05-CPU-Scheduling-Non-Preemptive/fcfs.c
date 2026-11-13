/*
 * Lab 5(a) - CPU Scheduling: First Come First Serve (FCFS).
 *
 * Input : n, then n lines of "pid arrival_time burst_time"
 * Output: per-process TAT / WT / RT (in pid order) and their averages.
 *
 * arr[i] = { pid, AT, BT, TAT, WT, RT }
 */
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int arr[n][6];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &arr[i][j]);

    /* Bubble sort by arrival time */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j][1] > arr[j + 1][1]) {
                for (int k = 0; k < 3; k++) {
                    int temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
    }

    int t = 0;
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][1] > t)          /* CPU idle until process arrives */
            t = arr[i][1];
        arr[i][4] = t - arr[i][1];                  /* WT  */
        arr[i][5] = arr[i][4];                      /* RT = WT (non-preemptive) */
        arr[i][3] = t + arr[i][2] - arr[i][1];      /* TAT */
        t += arr[i][2];
        avg_tat += arr[i][3];
        avg_wt += arr[i][4];
    }

    printf("PID\tAT\tBT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 1 == arr[j][0]) {
                printf("%d\t%d\t%d\t%d\t%d\t%d\n", arr[j][0], arr[j][1],
                       arr[j][2], arr[j][3], arr[j][4], arr[j][5]);
                break;
            }
        }
    }

    avg_tat /= n;
    avg_wt /= n;
    printf("Average Turnaround Time = %.2f\n", avg_tat);
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Response Time = %.2f\n", avg_wt);
    return 0;
}
