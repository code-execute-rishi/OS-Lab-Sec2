# Lab 7

**Aim:** Write a C program to simulate demand paging for multiple processes.

**Source:** [`demand_paging.c`](demand_paging.c)

```bash
gcc demand_paging.c -o demand_paging
./demand_paging < input.txt
```

**Input:** number of processes `n`, then the `n` process sizes, then `ram_size page_size`.

**Input** ([`input.txt`](input.txt))

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
Page Frame
0 -1
1 3
2 1
3 2
P2:
Page Frame
0 0
1 -1
2 -1
Frame table:
Frame Process Page
0 P2 0
1 P1 2
2 P1 3
3 P1 1
```
