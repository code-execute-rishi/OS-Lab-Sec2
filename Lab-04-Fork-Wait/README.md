# Lab 4 — fork() and wait()

**Aim:** Write a C program that shows how to use the `fork()` and `wait()` system calls.

**Source:** [`fork_wait.c`](fork_wait.c)

## Compile and run

```bash
gcc fork_wait.c -o fork_wait
./fork_wait
```

## Sample output

The PIDs are different on each run.

```

--- Child Process ---
Child PID: 2451
Parent PID: 2450
Child's global variable ++ : 11
Child's local variable ++ : 21

--- Parent Process ---
Parent PID: 2450
Parent's Parent PID (Shell): 1240
Child PID: 2451
Parent's global variable: 10
Parent's local variable: 20
```

## Observations

- `fork()` returns `0` in the child and returns the child's PID in the parent.
- `wait(NULL)` makes the parent wait until the child ends. Because of this, the child's output always comes first.
- The child increments `global_var` and `local_var`, but the parent still has `10` and `20`. The child has its own copy of the parent's address space.
