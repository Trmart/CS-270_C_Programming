/**
 * @file shell.c 
 * @author Taylor Martin
 * @brief shell functions definitions
 * @version 0.1
 * @date 11-17-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h> // exit
#include <unistd.h> // fork, exec, chdir
#include <sys/wait.h> // wait
#include <sys/stat.h>
#include <stdbool.h>

/**
 * @brief Split string cmd into arguments where
 *        each pointer element of arglist is pointing
 *        to a string in cmd. 
 * 
 * @param command     string command
 * @param arglist[]  string arguments as an array of pointers
 *                   to C-strings
 * @return int     number of arguments in cmd
 */

int commandToArray(char* command, char* arglist[])
{
    int argc = 0; //number of arguments
    bool newString = false; // new string encounter flag
    int length = strlen(command); //length of command

    for (int i = 0; i < length; ++i)
    {
        if(command[i] == ' ' && newString == 0)
        {
            newString = true; // set new string to true. 
            arglist[argc] = &command[i]; //assign element of arglist with command
            ++argc; //increment argument counter
        }
        else if (command[i] == ' ')
        {
            newString = false; 
            command[i] = '\0';
        }
    }
    arglist[argc] = NULL; 
    return argc; // returns number of arguments
    

}

/**
 * @brief spawns a child process and executes sent in command string
 * 
 * @param arglist[]  string arguments as an array of pointers
 *                   to C-strings
 */
void execute(char* arglist[])
{
    int pid, exit_status; 
    pid = fork(); // spawn child process

    if(pid == -1)
    {
        perror("FORK FAILED. TERMINATING PROCESS"); 
        exit(1); //exit process
    }
    else if(pid==0)
    {
        execvp(arglist[0], arglist); // run command with arguments
        // cannot return after execvp
        fprintf(stderr, "CANNOT EXECUTE COMMAND: %s\n", arglist[0]);
        exit(1); //exit if execvp FAILED
    }
    else
    {
        int got_pid = wait(&exit_status); // suspends current process until child terminates

        if(got_pid == pid) // if process exited successfully
        {
            if(WIFEXITED(exit_status)) // if child terminates successfully
            {
                printf("pid=%d EXITED SUCCESSFULLY WITH STATUS %d\n", pid,WEXITSTATUS(exit_status)); 
                //WEXITSTATUS returns the exit status of the child process.
                //only employed if WIFEXITED returned true
            }
        }
        else if(got_pid == -1) // if wait for process FAILED
        {
            perror("WAIT PROCESS FAIL");
        }
    }
}

/**
 * @brief changes the current working directory
 * 
 * @param arglist[]  string arguments as an array of pointers
 *                   to C-strings
 */
void cd(char* arglist[])
{
    int directoryCheck = 0;
    directoryCheck = chdir(arglist[1]); //use chdir to change directory

    if(directoryCheck==0) // if chdir was successfull returns 0
    {
        if(strcmp(arglist[1],"..") != 0)
        {
            printf("YOU HAVE MOVED INTO THE SUBDIRECTORY PATH: %s\n", arglist[1]); 
        }
        if(strcmp(arglist[1],"..") == 0) //
        {
            printf("YOU HAVE MOVED INTO THE PARENT DIRECTORY PATH: %s\n", arglist[1]); 
        }
    }
    if(strmcmp(arglist[0],"cd"))
    {
        chdir(getenv("HOME"));
        printf("YOU ARE NOW IN THE HOME DIRECTORY"); 
    }
    if(strcmp(arglist[1],"~"))
    {
        chdir(getenv("HOME"));
        printf("YOU ARE NOW IN THE HOME DIRECTORY"); 
    }
}

/**
 * @brief this function will create a new hidden directory in 
 *  user's home directory called ".junk".
 * the junk command will take unwanted files and move them into .junk
 * with -l as arglist[1] it will list all files currently inside of the.junk directory
 * with -p as arglist[1] it will remove all files currently inside of the .junk directory
 * 
 * @param arglist[]  string arguments as an array of pointers
 *                   to C-string
 */
