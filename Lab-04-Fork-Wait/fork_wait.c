/*
 * Lab 4 - Demonstrate fork() and wait().
 *
 * The child gets its own copy of the parent's memory, so incrementing
 * global_var / local_var in the child does not change the parent's values.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int global_var = 10;

int main(void)
{
    int local_var = 20;
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        global_var++;
        local_var++;
        printf("Child's global variable ++ : %d\n", global_var);
        printf("Child's local variable ++ : %d\n", local_var);
        exit(0);
    } else {
        wait(NULL);
        printf("\n--- Parent Process ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent's Parent PID (Shell): %d\n", getppid());
        printf("Child PID: %d\n", pid);
        printf("Parent's global variable: %d\n", global_var);
        printf("Parent's local variable: %d\n", local_var);
    }
    return 0;
}
