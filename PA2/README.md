# PA2: Systems Programming - File Operations (100 pts)

## Learner Objectives
At the conclusion of this programming assignment, participants should be able to:
* Understand the role and use of documentation
* Read, create, and write files using system calls
* Understand what file descriptors are
* Utilize buffering to make system calls more efficient
* Create their own version of the `tail` command

## Prerequisites
* Understanding of the lessons taught in Systems Programming - File Operations.

## Acknowledgements
Content used in this assignment is based upon information in the following sources:
* Understanding Unix/Linux Programming, A Guide to Theory and Practice by Bruce Molay

## Program Details


### Task 1 - Formatting date (5 pts)
1. The current implementation of `who2.c` prints the date as `Sep 29 08:43`. Fix the output so it will print out exactly as the `who` command does as `2020-09-29 08:43`. Read the manual for `ctime` found in section 3 in the manpages.
2. Update file header and function header comment if necessary.
3. Commit and push when completed.

### Task 2 - Buffering (20 pts)
1. Recall in class that system calls are expensive and time consuming under the hood. This makes the current implementation of `who2.c` inefficient as it does a system call for each `utmp` record. A better idea is to read in a bunch of records at once or add buffering to `who2.c`. 
2. For this task, you will use the starter codes inside `who3` folder that includes `who3.c`, `utmplib.c`, and `utmplib.h`. You only need to write the code for the functions in `utmplib.c`. However, it might be best to first check all three files and understand the flow of the program.
3. Update file header and function header comment if necessary.
4. Update the file header to minimize the number of includes.
5. You are also required to create a `Makefile` for this program.
6. Finally, in `who3.c` uncomment lines 52-53. Also, make sure to bring the changes you did in **Task 1** to this task.
7. Commit and push when completed.

### Task 3 - Preventing copying the same file (5 pts)
1. What does the standard `cp` do if you try to copy a file onto itself?
   ```
   $ cp file1 file1
   cp: 'file1' and 'file1' are the same file
   ```
2. Modify `cp1.c` to handle the situation.
3. Update file header and function header comment if necessary.
4. Commit and push when completed.

### Task 4 - Preventing file destruction (10 pts)
1. The standard version of `cp` silently overwrites existing files. The standard version of `cp` silently overwrites existing files. That is, if you have a file called `file2`, and you type 
   ```
   $ cp file1 file2
   ```
   you destroy the original contents of `file2`. The standard version of `cp` does support a `-i` option that causes the program to ask you before writing over a file. 
   ```
   $ cp -i file1 file2
   cp: overwrite 'file2.txt'?
   ```
   If you use the `-i` option and `file2` does not exist, then no prompt is given.
2. Your task is to add this feature to the `cp1.c` as a default feature. No need to look for `-i` option for `cp1`.
3. Update file header and function header comment if necessary.
4. Commit and push when completed.

### Task 5 - Your version of the `tail` command (60 pts)
The `lseek` system call allows you to move the current position anywhere in a file. The call `lseek(fd, 0, SEEK_END)` moves the current position to the end of the file.

The `tail` command displays the last ten liens of a file. Try it. `tail` has to move, not to the end of the file, but to a spot ten lines before the end of a file. The distance argument to `lseek`, though, is in units of characters (bytes).

How can `tail` work? Design your own version. Think about buffering to make your program efficient. Read the manual page to see all the options `tail` supports. How would those work? Designing this program seems, like `who` and `cp`, to be a straightforward project.

Commit and push your code during your development process. Make sure you have file header comments and function header comments. Also, write inline comments whenever necessary.

## Bonus Points (10 pts)
Add more functionality to these commands and I will decide whether its worth 10 points. Add a text file called `features.txt` and describe what features you've added to either `who`, `cp`, `tail` outside the scope of this PA, and describe how to use these features.

## Submitting Assignments
* It is VERY IMPORTANT that besides pushing the code to GitHub that you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
