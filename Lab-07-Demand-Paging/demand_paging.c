/*
 * Lab 7 - Simulate demand paging for multiple processes.
 *
 * Input : n (number of processes)
 *         n process sizes
 *         RAM size and page size
 * Output: page table of every process and the frame table.
 *
 * A fixed-seed Lehmer RNG (seed * 16807 mod 2^31-1) picks a random process
 * and a random address inside it. If that page is not loaded, it is placed
 * in the next free frame. Stops when RAM is full or every page is loaded.
 */
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    long size[100];
    for (int i = 0; i < n; i++)
        scanf("%ld", &size[i]);

    long ram_size, page_size;
    scanf("%ld %ld", &ram_size, &page_size);

    int pages[100];
    int total_pages = 0;
    for (int i = 0; i < n; i++) {
        pages[i] = (size[i] + page_size - 1) / page_size;   /* ceil */
        total_pages += pages[i];
    }

    int total_frames = ram_size / page_size;

    static int page_table[100][1000];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < pages[i]; j++)
            page_table[i][j] = -1;

    static int frame_proc[10000], frame_page[10000];
    for (int i = 0; i < total_frames; i++)
        frame_proc[i] = -1;

    int loaded = 0, next_frame = 0;
    unsigned long long seed = 1;
    while (loaded < total_pages && next_frame < total_frames) {
        seed = (seed * 16807) % 2147483647;
        int p = seed % n;
        seed = (seed * 16807) % 2147483647;
        long addr = seed % size[p];
        int page = addr / page_size;

        if (page_table[p][page] == -1) {    /* page fault: load page */
            page_table[p][page] = next_frame;
            frame_proc[next_frame] = p;
            frame_page[next_frame] = page;
            next_frame++;
            loaded++;
        }
    }

    printf("Frames: %d\n", total_frames);
    printf("Loaded pages: %d\n", loaded);
    if (next_frame == total_frames)
        printf("Stop: RAM full\n");
    else
        printf("Stop: All process pages loaded\n");

    printf("\nPage tables (-1 = not loaded):\n");
    for (int i = 0; i < n; i++) {
        printf("P%d:\nPage\tFrame\n", i + 1);
        for (int p = 0; p < pages[i]; p++)
            printf("%d\t%d\n", p, page_table[i][p]);
    }

    printf("\nFrame table:\nFrame\tProcess\tPage\n");
    for (int f = 0; f < total_frames; f++) {
        if (frame_proc[f] != -1)
            printf("%d\tP%d\t%d\n", f, frame_proc[f] + 1, frame_page[f]);
        else
            printf("%d\tFREE\t-\n", f);
    }
    return 0;
}
