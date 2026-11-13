# Lab 7 — Demand Paging Simulation

**Aim:** Write a C program that simulates demand paging for more than one process.

**Source:** [`demand_paging.c`](demand_paging.c)

```bash
gcc demand_paging.c -o demand_paging
./demand_paging < input.txt
```

## Input format

```
n                       # number of processes
size_1 size_2 ... size_n
ram_size page_size
```

## How it works

1. Pages per process = ⌈process size / page size⌉. Frames = RAM size / page size.
2. A fixed-seed Lehmer random number generator (`seed = seed * 16807 mod (2^31 − 1)`) selects a random process and a random address in that process.
3. If the page of that address is not loaded (page fault), the program puts the page in the next free frame.
4. The simulation stops when RAM is full or when all the pages are loaded.

The seed is fixed, so each run gives the same output.

## Sample

**Input** ([`input.txt`](input.txt)): 2 processes of 16 and 12 bytes, RAM = 16, page size = 4

```
2
16 12
16 4
```

**Output**

```
Frames: 4
Loaded pages: 4
Stop: RAM full

Page tables (-1 = not loaded):
P1:
Page	Frame
0	-1
1	3
2	1
3	2
P2:
Page	Frame
0	0
1	-1
2	-1

Frame table:
Frame	Process	Page
0	P2	0
1	P1	2
2	P1	3
3	P1	1
```

P1 has 4 pages and P2 has 3 pages, which is 7 pages in total. RAM has only 4 frames, so the simulation stops with 3 pages not loaded.
