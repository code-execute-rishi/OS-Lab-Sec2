// Lab 6(c): CPU scheduling algorithm - Pre-emptive Priority

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][6];
    int res[n][7];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &arr[i][0], &arr[i][1],
              &arr[i][2], &arr[i][3]);
        arr[i][4] = arr[i][2];
        arr[i][5] = -1;
        res[i][0] = arr[i][0];
        res[i][1] = arr[i][3];
        res[i][2] = arr[i][1];
        res[i][3] = arr[i][2];
    }

    int curr = 0, cmpl = 0;
    while (cmpl < n) {
        int idx = -1, mx = 100000;
        for (int i = 0; i < n; i++) {
            if (arr[i][1] <= curr && arr[i][4] > 0) {
                if (arr[i][3] < mx) {
                    mx = arr[i][3];
                    idx = i;
                } else if (arr[i][3] == mx && arr[i][1] < arr[idx][1]) {
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            curr++;
            continue;
        }
        if (arr[idx][5] == -1) {
            arr[idx][5] = curr;
            res[idx][6] = curr - arr[idx][1];
        }
        arr[idx][4]--;
        curr++;
        if (arr[idx][4] == 0) {
            cmpl++;
            res[idx][4] = curr - arr[idx][1];
            res[idx][5] = res[idx][4] - arr[idx][2];
        }
    }

    double tat = 0, wt = 0, rt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        tat += res[i][4];
        wt += res[i][5];
        rt += res[i][6];
    }
    printf("Average Turnaround Time = %.2f\n", tat / n);
    printf("Average Waiting Time = %.2f\n", wt / n);
    printf("Average Response Time = %.2f\n", rt / n);
    return 0;
}
