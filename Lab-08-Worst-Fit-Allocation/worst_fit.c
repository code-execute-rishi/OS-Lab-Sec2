// Lab 8: Simulate contiguous memory allocation using the worst-fit algorithm

#include <stdio.h>
#include <string.h>

// memory = list of blocks in address order; owner = -1 means the block is a free hole
int start[100], size[100], owner[100], count = 1;

int freeMemory() {
    int avail = 0;
    for (int i = 0; i < count; i++)
        if (owner[i] == -1)
            avail += size[i];
    return avail;
}

void display(int ev_no, int time, int arriving, int pid, int psize, char *msg) {
    int occ = 0, avail = freeMemory(), max_hole = 0;
    for (int i = 0; i < count; i++) {
        if (owner[i] != -1)
            occ += size[i];
        else if (size[i] > max_hole)
            max_hole = size[i];
    }

    if (arriving)
        printf("Event %d: Time %d ARRIVE P%d %d\n", ev_no, time, pid, psize);
    else
        printf("Event %d: Time %d LEAVE P%d\n", ev_no, time, pid);

    printf("Result: %s\nMemory: ", msg);
    for (int i = 0; i < count; i++) {
        if (owner[i] == -1)
            printf(" (%d, %d, FREE)", start[i], size[i]);
        else
            printf(" (%d, %d, P%d)", start[i], size[i], owner[i]);
    }
    printf("\nOccupied: %d KB\nAvailable: %d KB\n"
           "Largest hole: %d KB\nExternal Fragmentation: %d KB\n\n",
           occ, avail, max_hole, avail - max_hole);
}

void arrive(int time, int pid, int psize, int ev_no) {
    // worst fit: choose the LARGEST free hole that is big enough
    int w = -1;
    for (int i = 0; i < count; i++)
        if (owner[i] == -1 && size[i] >= psize && (w == -1 || size[i] > size[w]))
            w = i;

    if (w == -1) {
        display(ev_no, time, 1, pid, psize, (freeMemory() >= psize) ?
                "Allocation failed - external fragmentation" :
                "Allocation failed - insufficient total free memory");
        return;
    }

    if (size[w] > psize) {
        // split: shift later blocks right and put the leftover hole after this one
        for (int i = count; i > w + 1; i--) {
            start[i] = start[i - 1];
            size[i] = size[i - 1];
            owner[i] = owner[i - 1];
        }
        start[w + 1] = start[w] + psize;
        size[w + 1] = size[w] - psize;
        owner[w + 1] = -1;
        count++;
        size[w] = psize;
    }
    owner[w] = pid;
    display(ev_no, time, 1, pid, psize, "Allocated");
}

void leave(int time, int pid, int ev_no) {
    for (int i = 0; i < count; i++)
        if (owner[i] == pid) {
            owner[i] = -1;
            break;
        }

    // merge neighbouring free holes into one
    for (int i = 0; i < count - 1;) {
        if (owner[i] == -1 && owner[i + 1] == -1) {
            size[i] += size[i + 1];
            for (int j = i + 1; j < count - 1; j++) {
                start[j] = start[j + 1];
                size[j] = size[j + 1];
                owner[j] = owner[j + 1];
            }
            count--;
        } else {
            i++;
        }
    }
    display(ev_no, time, 0, pid, 0, "Released");
}

int main() {
    int mem_size, events;
    if (scanf("%d %d", &mem_size, &events) != 2)
        return 0;
    start[0] = 0;
    size[0] = mem_size;
    owner[0] = -1;

    for (int i = 1; i <= events; i++) {
        int time, pid, psize;
        char type[10];
        scanf("%d %s", &time, type);
        if (!strcmp(type, "ARRIVE")) {
            scanf("%d %d", &pid, &psize);
            arrive(time, pid, psize, i);
        } else {
            scanf("%d", &pid);
            leave(time, pid, i);
        }
    }
    return 0;
}
