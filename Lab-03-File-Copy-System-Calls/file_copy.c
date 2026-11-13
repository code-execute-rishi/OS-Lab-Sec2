// Lab 3: Copy the contents of one file to another using open(), read(), write() and close()

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char src[100], dest[100], buffer[1024];

    printf("<name of existing file>");
    scanf("%99s", src);
    printf("<name of new file>");
    scanf("%99s", dest);

    int in = open(src, O_RDONLY);
    if (in < 0) {
        perror("Error opening source file");
        exit(1);
    }
    int out = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        perror("Error opening/creating destination file");
        exit(1);
    }

    // read a block, write the same block, until read() returns 0 (end of file)
    int n;
    while ((n = read(in, buffer, sizeof(buffer))) > 0) {
        if (write(out, buffer, n) != n) {
            perror("Error writing to destination file");
            exit(1);
        }
    }

    if (n < 0)
        perror("Error reading source file");
    else
        printf("File copied successfully!\n");

    close(in);
    close(out);
    return 0;
}
