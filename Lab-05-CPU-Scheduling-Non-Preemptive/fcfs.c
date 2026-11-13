// Lab 5(a): CPU scheduling algorithm - FCFS

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
        // pick the arrived process that came first
        int c = -1;
        for (int i = 0; i < n; i++)
            if (!fin[i] && at[i] <= t && (c == -1 || at[i] < at[c]))
                c = i;

        if (c == -1) {          // nothing has arrived: CPU idle
            t++;
            continue;
        }

        wt[c] = t - at[c];      // waited from arrival until now
        t += bt[c];             // run it completely
        tat[c] = t - at[c];
        fin[c] = 1;
        done++;
        a += tat[c];
        b += wt[c];
    }

    for (int i = 0; i < n; i++)
        printf("%d %d %d %d %d %d\n", pid[i], at[i], bt[i], tat[i], wt[i], wt[i]);

    printf("Average Turnaround Time = %.2f\n", a / n);
    printf("Average Waiting Time = %.2f\n", b / n);
    printf("Average Response Time = %.2f\n", b / n);
}
