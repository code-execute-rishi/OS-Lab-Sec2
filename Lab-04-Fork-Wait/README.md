# Lab 4

**Aim:** Write a C program to demonstrate the usage of fork() and wait() system calls.

**Source:** [`fork_wait.c`](fork_wait.c)

```bash
gcc fork_wait.c -o fork_wait
./fork_wait
```

## Output

```
--- Child Process ---
Child PID: 2451
Parent PID: 2450
Child's Global variable ++ : 11
Child's Local variable ++ : 21

--- Parent Process ---
Parent PID: 2450
Parent's Parent PID (Shell): 1240
Child PID: 2451
Parent's Global variable: 10
Parent's Local variable: 20
```
