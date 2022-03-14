/**
 * @file main.c
 * @author Taylor Martin
 * @brief uses directory_operations.h and directory_operations.c 
 *        to implement my own versions of ls and -ialR in linux 
 * @version 0.1
 * @date 10/24/2021
 * 
 */
#include "directory_operations.h"

int main(int argc, char* argv[])
{
    if (argc == 1) // change back to 1
    {
        ls(".");
    }
    else if(argc == 2)
    {
        // identifies the '-' as a flag in argv[1]
        char *flag = strrchr(argv[1], '-');
        char *a = strrchr(argv[1], 'a');
        char *i = strrchr(argv[1], 'i');
        char *l = strrchr(argv[1], 'l');
        char *R = strrchr(argv[1], 'R');
        char *str = argv[1];

        if (flag)
        {
            if (a && i && l && R)
            {
                lsialR(".");
            }
            else
            fprintf(stderr,"incorrect format for flag: -ialR\n");
        }
    }
    else
    {
        while (--argc)
        {
            printf("%s:\n", *++argv);
            ls(*argv);
        }
    }
    return 0; 
}