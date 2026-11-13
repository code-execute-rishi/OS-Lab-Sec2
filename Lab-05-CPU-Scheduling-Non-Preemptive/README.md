# Lab 5 — CPU Scheduling (Non-Preemptive)

## Input format (both programs)

```
n                       # number of processes
pid arrival burst       # one line per process (n lines)
```

---

## (a) First Come First Serve (FCFS)

**Aim:** Write a C program for the FCFS CPU scheduling algorithm.

**Source:** [`fcfs.c`](fcfs.c)

```bash
gcc fcfs.c -o fcfs
./fcfs < input_fcfs.txt
```

**Input** ([`input_fcfs.txt`](input_fcfs.txt))

```
3
1 0 5
2 2 3
3 4 1
```

**Output**

```
PID	AT	BT	TAT	WT	RT
1	0	5	5	0	0
2	2	3	6	3	3
3	4	1	5	4	4
Average Turnaround Time = 5.33
Average Waiting Time = 2.33
Average Response Time = 2.33
```

**Gantt chart**

```
| P1 | P2 | P3 |
0    5    8    9
```

---

## (b) Shortest Job First (SJF)

**Aim:** Write a C program for the SJF CPU scheduling algorithm.

**Source:** [`sjf.c`](sjf.c)

```bash
gcc sjf.c -o sjf
./sjf < input_sjf.txt
```

**Input** ([`input_sjf.txt`](input_sjf.txt))

```
4
1 0 7
2 2 4
3 4 1
4 5 4
```

**Output**

```
PID	AT	BT	TAT	WT	RT
1	0	7	7	0	0
2	2	4	10	6	6
3	4	1	4	3	3
4	5	4	11	7	7
Average Turnaround Time = 8.00
Average Waiting Time = 4.00
Average Response Time = 4.00
```

**Gantt chart**

```
| P1 | P3 | P2 | P4 |
0    7    8    12   16
```

At t = 8, P2 and P4 both have a burst of 4. P2 runs first because it arrived earlier.

> In non-preemptive scheduling, a process runs until it ends, so Response Time = Waiting Time.
