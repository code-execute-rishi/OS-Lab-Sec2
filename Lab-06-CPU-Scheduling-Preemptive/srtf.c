// Lab 6(a): CPU scheduling algorithm - SRTF

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int pid[n], at[n], bt[n], rem[n], tat[n], wt[n], rt[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        rem[i] = bt[i];
        rt[i] = -1;
    }

    int t = 0, done = 0;
    while (done < n) {
        // every 1 ms: pick the arrived process with the least remaining time
        int c = -1;
        for (int i = 0; i < n; i++)
            if (at[i] <= t && rem[i] > 0 &&
                (c == -1 || rem[i] < rem[c] || (rem[i] == rem[c] && at[i] < at[c])))
                c = i;

        if (c == -1) {          // nothing has arrived: CPU idle
            t++;
            continue;
        }

        if (rt[c] == -1)        // first time on the CPU
            rt[c] = t - at[c];
        rem[c]--;               // run for 1 ms
        t++;

        if (rem[c] == 0) {
            done++;
            tat[c] = t - at[c];
            wt[c] = tat[c] - bt[c];
        }
    }

    double a = 0, b = 0, r = 0;
    for (int i = 0; i < n; i++) {
        printf("%d %d %d %d %d %d\n", pid[i], at[i], bt[i], tat[i], wt[i], rt[i]);
        a += tat[i];
        b += wt[i];
        r += rt[i];
    }
    printf("Average Turnaround Time = %.2f\n", a / n);
    printf("Average Waiting Time = %.2f\n", b / n);
    printf("Average Response Time = %.2f\n", r / n);
    return 0;
}
