// Lab 5(b): CPU scheduling algorithm - SJF

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][7];
    int vec[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][6] = 0;
        }
        vec[i] = arr[i][0];
    }

    int t = 0;
    float a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int curr = -1;
        for (int j = 0; j < n; j++) {
            if (arr[j][6] == 1) {
                continue;
            }
            if (curr == -1) {
                curr = j;
                continue;
            }
            if (arr[curr][1] > t && arr[j][1] <= t) {
                curr = j;
            } else if (arr[curr][1] <= t && arr[j][1] <= t) {
                if (arr[curr][2] > arr[j][2]) {
                    curr = j;
                } else if (arr[curr][2] == arr[j][2] &&
                           arr[curr][1] > arr[j][1]) {
                    curr = j;
                } else if (arr[curr][2] == arr[j][2] &&
                           arr[curr][1] == arr[j][1] &&
                           arr[curr][0] > arr[j][0]) {
                    curr = j;
                }
            } else if (arr[curr][1] > t && arr[j][1] > t) {
                if (arr[curr][1] > arr[j][1]) {
                    curr = j;
                }
            }
        }

        if (arr[curr][1] > t) {
            t = arr[curr][1];
        }
        arr[curr][4] = t - arr[curr][1];
        arr[curr][5] = arr[curr][4];
        arr[curr][3] = arr[curr][4] + arr[curr][2];
        t += arr[curr][2];
        a += arr[curr][3];
        b += arr[curr][4];
        arr[curr][6] = 1;
    }

    a = a / n;
    b = b / n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[i] == arr[j][0]) {
                printf("%d %d %d %d %d %d\n",
                       arr[j][0], arr[j][1], arr[j][2],
                       arr[j][3], arr[j][4], arr[j][5]);
            }
        }
    }
    printf("Average Turnaround Time = %.2f\n", a);
    printf("Average Response Time = %.2f\n", b);
    printf("Average Waiting Time = %.2f\n", b);
}
