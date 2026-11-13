# Lab 6 — CPU Scheduling (Preemptive)

---

## (a) Shortest Remaining Time First (SRTF)

**Aim:** Write a C program for the SRTF CPU scheduling algorithm.

**Source:** [`srtf.c`](srtf.c)

```bash
gcc srtf.c -o srtf
./srtf < input_srtf.txt
```

**Input format:** `n`, then `n` lines of `pid arrival burst`.

**Input** ([`input_srtf.txt`](input_srtf.txt))

```
4
1 0 5
2 1 3
3 2 8
4 3 6
```

**Output**

```
PID	AT	BT	TAT	WT	RT
1	0	5	8	3	0
2	1	3	3	0	0
3	2	8	20	12	12
4	3	6	11	5	5
Average Turnaround Time = 10.50
Average Waiting Time = 5.00
Average Response Time = 4.25
```

**Gantt chart**

```
| P1 | P2 | P1 | P4 | P3 |
0    1    4    8    14   22
```

---

## (b) Round Robin (RR)

**Aim:** Write a C program for the Round Robin CPU scheduling algorithm.

**Source:** [`round_robin.c`](round_robin.c)

```bash
gcc round_robin.c -o round_robin
./round_robin < input_rr.txt
```

**Input format:** `n`, then `n` lines of `pid arrival burst`, then the time quantum.

**Input** ([`input_rr.txt`](input_rr.txt), time quantum = 2)

```
4
1 0 5
2 1 3
3 2 8
4 3 6
2
```

**Output**

```
PID	AT	BT	TAT	WT	RT
1	0	5	14	9	0
2	1	3	10	7	1
3	2	8	20	12	2
4	3	6	17	11	5
Average Turnaround Time = 15.25
Average Waiting Time = 9.75
Average Response Time = 2.00
```

**Gantt chart**

```
| P1 | P2 | P3 | P1 | P4 | P2 | P3 | P1 | P4 | P3 | P4 | P3 |
0    2    4    6    8    10   11   13   14   16   18   20   22
```

---

## (c) Preemptive Priority

**Aim:** Write a C program for the preemptive Priority CPU scheduling algorithm.

**Source:** [`priority_preemptive.c`](priority_preemptive.c)

```bash
gcc priority_preemptive.c -o priority_preemptive
./priority_preemptive < input_priority.txt
```

**Input format:** `n`, then `n` lines of `pid arrival burst priority`. A lower number means a higher priority.

**Input** ([`input_priority.txt`](input_priority.txt))

```
4
1 0 5 2
2 1 3 1
3 2 4 3
4 3 2 1
```

**Output**

```
PID	PRI	AT	BT	TAT	WT	RT
1	2	0	5	10	5	0
2	1	1	3	3	0	0
3	3	2	4	12	8	8
4	1	3	2	3	1	1
Average Turnaround Time = 7.00
Average Waiting Time = 3.50
Average Response Time = 2.25
```

**Gantt chart**

```
| P1 | P2 | P4 | P1 | P3 |
0    1    4    6    10   14
```

At t = 3, P4 (priority 1) arrives, but P2 also has priority 1 and arrived earlier, so P2 continues to run.