void junkDirectory(char* arglist[])
{
    char currentWorkingDirectory[PATH];
    char *path;
    int pid, exitstatus;

    if (getcwd(currentWorkingDirectory, sizeof(currentWorkingDirectory)) != NULL)
    {
        path = getcwd(currentWorkingDirectory, sizeof(currentWorkingDirectory));
    }
    chdir(path);

    // if arglist [1] is a regular file, move it to the junk folder
    if (access(arglist[1], F_OK) == 0)
    {
        moveJunk(arglist);
    }
    else if (access(arglist[1], F_OK) != 0)
    {
        // list all the files in .junk
        if (strcmp(arglist[1], "-l") == 0)
        {
            listJunkContents(arglist);
            chdir(path);
        }
        // else if arglist[1]  == "-p"
        else if (strcmp(arglist[1], "-p") == 0)
        {
            deleteJunkContents(arglist);
            chdir(path);
        }
        else
            fprintf(stderr, "\nIncorrect usage:\nsyntax or non-existing file: %s\n\nCorrect format: junk filename.ext or -l or -p\n\n", arglist[1]);
    }
}


/**
 * @brief creates a junk directory if one doesn't already exist
 * 
 */

void createJunk()
{
    char* currentWorkingDirectory[PATH]; //create an string to hold our cwd
    char* path; //stores cwd for further use
    if(getcwd(currentWorkingDirectory, sizeof(currentWorkingDirectory))!= NULL)
    {
        path = getcwd(currentWorkingDirectory, sizeof(currentWorkingDirectory)); 
    }
    chdir(getenv("HOME")); 
    struct stat directoryStat = {0};
    
    if(stat(".junk", &directoryStat) == -1)
    {
        mkdir(".junk" , 0777); //create directory with 0777 permissions. (Read,Write,Execute) 
        printf(".junk directory has been created\n");
    }
    chdir(path);
}

/**
 * @brief Moves items into junk directory
 * 
 * @param arglist[]  string arguments as an array of pointers
 *                   to C-strings
 */
void moveJunk(char* arglist[])
{
    char homePath[256]; 
    strcpy(homePath, getenv("HOME")); //gets the home path
    strcat(homePath,"/.junk/"); //appends /.junk/ to the path

    //append the file name to end of homePath
    strcat(homePath, arglist[1]); //

    if(rename(arglist[1],homePath) == 0)
    {
        printf("FILE %s HAS BEEN MOVED INTO THE JUNK DIRECTORY\n",arglist[1]);
    }
}

/**
 * @brief lists the contents of the junk directory
 *
 * @param arglist[]  string arguments as an array of pointers
 *                   to C-string
 */
void listJunkContents(char* arglist[])
{
    int pid, exit_status;

    pid = fork(); //create child process

    if(pid == -1) //
    {
        printf("FAILED TO CREATE CHILD PROCESS. TERMINATING PROCESS");
        exit(1); 
    }
    else if(pid == 0)
    {
        chdir("HOME"); 
        if(chdir(".junk") != 0)
        {
            printf("JUNK FOLDER IS CURRENTLY EMPTY\n"); 
        }
        else
        {
            execlp("ls", "ls", "-l", NULL);
            //since execlp cannot return 
            fprintf(stderr, "CANNOT EXECUTE COMMAND: %s\n", arglist[0]);
        }
        exit(1); //exit if execvp FAILED
    }
    else
    {
        int got_pid = wait(&exit_status);
        if(got_pid == pid)
        {
            if(WIFEXITED(exit_status))
            {
                printf("pid=%d\n EXITED SUCCESSFULLY WITH STATUS: %d\n", pid,WEXITSTATUS(exit_status));
            }
            else if(got_pid==-1)
            {
                perror("WAIT FAILED");
            }
        }
        else if(got_pid == -1)
        {
            printf("WAIT PROCESS FAILED\n");
        }
    }
}

/**
 * @brief empties the junk directory
 * 
 * @param arglist[]  string arguments as an array of pointers
 *                   to C-string
 */
void deleteJunkContents(char* arglist[])
{
    struct dirent* dirEntryPtr; //create directory structure pointer 

    char homePath[256]; 

    strcpy(homePath,getenv("HOME")); //retrieve and copy home path to homePath
    strcat(homePath,"/.junk"); //append .junk to homePath
    chdir(homePath); //change to homePath directory

    DIR* dirPtr = opendir("."); //create a directory pointer to read directory contents
    if(dirPtr==NULL)
    {
        printf("COULD NOT OPEN DIRECTORY. TERMINATING PROCESS\n");
        exit(1);
    }

    while(dirEntryPtr = readdir(dirPtr) != NULL)
    {
        //if the directory entry is a file then
        if(access(dirEntryPtr->d_name, F_OK) == 0)
        {
            //delete the file
            unlink(dirEntryPtr->d_name);
        }
    }
    closedir(dirPtr);
    printf("DELETION PROCESS COMPLETE. .junk IS NOW EMPTY\n\n .junk CONTENTS:");
    listJunkContents(arglist);
}