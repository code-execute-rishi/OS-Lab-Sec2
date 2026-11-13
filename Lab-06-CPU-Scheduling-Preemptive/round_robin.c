// Lab 6(b): CPU scheduling algorithm - RR

#include <stdio.h>

int main() {
    int n, tq;
    scanf("%d", &n);
    int p[n][8];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
        p[i][3] = p[i][2];
        p[i][4] = -1;
    }
    scanf("%d", &tq);

    int queue[10000];
    int head = 0, tail = 0;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int curr = 0, cmpl = 0;
    for (int i = 0; i < n; i++) {
        if (p[i][1] == 0) {
            queue[tail++] = i;
            visited[i] = 1;
        }
    }

    while (cmpl < n) {
        if (head == tail) {
            curr++;
            for (int i = 0; i < n; i++) {
                if (p[i][1] <= curr && !visited[i] && p[i][3] > 0) {
                    queue[tail++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[head++];
        if (p[idx][4] == -1) {
            p[idx][4] = curr;
            p[idx][7] = curr - p[idx][1];
        }

        int run = (p[idx][3] < tq ? p[idx][3] : tq);
        p[idx][3] -= run;
        curr += run;
        for (int i = 0; i < n; i++) {
            if (p[i][1] <= curr && !visited[i] && p[i][3] > 0) {
                queue[tail++] = i;
                visited[i] = 1;
            }
        }

        if (p[idx][3] == 0) {
            cmpl++;
            p[idx][5] = curr - p[idx][1];
            p[idx][6] = p[idx][5] - p[idx][2];
        } else {
            queue[tail++] = idx;
        }
    }

    double tat = 0, wt = 0, rt = 0;
    for (int i = 0; i < n; i++) {
        printf("%d %d %d %d %d %d\n", p[i][0],
               p[i][1], p[i][2], p[i][5], p[i][6], p[i][7]);
        tat += p[i][5];
        wt += p[i][6];
        rt += p[i][7];
    }
    printf("Average Turnaround Time = %.2f\n", tat / n);
    printf("Average Waiting Time = %.2f\n", wt / n);
    printf("Average Response Time = %.2f\n", rt / n);
    return 0;
}
