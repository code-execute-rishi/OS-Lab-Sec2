// Lab 4: Demonstrate the usage of fork() and wait() system calls

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int global_var = 10;

int main() {
    int local_var = 20;
    int pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // child: change its own copy of the variables
        global_var++;
        local_var++;
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        printf("Child's Global variable ++ : %d\n", global_var);
        printf("Child's Local variable ++ : %d\n", local_var);
        exit(0);
    }

    // parent: wait for the child, then show its variables are unchanged
    wait(NULL);
    printf("\n--- Parent Process ---\n");
    printf("Parent PID: %d\n", getpid());
    printf("Parent's Parent PID (Shell): %d\n", getppid());
    printf("Child PID: %d\n", pid);
    printf("Parent's Global variable: %d\n", global_var);
    printf("Parent's Local variable: %d\n", local_var);
    return 0;
}
