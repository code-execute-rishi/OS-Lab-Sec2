// Lab 6(a): CPU scheduling algorithm - SRTF

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int p[n][8];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
        p[i][3] = p[i][2];
        p[i][4] = -1;
    }

    int curr = 0, cmpl = 0;
    while (cmpl < n) {
        int idx = -1;
        int mn = 100000;
        for (int i = 0; i < n; i++) {
            if (p[i][1] <= curr && p[i][3] > 0) {
                if (p[i][3] < mn) {
                    mn = p[i][3];
                    idx = i;
                } else if (p[i][3] == mn && p[i][1] < p[idx][1]) {
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            curr++;
            continue;
        }
        if (p[idx][4] == -1) {
            p[idx][4] = curr;
            p[idx][7] = curr - p[idx][1];
        }
        p[idx][3]--;
        curr++;
        if (p[idx][3] == 0) {
            cmpl++;
            p[idx][5] = curr - p[idx][1];
            p[idx][6] = p[idx][5] - p[idx][2];
        }
    }

    double tat = 0, wt = 0, rt = 0;
    for (int i = 0; i < n; i++) {
        printf("%d %d %d %d %d %d\n", p[i][0], p[i][1],
               p[i][2], p[i][5], p[i][6], p[i][7]);
        tat += p[i][5];
        wt += p[i][6];
        rt += p[i][7];
    }
    printf("Average Turnaround Time = %.2f\n", tat / n);
    printf("Average Waiting Time = %.2f\n", wt / n);
    printf("Average Response Time = %.2f\n", rt / n);
    return 0;
}
