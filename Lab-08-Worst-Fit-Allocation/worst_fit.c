/*
 * Lab 8 - Contiguous memory allocation using the Worst-Fit algorithm.
 *
 * Input : memory_size number_of_events
 *         then one event per line:
 *           <time> ARRIVE <pid> <size>
 *           <time> LEAVE  <pid>
 * Output: result of every event, the memory map, and occupied / available
 *         memory, largest hole and external fragmentation (all in KB).
 *
 * Memory is a linked list of blocks. ARRIVE takes the largest free block
 * (lowest start address on ties) and splits it. LEAVE frees the block and
 * merges adjacent free blocks.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    int start, size, is_free, pid;
    struct Block *next;
} Block;

Block *head = NULL;

void init(int size)
{
    head = malloc(sizeof(Block));
    head->start = 0;
    head->size = size;
    head->is_free = 1;
    head->pid = -1;
    head->next = NULL;
}

void metrics(int *occ, int *avail, int *max_hole, int *ext_frag)
{
    *occ = 0;
    *avail = 0;
    *max_hole = 0;
    for (Block *c = head; c; c = c->next) {
        if (c->is_free) {
            *avail += c->size;
            if (c->size > *max_hole)
                *max_hole = c->size;
        } else {
            *occ += c->size;
        }
    }
    *ext_frag = (*avail == 0) ? 0 : *avail - *max_hole;
}

void display(int ev_no, int time, const char *type, int pid, int psize, const char *msg)
{
    int occ, avail, max_hole, ext_frag;
    metrics(&occ, &avail, &max_hole, &ext_frag);

    if (!strcmp(type, "ARRIVE"))
        printf("Event %d: Time %d ARRIVE P%d %d\n", ev_no, time, pid, psize);
    else
        printf("Event %d: Time %d LEAVE P%d\n", ev_no, time, pid);

    printf("Result: %s\nMemory:", msg);
    for (Block *c = head; c; c = c->next) {
        if (c->is_free)
            printf(" (%d, %d, FREE)", c->start, c->size);
        else
            printf(" (%d, %d, P%d)", c->start, c->size, c->pid);
    }
    printf("\nOccupied: %d KB\nAvailable: %d KB\nLargest hole: %d KB\n"
           "External fragmentation: %d KB\n\n", occ, avail, max_hole, ext_frag);
}

void arrive(int time, int pid, int psize, int ev_no)
{
    Block *target = NULL;
    int max_s = -1;
    for (Block *c = head; c; c = c->next) {
        if (c->is_free && c->size >= psize) {
            if (c->size > max_s ||
                (c->size == max_s && target && c->start < target->start)) {
                max_s = c->size;
                target = c;
            }
        }
    }

    if (!target) {
        int occ, avail, max_hole, ext_frag;
        metrics(&occ, &avail, &max_hole, &ext_frag);
        display(ev_no, time, "ARRIVE", pid, psize,
                (avail >= psize) ? "Allocation failed - external fragmentation"
                                 : "Allocation failed - insufficient total free memory");
        return;
    }

    if (target->size == psize) {
        target->is_free = 0;
        target->pid = pid;
    } else {                        /* split: [pid | remaining free] */
        Block *n = malloc(sizeof(Block));
        n->start = target->start + psize;
        n->size = target->size - psize;
        n->is_free = 1;
        n->pid = -1;
        n->next = target->next;
        target->size = psize;
        target->is_free = 0;
        target->pid = pid;
        target->next = n;
    }
    display(ev_no, time, "ARRIVE", pid, psize, "Allocated");
}

void leave(int time, int pid, int ev_no)
{
    for (Block *c = head; c; c = c->next) {
        if (!c->is_free && c->pid == pid) {
            c->is_free = 1;
            c->pid = -1;
            break;
        }
    }

    /* merge adjacent free blocks */
    for (Block *c = head; c && c->next;) {
        if (c->is_free && c->next->is_free) {
            Block *temp = c->next;
            c->size += temp->size;
            c->next = temp->next;
            free(temp);
        } else {
            c = c->next;
        }
    }
    display(ev_no, time, "LEAVE", pid, 0, "Released");
}

int main(void)
{
    int mem_size, events;
    if (scanf("%d %d", &mem_size, &events) != 2)
        return 0;
    init(mem_size);

    for (int i = 1; i <= events; i++) {
        int time, pid, psize;
        char type[10];
        scanf("%d %9s", &time, type);
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
