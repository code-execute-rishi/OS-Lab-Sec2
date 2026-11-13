// Lab 7: Simulate demand paging for multiple processes

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long size[100];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &size[i]);
    }

    long ram_size, page_size;
    scanf("%ld %ld", &ram_size, &page_size);

    int pages[100];
    int total_pages = 0;
    for (int i = 0; i < n; i++) {
        pages[i] = (size[i] + page_size - 1) / page_size;
        total_pages += pages[i];
    }

    int total_frames = ram_size / page_size;
    int page_table[100][1000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < pages[i]; j++) {
            page_table[i][j] = -1;
        }
    }

    int frame_proc[10000], frame_page[10000];
    for (int i = 0; i < total_frames; i++) {
        frame_proc[i] = -1;
    }

    int loaded = 0, next_frame = 0;
    unsigned long long seed = 1;
    while (loaded < total_pages && next_frame < total_frames) {
        seed = (seed * 16807) % 2147483647;
        int p = seed % n;
        seed = (seed * 16807) % 2147483647;
        long addr = seed % size[p];
        int page = addr / page_size;
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
    if (next_frame == total_frames) {
        printf("Stop: RAM full\n");
    } else {
        printf("Stop: All process pages loaded\n");
    }

    printf("Page tables (-1 = not loaded):\n");
    for (int i = 0; i < n; i++) {
        printf("P%d:\nPage Frame\n", i + 1);
        for (int p = 0; p < pages[i]; p++) {
            printf("%d %d\n", p, page_table[i][p]);
        }
    }

    printf("Frame table:\nFrame Process Page\n");
    for (int f = 0; f < total_frames; f++) {
        if (frame_proc[f] != -1) {
            printf("%d P%d %d\n", f, frame_proc[f] + 1, frame_page[f]);
        } else {
            printf("%d FREE -\n", f);
        }
    }
    return 0;
}
