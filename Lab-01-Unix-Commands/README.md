# Lab 1 — UNIX Commands

**Aim:** Use suitable UNIX commands to do the following tasks.

> The outputs below were taken on the lab's Linux machine. Your values will be different.

---

### (a) Find the number of CPU cores on your machine

```bash
$ nproc
```

```
8
```

---

### (b) Show the total and available space on the file system, with sizes in powers of 1024 (for example, 1023M)

```bash
$ df -h
```

```
Filesystem      Size  Used Avail Use% Mounted on
/dev/sda1       250G   45G  193G  19% /
tmpfs           7.8G     0  7.8G   0% /dev/shm
/dev/sda2       950M  120M  830M  13% /boot
```

`-h` prints human-readable sizes in powers of 1024. (`-H` uses powers of 1000.)

---

### (c) Show all the processes that run on your system, with User ID, Process ID, Parent Process ID and process name

```bash
$ ps -ef
```

```
UID        PID  PPID  C STIME TTY          TIME CMD
root         1     0  0 09:00 ?        00:00:02 /sbin/init
root       412     1  0 09:00 ?        00:00:00 /usr/sbin/sshd
student   1240   412  0 09:15 pts/0    00:00:00 bash
student   1582  1240  0 09:15 pts/0    00:00:00 ps -ef
```

To show only the four required columns: `ps -eo user,pid,ppid,comm`

---

### (d) List the files in your directory, sorted so that the newest file is at the bottom of the list

```bash
$ ls -ltr
```

```
total 16
-rw-r--r-- 1 student student  412 Aug 10 10:00 a.txt
-rw-r--r-- 1 student student 1024 Aug 14 14:20 b.pdf
-rw-r--r-- 1 student student  256 Aug 16 11:45 c.sh
-rw-r--r-- 1 student student   85 Aug 16 18:00 d.py
```

`-t` sorts by modification time (newest first). `-r` reverses the order, so the newest file is last.

---

### (e) Use `cat` with redirection to create a file named `student.dat`. Each record has the course name, roll number and student name for at least 10 students from different courses. Separate the fields with a comma (`,`).

```bash
$ cat > student.dat
BTech CSE,101,Aarav Sharma
BTech ECE,102,Priya Patel
BTech ME,103,Rohan Verma
BTech EE,104,Ananya Gupta
BTech CE,105,Vikram Singh
BTech CSE,106,Ishaan Kumar
BTech IT,107,Neha Mishra
BTech ECE,108,Devansh Joshi
BTech MME,109,Sanya Malhotra
BTech CSE,110,Ketan Reddy
^D
```

Press `Ctrl+D` to end the input and save the file. The result is in [`student.dat`](student.dat).
