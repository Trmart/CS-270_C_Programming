/**
 * @file mv.c
 * @author Taylor Martin
 * @brief implements my own version of linux mv 
 * @version 0.1
 * @date 11/1/2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
/**
 * @brief  Using DIR *ptr this function will handle distinguishing between 
 * file renames commands and moving files to directory targets.
 * it will also utilize strcat to append the correct file directory 
 * path to the new directory.
 * 
 * @param fName // argv[1] or the given file name to be renamed or moved 
 * 
 * @param renameOrMvDir // parameter that will be evaluated as a new file name 
 *  or directory target location.
 * 
 * @param dest // a string buffer that will have strcat append the path of the
 * target directory to rename the file to.
 */
void mv(char* file_name, char* destination_name)
{
    int result = rename(file_name,destination_name); 

    if(destination_name[0] == '/')
    {
        if(result == 0)
        {
            printf("DIRECTORY WAS FOUND\n"); 
        }
        else
        {
            perror("THE DIRECTORY WAS NOT FOUND, EXITING PROGRAM"); 
            exit(1); 
        }
        
    }
    
    else
    {
        DIR *dirPtr = opendir(destination_name); // pointer to directory struct _dirstream 

        if(dirPtr == NULL)
        {
            if(result != 0)
            {
                perror("A NEW FILENAME WAS NOT ENTERED"); 
                exit(1); 
            }
            else
            {
                printf("OPERATION COMPLETE. RENAMED FILE %s TO %s \n",file_name,destination_name); 
            }
        }
        else
        {
            if(rename(file_name,destination_name) != 1)
            {
                printf("%s HAS BEEN MOVED TO %s\n",file_name,destination_name); 
            }
            else
            {
                perror("ERROR: TARGET DIRECTORY DOES NOT EXIST IN CURRENT WORKING DIRECTORY\n"); 
                exit(1); 
            }
        }
    }
    
}

int main(int argc, char* argv[])
{
    char *file_name = argv[1]; 
    char *destination_name = argv[2]; 
    if(argc > 3)
    {
        perror("EXCEEDS THE LIMITED NUMBER OF VALID ARGUMENTS"); 
    }
    else
    {
        mv(file_name,destination_name); 
    }
    return 0; 
}