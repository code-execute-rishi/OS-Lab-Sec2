/*
 * Lab 5(b) - CPU Scheduling: Shortest Job First (SJF, non-preemptive).
 *
 * Input : n, then n lines of "pid arrival_time burst_time"
 * Output: per-process TAT / WT / RT (in input order) and their averages.
 *
 * arr[i] = { pid, AT, BT, TAT, WT, RT, done }
 * Ties on burst time are broken by arrival time, then by pid.
 */
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int arr[n][7];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            scanf("%d", &arr[i][j]);
        arr[i][6] = 0;
    }

    int t = 0;
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        int curr = -1;
        for (int j = 0; j < n; j++) {
            if (arr[j][6] == 1)
                continue;
            if (curr == -1) {
                curr = j;
                continue;
            }
            if (arr[curr][1] > t && arr[j][1] <= t) {
                /* j has arrived, curr has not */
                curr = j;
            } else if (arr[curr][1] <= t && arr[j][1] <= t) {
                /* both arrived: shortest burst, then earliest arrival, then lowest pid */
                if (arr[curr][2] > arr[j][2])
                    curr = j;
                else if (arr[curr][2] == arr[j][2] && arr[curr][1] > arr[j][1])
                    curr = j;
                else if (arr[curr][2] == arr[j][2] && arr[curr][1] == arr[j][1] &&
                         arr[curr][0] > arr[j][0])
                    curr = j;
            } else if (arr[curr][1] > t && arr[j][1] > t) {
                /* neither arrived: pick the one that arrives first */
                if (arr[curr][1] > arr[j][1])
                    curr = j;
            }
        }

        if (arr[curr][1] > t)
            t = arr[curr][1];
        arr[curr][4] = t - arr[curr][1];            /* WT  */
        arr[curr][5] = arr[curr][4];                /* RT = WT (non-preemptive) */
        arr[curr][3] = arr[curr][4] + arr[curr][2]; /* TAT */
        t += arr[curr][2];
        avg_tat += arr[curr][3];
        avg_wt += arr[curr][4];
        arr[curr][6] = 1;
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("PID\tAT\tBT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2],
               arr[i][3], arr[i][4], arr[i][5]);

    printf("Average Turnaround Time = %.2f\n", avg_tat);
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Response Time = %.2f\n", avg_wt);
    return 0;
}
