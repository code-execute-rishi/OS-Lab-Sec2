// Lab 4: Demonstrate the usage of fork() and wait() system calls

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int global_var = 10;

int main() {
    int local_var = 20;
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        global_var++;
        local_var++;
        printf("Child's Global variable ++ : %d\n", global_var);
        printf("Child's Local variable ++ : %d\n", local_var);
        exit(0);
    } else {
        wait(NULL);
        printf("\n--- Parent Process ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent's Parent PID (Shell): %d\n", getppid());
        printf("Child PID: %d\n", pid);
        printf("Parent's Global variable: %d\n", global_var);
        printf("Parent's Local variable: %d\n", local_var);
    }
    return 0;
}
