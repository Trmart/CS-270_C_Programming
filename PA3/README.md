# PA3: Linux Directories, File Properties, and the File System (100 pts)

## Learner Objectives
At the conclusion of this programming assignment, participants should be able to:
* Create their own version of the `mv` command
* Create their own version of the `find` command
* Create their own version of the `ls -ialR` command

## Prerequisites
* Understanding of the lessons taught on Directories and File Properties.
* Understanding of the lessons taught on File Systems.

## Acknowledgements
Content used in this assignment is based upon information in the following sources:
* Understanding Unix/Linux Programming, A Guide to Theory and Practice by Bruce Molay

## Program Details

### Task 1 - Your version of `mv` command (20 pts)
1. The `mv` command is more than just a wrapper around the `rename` system call. Write a version of `mv` that accepts two argument. The first argument must be the name of a file, and the second argument may be the name of a file or the name of a directory. If the destination is the name of a directory, then `mv` moves the file into that directory. Otherwise `mv` rename the file if possible.
2. Commit and push when completed.

### Task 2 - Your version of `find` command (20 pts)
1. Try running the `find` command in the shell and observe the output. Try it in different folders to make sure you understand what it prints out.

   ```$ find```
   
2. Write your version of the `find` command.
3. Commit and push your during your development process.

### Task 3 - Your version of the `ls -ialR` command (60 pts)
1. Write your version of `ls -ialR` command. In this version of `ls`, you must also consider symbolic file types.
2. Commit and push your code during your development process. Make sure you have file header comments and function header comments. Also, write inline comments whenever necessary.

## Bonus Points (5 pts)
Sort the filenames of **Task 5** to get the exact result of `ls -ialR` command.

## Submitting Assignments
* It is VERY IMPORTANT that besides pushing the code to GitHub that you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**
