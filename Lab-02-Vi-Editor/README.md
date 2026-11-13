# Lab 2

**Aim:** Use vi editor for the following activities.

### (a & b) Create file containing any text using vi editor. Grant user and other users permissions for reading and writing only and group for writing only. Check the file permissions.

```
$ vi sample.txt
```

```
Welcome to the UNIX lab
This is a text file for vi editor operations.
~
~
:wq
```

```
$ chmod 626 sample.txt
$ ls -l sample.txt
-rw--w-rw- 1 student student 67 Aug 16 18:35 sample.txt
```

### (c) Write the methods/commands for performing the following task in the 'vi' editor

| Task | Command |
|------|---------|
| Enable insert mode | `i` |
| Append text at current position | `a` |
| Add text at the end of the current line | `A` |
| Delete an entire line | `dd` |
| Undo the most recent change | `u` |
| Move cursor to the end of the line | `$` |
| Move cursor to the beginning of the line | `0` |
| Search for a pattern in the forward direction | `/text` |
| Search for a pattern in backward direction | `?UNIX` |
| Save the current file | `:w` |
| Abort changes and exit to shell prompt | `:q!` |
| Save changes and exit to shell prompt | `:wq` |
