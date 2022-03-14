/**
 * @file find.c
 * @author Taylor Martin
 * @brief implements my own version of find in linux
 * @version 0.1
 * @date 11/1/2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
/**
 * @brief finds directory called directory_name and prints contents
 * 
 * @param directory_name
 */
void find(char* directory_name)
{
    DIR *dirPtr; 
    struct dirent *pDirent; 

    if(dirPtr = open(directory_name) == NULL)
    {
        fprintf(stderr, "ls: CANNOT OPEN %s\n", directory_name); 
    }
    else
    {
        while(pDirent = readdir(dirPtr) != NULL)
        {
            if(pDirent->d_name[0] == '.' && pDirent->d_name[1] == '.')
            {
                printf("%s\n",pDirent->d_name); 
            }
            else if(pDirent->d_name[0] == '.' && pDirent->d_name[1] == '.')
            {
                continue; 
            }
            else
            {
                printf("./%s\n", pDirent->d_name); 
            }
        }
        closedir(dirPtr); 
    }
}

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        find("./"); 
    }
    else
    {
        while(--argc)
        {
            printf("%s:\n", *++argv); 
            find(*argv); 
        }
    }
    return 0; 
}