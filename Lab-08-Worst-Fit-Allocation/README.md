# Lab 8

**Aim:** Write a C program to simulate contiguous memory allocation using the worst-fit algorithm.

**Source:** [`worst_fit.c`](worst_fit.c)

```bash
gcc worst_fit.c -o worst_fit
./worst_fit < input.txt
```

**Input:** `memory_size number_of_events`, then one event per line: `<time> ARRIVE <pid> <size>` or `<time> LEAVE <pid>`.

**Input** ([`input.txt`](input.txt))

```
1024 5
1 ARRIVE 1 100
1 ARRIVE 2 200
1 ARRIVE 3 300
1 ARRIVE 4 300
1 ARRIVE 5 300
```

**Output**

```
Event 1: Time 1 ARRIVE P1 100
Result: Allocated
Memory:  (0, 100, P1) (100, 924, FREE)
Occupied: 100 KB
Available: 924 KB
Largest hole: 924 KB
External Fragmentation: 0 KB

Event 2: Time 1 ARRIVE P2 200
Result: Allocated
Memory:  (0, 100, P1) (100, 200, P2) (300, 724, FREE)
Occupied: 300 KB
Available: 724 KB
Largest hole: 724 KB
External Fragmentation: 0 KB

Event 3: Time 1 ARRIVE P3 300
Result: Allocated
Memory:  (0, 100, P1) (100, 200, P2) (300, 300, P3) (600, 424, FREE)
Occupied: 600 KB
Available: 424 KB
Largest hole: 424 KB
External Fragmentation: 0 KB

Event 4: Time 1 ARRIVE P4 300
Result: Allocated
Memory:  (0, 100, P1) (100, 200, P2) (300, 300, P3) (600, 300, P4) (900, 124, FREE)
Occupied: 900 KB
Available: 124 KB
Largest hole: 124 KB
External Fragmentation: 0 KB

Event 5: Time 1 ARRIVE P5 300
Result: Allocation failed - insufficient total free memory
Memory:  (0, 100, P1) (100, 200, P2) (300, 300, P3) (600, 300, P4) (900, 124, FREE)
Occupied: 900 KB
Available: 124 KB
Largest hole: 124 KB
External Fragmentation: 0 KB
```
