# Lab 6

## (a) SRTF

**Aim:** Write a C program of CPU scheduling algorithm - SRTF.

**Source:** [`srtf.c`](srtf.c)

```bash
gcc srtf.c -o srtf
./srtf < input_srtf.txt
```

**Input:** number of processes `n`, then `n` lines of `pid arrival_time burst_time`.

**Output columns:** `pid arrival_time burst_time turnaround_time waiting_time response_time`

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
1 0 5 8 3 0
2 1 3 3 0 0
3 2 8 20 12 12
4 3 6 11 5 5
Average Turnaround Time = 10.50
Average Waiting Time = 5.00
Average Response Time = 4.25
```

## (b) RR

**Aim:** Write a C program of CPU scheduling algorithm - RR.

**Source:** [`round_robin.c`](round_robin.c)

```bash
gcc round_robin.c -o round_robin
./round_robin < input_rr.txt
```

**Input:** number of processes `n`, then `n` lines of `pid arrival_time burst_time`, then the time quantum.

**Output columns:** `pid arrival_time burst_time turnaround_time waiting_time response_time`

**Input** ([`input_rr.txt`](input_rr.txt))

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
1 0 5 14 9 0
2 1 3 10 7 1
3 2 8 20 12 2
4 3 6 17 11 5
Average Turnaround Time = 15.25
Average Waiting Time = 9.75
Average Response Time = 2.00
```

## (c) Pre-emptive Priority

**Aim:** Write a C program of CPU scheduling algorithm - Pre-emptive Priority.

**Source:** [`priority_preemptive.c`](priority_preemptive.c)

```bash
gcc priority_preemptive.c -o priority_preemptive
./priority_preemptive < input_priority.txt
```

**Input:** number of processes `n`, then `n` lines of `pid arrival_time burst_time priority` (lower number = higher priority).

**Output columns:** `pid priority arrival_time burst_time turnaround_time waiting_time response_time`

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
1 2 0 5 10 5 0
2 1 1 3 3 0 0
3 3 2 4 12 8 8
4 1 3 2 3 1 1
Average Turnaround Time = 7.00
Average Waiting Time = 3.50
Average Response Time = 2.25
```
