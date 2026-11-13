# Lab 8 — Worst-Fit Contiguous Memory Allocation

**Aim:** Write a C program that simulates contiguous memory allocation with the worst-fit algorithm.

**Source:** [`worst_fit.c`](worst_fit.c)

```bash
gcc worst_fit.c -o worst_fit
./worst_fit < input.txt
```

## Input format

```
memory_size number_of_events
<time> ARRIVE <pid> <size>      # a process asks for memory
<time> LEAVE  <pid>             # a process releases its memory
```

The program stores memory as a linked list of blocks `(start, size, owner)`.

- **ARRIVE:** The program selects the **largest** free block that is big enough. On a tie, it selects the block with the lowest address. Then it splits the block.
- **LEAVE:** The program frees the block and merges it with the free blocks next to it.
- **External fragmentation** = total free memory − largest hole.
- If an allocation fails, the program gives one of these two reasons:
  - `insufficient total free memory`: the total free memory is less than the request.
  - `external fragmentation`: there is enough free memory in total, but no single hole is large enough.

---

## Sample 1

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
Memory: (0, 100, P1) (100, 924, FREE)
Occupied: 100 KB
Available: 924 KB
Largest hole: 924 KB
External fragmentation: 0 KB

Event 2: Time 1 ARRIVE P2 200
Result: Allocated
Memory: (0, 100, P1) (100, 200, P2) (300, 724, FREE)
Occupied: 300 KB
Available: 724 KB
Largest hole: 724 KB
External fragmentation: 0 KB

Event 3: Time 1 ARRIVE P3 300
Result: Allocated
Memory: (0, 100, P1) (100, 200, P2) (300, 300, P3) (600, 424, FREE)
Occupied: 600 KB
Available: 424 KB
Largest hole: 424 KB
External fragmentation: 0 KB

Event 4: Time 1 ARRIVE P4 300
Result: Allocated
Memory: (0, 100, P1) (100, 200, P2) (300, 300, P3) (600, 300, P4) (900, 124, FREE)
Occupied: 900 KB
Available: 124 KB
Largest hole: 124 KB
External fragmentation: 0 KB

Event 5: Time 1 ARRIVE P5 300
Result: Allocation failed - insufficient total free memory
Memory: (0, 100, P1) (100, 200, P2) (300, 300, P3) (600, 300, P4) (900, 124, FREE)
Occupied: 900 KB
Available: 124 KB
Largest hole: 124 KB
External fragmentation: 0 KB
```

---

## Sample 2: LEAVE events and external fragmentation

**Input** ([`input_with_leave.txt`](input_with_leave.txt))

```
1024 7
0 ARRIVE 1 300
1 ARRIVE 2 200
2 ARRIVE 3 300
3 LEAVE 1
4 LEAVE 3
5 ARRIVE 4 600
6 ARRIVE 5 400
```

**Output**

```
Event 1: Time 0 ARRIVE P1 300
Result: Allocated
Memory: (0, 300, P1) (300, 724, FREE)
Occupied: 300 KB
Available: 724 KB
Largest hole: 724 KB
External fragmentation: 0 KB

Event 2: Time 1 ARRIVE P2 200
Result: Allocated
Memory: (0, 300, P1) (300, 200, P2) (500, 524, FREE)
Occupied: 500 KB
Available: 524 KB
Largest hole: 524 KB
External fragmentation: 0 KB

Event 3: Time 2 ARRIVE P3 300
Result: Allocated
Memory: (0, 300, P1) (300, 200, P2) (500, 300, P3) (800, 224, FREE)
Occupied: 800 KB
Available: 224 KB
Largest hole: 224 KB
External fragmentation: 0 KB

Event 4: Time 3 LEAVE P1
Result: Released
Memory: (0, 300, FREE) (300, 200, P2) (500, 300, P3) (800, 224, FREE)
Occupied: 500 KB
Available: 524 KB
Largest hole: 300 KB
External fragmentation: 224 KB

Event 5: Time 4 LEAVE P3
Result: Released
Memory: (0, 300, FREE) (300, 200, P2) (500, 524, FREE)
Occupied: 200 KB
Available: 824 KB
Largest hole: 524 KB
External fragmentation: 300 KB

Event 6: Time 5 ARRIVE P4 600
Result: Allocation failed - external fragmentation
Memory: (0, 300, FREE) (300, 200, P2) (500, 524, FREE)
Occupied: 200 KB
Available: 824 KB
Largest hole: 524 KB
External fragmentation: 300 KB

Event 7: Time 6 ARRIVE P5 400
Result: Allocated
Memory: (0, 300, FREE) (300, 200, P2) (500, 400, P5) (900, 124, FREE)
Occupied: 600 KB
Available: 424 KB
Largest hole: 300 KB
External fragmentation: 124 KB
```

In event 5, P3 leaves and its block merges with the free block after it (300 + 224 = 524). In event 6, 824 KB is free in total, but the largest hole is only 524 KB, so the 600 KB request fails. In event 7, worst-fit puts P5 in the largest hole (524 KB), not in the 300 KB hole.
