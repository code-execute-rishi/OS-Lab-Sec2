// Lab 7: Simulate demand paging for multiple processes

#include <stdio.h>

int main() {
    int n;
    long size[100], ram_size, page_size;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%ld", &size[i]);
    scanf("%ld %ld", &ram_size, &page_size);

    // pages needed by each process = ceil(size / page_size)
    int pages[100], total_pages = 0;
    for (int i = 0; i < n; i++) {
        pages[i] = (size[i] + page_size - 1) / page_size;
        total_pages += pages[i];
    }
    int total_frames = ram_size / page_size;

    static int page_table[100][1000];      // page_table[process][page] = frame, -1 = not loaded
    int frame_proc[10000], frame_page[10000];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < pages[i]; j++)
            page_table[i][j] = -1;
    for (int f = 0; f < total_frames; f++)
        frame_proc[f] = -1;

    // random process + random address; on a page fault, load the page into the next free frame
    int loaded = 0, next_frame = 0;
    unsigned long long seed = 1;
    while (loaded < total_pages && next_frame < total_frames) {
        seed = (seed * 16807) % 2147483647;
        int p = seed % n;
        seed = (seed * 16807) % 2147483647;
        int page = (seed % size[p]) / page_size;
        if (page_table[p][page] == -1) {
            page_table[p][page] = next_frame;
            frame_proc[next_frame] = p;
            frame_page[next_frame] = page;
            next_frame++;
            loaded++;
        }
    }

    printf("Frames: %d\n", total_frames);
    printf("Loaded pages: %d\n", loaded);
    printf(next_frame == total_frames ? "Stop: RAM full\n" : "Stop: All process pages loaded\n");

    printf("Page tables (-1 = not loaded):\n");
    for (int i = 0; i < n; i++) {
        printf("P%d:\nPage Frame\n", i + 1);
        for (int j = 0; j < pages[i]; j++)
            printf("%d %d\n", j, page_table[i][j]);
    }

    printf("Frame table:\nFrame Process Page\n");
    for (int f = 0; f < total_frames; f++) {
        if (frame_proc[f] != -1)
            printf("%d P%d %d\n", f, frame_proc[f] + 1, frame_page[f]);
        else
            printf("%d FREE -\n", f);
    }
    return 0;
}
