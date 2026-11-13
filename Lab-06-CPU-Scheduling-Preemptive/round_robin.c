// Lab 6(b): CPU scheduling algorithm - RR

#include <stdio.h>

int n, tq, t = 0;
int pid[100], at[100], bt[100], rem[100], tat[100], wt[100], rt[100], inq[100];
int queue[10000], head = 0, tail = 0;

// put every process that has arrived (and was never queued) at the back of the queue
void addArrivals() {
    for (int i = 0; i < n; i++)
        if (!inq[i] && at[i] <= t) {
            queue[tail++] = i;
            inq[i] = 1;
        }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        rem[i] = bt[i];
        rt[i] = -1;
    }
    scanf("%d", &tq);

    int done = 0;
    while (done < n) {
        addArrivals();
        if (head == tail) {     // queue empty: CPU idle
            t++;
            continue;
        }

        int c = queue[head++];  // take the process at the front
        if (rt[c] == -1)
            rt[c] = t - at[c];

        int run = rem[c] < tq ? rem[c] : tq;   // run for one time quantum
        rem[c] -= run;
        t += run;

        if (rem[c] == 0) {
            done++;
            tat[c] = t - at[c];
            wt[c] = tat[c] - bt[c];
        } else {
            addArrivals();          // new arrivals go in first,
            queue[tail++] = c;      // then this process goes to the back
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
