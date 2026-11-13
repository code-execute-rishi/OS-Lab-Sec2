// Lab 5(a): CPU scheduling algorithm - FCFS

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][6];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j][1] > arr[j + 1][1]) {
                for (int k = 0; k < 3; k++) {
                    int temp;
                    temp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp;
                }
            }
        }
    }

    int t = 0;
    float a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][1] > t) {
            t = arr[i][1];
        }
        arr[i][4] = t - arr[i][1];
        arr[i][5] = arr[i][4];
        arr[i][3] = t + arr[i][2] - arr[i][1];
        t += arr[i][2];
        a += arr[i][3];
        b += arr[i][4];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 1 == arr[j][0]) {
                printf("%d %d %d %d %d %d\n",
                       arr[j][0], arr[j][1], arr[j][2],
                       arr[j][3], arr[j][4], arr[j][5]);
                break;
            }
        }
    }

    a = a / n;
    b = b / n;
    printf("Average Turnaround Time = %.2f\n", a);
    printf("Average Waiting Time = %.2f\n", b);
    printf("Average Response Time = %.2f\n", b);
}
