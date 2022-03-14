/**
 * @file cp1.c
 * @author Taylor Martin
 * @brief Uses read and write with tunable buffer size
 *        usage: cp1 src dest
 * @version 0.1
 * @date 10/22/2021
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>
#define BUFFERSIZE   4096
#define COPYMODE     0644

void oops(char *, char *);
bool isExistingFile(char* fileName2); 
bool isSameINodeNum(char* fileName1, char* fileName2); 


int main(int argc, char *argv[])
{
    int infd, outfd, nChars;
    char buf[BUFFERSIZE];
    char *fileName1 = argv[1]; 
    char *fileName2 = argv[2]; 

    // check args
    if (argc != 3)
    {
        fprintf(stderr, "usage: %s source destination\n", *argv);
        exit(1);
    }

    // open files
    if ((infd = open(fileName1, O_RDONLY)) == -1)
    {
        oops("Cannot open ", fileName1);
    }

    if ((outfd = creat(fileName2, COPYMODE)) == -1)
    {
        oops("Cannot open ", fileName2);
    }
    if(isSameINodeNum(fileName1,fileName2)==true); 
    {
        oops("Cannot copy " , fileName1); 
        exit(1); 
    }

    if(isExistingFIle(fileName2)==true)
    {
        printf("The file %s already exists" , fileName2); 
        printf("CP: Overwrite '%s'?\nEnter 'y' for yes or 'n' for no: ",fileName2); 

        char choice; 
        choice = scanf("%c",&choice); 

        switch(choice)
        {
            case 'y':
                printf("Override initiated, copying file"); 
                break; 
            case 'Y':
                printf("Override initiated, copying file"); 
                break; 
            case 'n':
                printf("Process Terminated, File Preserved"); 
                exit(1); 
            case 'N':
                printf("Process Terminated, File Preserved"); 
                exit(1); 
            default:
                printf("Process Terminated, File Preserved"); 
                exit(1); 
        }
    }
    // copy files
    while ((nChars = read(infd, buf, BUFFERSIZE)) > 0)
    {
        if (write(outfd, buf, nChars) != nChars)
        {
            oops("Write error to ", fileName2);
        }
    }
    if (nChars == -1)
    {
        oops("Read error from ", fileName1);
    }

    if (close(infd) == -1 || close(outfd) == -1)
    {
        oops("Error closing files", "");
    }

    return 0;
}

/**
 * @brief Displays error to the standard error and
 *        prints error by the system call using perror().
 *        Program terminates when this function is called.
 * 
 * @param s1 type of error
 * @param s2 file that cause the error
 */
void oops(char *s1, char *s2)
{
    fprintf(stderr, "Error: %s ", s1);
    perror(s2);
    exit(1);
}

/**
 * @brief uses a stat member function called access
 *         to check if the file name already exists 
 *         within the directory. 
 * 
 * @param fileName2 
 */
bool isExistingFIle(char* fileName2)
{
    if(access(fileName2,F_OK) != -1)
    {
        return true; //file exists and was found in directory 
    }
    return false;  //file was not found within directory, doesn't currently exist. 
}

/**
 * @brief checks to see if the Inode numbers are the same 
 *          between two files. 
 * 
 * @param fileName1 
 * @param fileName2
 */
bool isSameINodeNum(char* fileName1, char* fileName2)
{
    struct stat src,dst; 
    int error = stat(fileName1, &src); 

    if(error < 0)
    {
        perror("stat"); 
        exit(1); 
    }

    error = stat(fileName2,&dst); 

    if(error < 0)
    {
        perror("stat"); 
        exit(1); 
    }

    if((src.st_ino == dst.st_ino) && (src.st_dev == dst.st_dev))
    {
        printf("cp: '%s' and '%s' are the same file\n", fileName1, fileName2);
        return true;
    }
    return false; 
}
