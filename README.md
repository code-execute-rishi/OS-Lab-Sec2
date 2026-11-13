# Operating Systems Lab — Section 2

Lab programs for the Operating Systems course at Maulana Azad National Institute of Technology (MANIT), Bhopal.
The programs are written in C for POSIX systems (Linux and macOS). Each lab folder has the source code, a sample input, and the matching output.

| Lab | Topic | Files |
|-----|-------|-------|
| [01](Lab-01-Unix-Commands) | Basic UNIX commands (`nproc`, `df`, `ps`, `ls`, `cat`) | `student.dat` |
| [02](Lab-02-Vi-Editor) | `vi` editor and file permissions (`chmod`) | `sample.txt` |
| [03](Lab-03-File-Copy-System-Calls) | Copy a file with `open()`, `read()`, `write()`, `close()` | `file_copy.c` |
| [04](Lab-04-Fork-Wait) | Process creation with `fork()` and `wait()` | `fork_wait.c` |
| [05](Lab-05-CPU-Scheduling-Non-Preemptive) | CPU scheduling: FCFS, SJF | `fcfs.c`, `sjf.c` |
| [06](Lab-06-CPU-Scheduling-Preemptive) | CPU scheduling: SRTF, Round Robin, Preemptive Priority | `srtf.c`, `round_robin.c`, `priority_preemptive.c` |
| [07](Lab-07-Demand-Paging) | Demand paging simulation for multiple processes | `demand_paging.c` |
| [08](Lab-08-Worst-Fit-Allocation) | Contiguous memory allocation using Worst-Fit | `worst_fit.c` |

## Build and run

You need a C compiler (`gcc` or `clang`). Example:

```bash
cd Lab-05-CPU-Scheduling-Non-Preemptive
gcc fcfs.c -o fcfs
./fcfs < input_fcfs.txt
```

The programs read from standard input. You can type the input, or redirect a sample input file with `<`.

## Abbreviations used in scheduling output

| Abbreviation | Meaning |
|--------------|---------|
| PID | Process ID |
| AT  | Arrival Time |
| BT  | Burst Time |
| PRI | Priority (lower number = higher priority) |
| TAT | Turnaround Time = Completion Time − Arrival Time |
| WT  | Waiting Time = Turnaround Time − Burst Time |
| RT  | Response Time = First CPU Time − Arrival Time |
