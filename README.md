# Operating Systems Lab — Section 2

Lab programs for the Operating Systems course at Maulana Azad National Institute of Technology (MANIT), Bhopal.

| Lab | Aim | Files |
|-----|-----|-------|
| [01](Lab-01-Unix-Commands) | Use suitable UNIX commands to perform the given activities | `student.dat` |
| [02](Lab-02-Vi-Editor) | Use the vi editor for the given activities | `sample.txt` |
| [03](Lab-03-File-Copy-System-Calls) | Copy one file to another using `open()`, `read()`, `write()`, `close()` | `file_copy.c` |
| [04](Lab-04-Fork-Wait) | Demonstrate `fork()` and `wait()` system calls | `fork_wait.c` |
| [05](Lab-05-CPU-Scheduling-Non-Preemptive) | CPU scheduling: (a) FCFS, (b) SJF | `fcfs.c`, `sjf.c` |
| [06](Lab-06-CPU-Scheduling-Preemptive) | CPU scheduling: (a) SRTF, (b) RR, (c) Pre-emptive Priority | `srtf.c`, `round_robin.c`, `priority_preemptive.c` |
| [07](Lab-07-Demand-Paging) | Simulate demand paging for multiple processes | `demand_paging.c` |
| [08](Lab-08-Worst-Fit-Allocation) | Contiguous memory allocation using the worst-fit algorithm | `worst_fit.c` |

## Build and run

```bash
gcc fcfs.c -o fcfs
./fcfs < input_fcfs.txt
```
