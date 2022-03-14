# PA4: C System Call vs Bash Programming (100 pts)

## Learner Objectives
At the conclusion of this programming assignment, participants should be able to:
* Write bash scripts and call shell commands inside the script
* Use bash constructs
* Use system calls in C programs

## Prerequisites
* Understanding of the lessons taught on Bash Programming
* Understanding of the lessons taught on Directories and File Properties.
* Understanding of the lessons taught on File Systems.

## Acknowledgements
Content used in this assignment is based upon information in the following sources:
* Linux for Programmers and Users by Glass and Ables

## Program Details

Write a utility called **`junk`** that satisfies the following specification:

*Utility:* **`junk`** [-l] [-p] { *fileName }\*

**`junk`** is a replacement for the **`rm`** utility. Rather than removing files, it moves them into the subdirectory **.junk** in your **home directory**. If **.junk** doesn't exist, it is automatically created. The **`-l`** option lists the current contents of the **.junk** directory, and the **`-p`** option purgest **.junk**.

Here's an example of **`junk`** at work:
```bash
$ ls -lG
-rw-r--r-- 1 gvdelacruz   18 Sep 17 14:24 README.md
-rw-r--r-- 1 gvdelacruz   18 Sep 17 14:24 a.txt
$ junk README.md
$ ls -lG README.md
ls: cannot access 'README.md': No such file or directory
$ junk a.txt
$ junk -l
-rw-r--r-- 1 gvdelacruz   18 Sep 17 14:24 README.md
-rw-r--r-- 1 gvdelacruz   18 Sep 17 14:24 a.txt
$ junk -p
$ junk -l
```

### Task 1 - Write **`junk`** using Bash Programming (50 pts)
* Useful to look at additional [test conditions](https://www.gnu.org/software/bash/manual/html_node/Bash-Conditional-Expressions.html#Bash-Conditional-Expressions) available in Bash

### Task 2 - Write **`junk`** using C Programming with System Calls (50 pts)


## Submitting Assignments
* It is VERY IMPORTANT that besides pushing the code to GitHub that you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
