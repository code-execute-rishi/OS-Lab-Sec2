# Lab 1

**Aim:** Use suitable UNIX commands to perform the following activities.

### (a) Find the number of CPU cores on your machine

```
$ nproc
8
```

### (b) Display the information about the total and available space on the file system. The sizes should be printed in powers of 1024 (eg. 1023M)

```
$ df -h
Filesystem      Size  Used Avail Use% Mounted on
/dev/sda1       250G   45G  193G  19% /
tmpfs           7.8G     0  7.8G   0% /dev/shm
/dev/sda2       950M  120M  830M  13% /boot
```

### (c) Display all the processes running in your system. The output should contain the following details: User ID, Process ID, Parent process ID, process name

```
$ ps -ef
UID        PID  PPID  C STIME TTY          TIME CMD
root         1     0  0 09:00 ?        00:00:02 /sbin/init
root       412     1  0 09:00 ?        00:00:00 /usr/sbin/sshd
student   1240   412  0 09:15 pts/0    00:00:00 bash
student   1582  1240  0 09:15 pts/0    00:00:00 ps -ef
```

### (d) Display the list of files in your directory sorted in an order where the newest file should appear in the bottom of the list

```
$ ls -ltr
total 16
-rw-r--r-- 1 student student  412 Aug 10 10:00 a.txt
-rw-r--r-- 1 student student 1024 Aug 14 14:20 b.pdf
-rw-r--r-- 1 student student  256 Aug 16 11:45 c.sh
-rw-r--r-- 1 student student   85 Aug 16 18:00 d.py
```

### (e) Create a file named 'student.dat' and record course name, roll no, and student name about at least 10 students from different courses into it. Each field should be separated by a , (comma). Use 'cat' command with redirection to create this file.

```
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
