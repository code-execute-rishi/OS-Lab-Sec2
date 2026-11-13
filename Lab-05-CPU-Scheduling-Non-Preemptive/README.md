# Lab 5

**Input:** number of processes `n`, then `n` lines of `pid arrival_time burst_time`.

**Output columns:** `pid arrival_time burst_time turnaround_time waiting_time response_time`

## (a) FCFS

**Aim:** Write a C program for CPU scheduling algorithm - FCFS.

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
1 0 5 5 0 0
2 2 3 6 3 3
3 4 1 5 4 4
Average Turnaround Time = 5.33
Average Waiting Time = 2.33
Average Response Time = 2.33
```

## (b) SJF

**Aim:** Write a C program of CPU scheduling algorithm - SJF.

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
1 0 7 7 0 0
2 2 4 10 6 6
3 4 1 4 3 3
4 5 4 11 7 7
Average Turnaround Time = 8.00
Average Response Time = 4.00
Average Waiting Time = 4.00
```
