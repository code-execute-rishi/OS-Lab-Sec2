// Lab 5(b): CPU scheduling algorithm - SJF

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int pid[n], at[n], bt[n], tat[n], wt[n], fin[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        fin[i] = 0;
    }

    int t = 0, done = 0;
    float a = 0, b = 0;
    while (done < n) {
        // pick the arrived process with the shortest burst (tie: earlier arrival)
        int c = -1;
        for (int i = 0; i < n; i++)
            if (!fin[i] && at[i] <= t &&
                (c == -1 || bt[i] < bt[c] || (bt[i] == bt[c] && at[i] < at[c])))
                c = i;

        if (c == -1) {          // nothing has arrived: CPU idle
            t++;
            continue;
        }

        wt[c] = t - at[c];
        t += bt[c];             // non-preemptive: run it completely
        tat[c] = t - at[c];
        fin[c] = 1;
        done++;
        a += tat[c];
        b += wt[c];
    }

    for (int i = 0; i < n; i++)
        printf("%d %d %d %d %d %d\n", pid[i], at[i], bt[i], tat[i], wt[i], wt[i]);

    printf("Average Turnaround Time = %.2f\n", a / n);
    printf("Average Response Time = %.2f\n", b / n);
    printf("Average Waiting Time = %.2f\n", b / n);
}
