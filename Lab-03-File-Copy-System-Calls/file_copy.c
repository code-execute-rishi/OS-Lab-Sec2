/*
 * Lab 3 - Copy one file to another using open(), read(), write(), close().
 *
 * Interactive: asks for the name of an existing file and the name of the
 * new file, then copies the contents in chunks of BUF_SIZE bytes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(void)
{
    char src[100], dest[100], buffer[BUF_SIZE];
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;

    printf("<name of existing file> ");
    scanf("%99s", src);
    printf("<name of new file> ");
    scanf("%99s", dest);

    src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        exit(1);
    }

    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening/creating destination file");
        close(src_fd);
        exit(1);
    }

    while ((bytes_read = read(src_fd, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }
    }

    if (bytes_read < 0)
        perror("Error reading source file");
    else
        printf("File copied successfully!\n");

    close(src_fd);
    close(dest_fd);
    return 0;
}
