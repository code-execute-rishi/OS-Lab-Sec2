# Lab 3 — Copy a File with System Calls

**Aim:** Write a C program that uses the `open()`, `read()`, `write()` and `close()` system calls to copy the contents of one file to another file. The program must be interactive and must ask the user for `<name of existing file>` and `<name of new file>`. Make sure that the program handles errors correctly and that the code is indented correctly.

**Source:** [`file_copy.c`](file_copy.c)

## Compile and run

```bash
gcc file_copy.c -o file_copy
./file_copy
```

## Sample run

```
$ ./file_copy
<name of existing file> student.dat
<name of new file> student_copy.dat
File copied successfully!
```

If the source file does not exist:

```
$ ./file_copy
<name of existing file> missing.dat
<name of new file> out.dat
Error opening source file: No such file or directory
```

## How it works

1. `open(src, O_RDONLY)` opens the source file.
2. `open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644)` creates or empties the destination file.
3. The loop calls `read()` to get up to 1024 bytes and `write()` to write them, until `read()` returns 0 (end of file).
4. If any system call fails, `perror()` prints the reason. Both file descriptors are closed at the end.
