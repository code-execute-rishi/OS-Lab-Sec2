# Lab 2 — vi Editor

**Aim:** Use the `vi` editor for the following tasks.

---

### (a & b) Use `vi` to create a file that contains some text. Give the user and others read and write permission only, and give the group write permission only. Check the file permissions.

```bash
$ vi sample.txt
```

Press `i` to start insert mode. Type the text, press `Esc`, then type `:wq` to save and quit:

```
Welcome to the UNIX lab
This is a text file for vi editor operations.
~
~
:wq
```

Set and check the permissions:

```bash
$ chmod 626 sample.txt
$ ls -l sample.txt
```

```
-rw--w-rw- 1 student student 70 Aug 16 18:35 sample.txt
```

| Who | Octal | Permission |
|-----|-------|------------|
| User  | 6 | `rw-` (read + write) |
| Group | 2 | `-w-` (write only)   |
| Other | 6 | `rw-` (read + write) |

---

### (c) Write the commands that do these tasks in the `vi` editor

| Task | Command |
|------|---------|
| Start insert mode | `i` |
| Append text after the cursor | `a` |
| Add text at the end of the current line | `A` |
| Delete the current line | `dd` |
| Undo the last change | `u` |
| Move the cursor to the end of the line | `$` |
| Move the cursor to the start of the line | `0` |
| Search forward for a pattern | `/pattern` |
| Search backward for a pattern | `?pattern` |
| Save the current file | `:w` |
| Discard changes and go back to the shell | `:q!` |
| Save changes and go back to the shell | `:wq` |
