**
 * @file main.c
 * @author Taylor Martin
 * @brief uses tail.h and tail.c to implement my own version of tail in linux 
 * @version 0.1
 * @date 10/24/2021
 * 
 */
#include "tail.h"

int main(int  argc, char* argv[])
{
    
    char* p;
    int num_lines=0; 

    if(argc < 2)
    {
        printf("NO FILE SPECIFIED IN COMMAND LINE, TERMINATING PROCESS"); 
        exit(1); 
    } 
    
    FILE *fp=fopen(argv[1], "r"); 
    if(fp == NULL)
    {
        printf("THERE WAS AN ERROR OPENING YOUR FILE, TERMINATING PROCESS"); 
        exit(1); 
    }
    if(argc==2)
    {
        for(int i = 0; i < 10; i++)
        {
            tail(fp,i); 
        }
    }
    printf("\n"); 
    
    close(fp); 
    return 0; 
}
