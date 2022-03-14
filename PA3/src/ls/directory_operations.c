/**
 * @file directory_operations.c
 * @author Taylor Martin
 * @brief directory_operations definitions file 
 * @version 0.1
 * @date 11/1/2021
 * 
 */
#include "directory_operations.h"

/**
 * @brief List files in directory called directory_name
 * 
 * @param directory_name
 */
void ls(const char *directory_name)
{
    DIR *dirPtr; //pointer to the directory 
    struct dirent *pDirent; //each entry in directory 

    if(dirPtr = open(directory_name) == NULL)
    {
        fprintf(stderr,"ls: CANNOT OPEN %s\n,",directory_name); 
    }
    else
    {
        while(pDirent = readdir(dirPtr) != NULL)
        {
            char *file_name[MAX_PATH]; 
            struct stat info; 

            strcpy(file_name,directory_name); 

            if(directory_name[strlen(directory_name) - 1] != '/')
            {
                strcat(file_name,"/"); 
            }
            strcat(file_name,pDirent->d_name);

            if(stat(file_name, &info) != -1)
            {
                showStatInfo(pDirent->d_name, &info); 
            }

            else
            {
                perror(pDirent->d_name); 
            }

        }
        close(dirPtr); 
    }
}

void lsialR(const char *directory_name)
{
    DIR *dirPtr; 
    struct dirent *pDirent; 

    if(dirPtr= opendir(directory_name) == NULL)
    {
        fprintf(stderr, "ls: CANNOT OPEN %s\n", directory_name); 
    }
    else
    {
        printf(".:\n"); 

        while(pDirent = readdir(dirPtr) != NULL)
        {
            char file_name[MAX_PATH]; 
            struct stat info, *buff; 

            strcpy(file_name,directory_name); 

            if(directory_name[strlen(directory_name) - 1] != '/')
            {
                strcat(file_name,"/"); 
            }
            strcat(file_name,pDirent->d_name); 

            if(stat(file_name,&info) != -1)
            {
                showStatInfo(pDirent->d_name,&info); 
            }
            else
            {
                perror(pDirent->d_name); 
            }
        }
        closedir(dirPtr); 
    }
}

void showStatInfo(const char *file_name, struct stat *buffer)
{
    if(file_name[0] == '.')
    {
        return;
    }

    char strMode[11]; 
}

void modeToLetters(int mode, char str[])
{
    strcpy(str,"----------"); 
    if(S_ISDIR(mode)) str[0] = 'd'; 
    if(S_ISCHR(mode)) str[0] = 'c'; 
    if(S_ISBLK(mode)) str[0] = 'b'; 

    // 3 bits for user
    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';

    // 3 bits for group
    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';

    // 3 bits for other
    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';
}

char* uidToName(uid_t id)
{
    return getpwuid(id)->pw_name; 
}

char* gidToName(gid_t id)
{
    return getgrgid(id)->gr_name; 
}