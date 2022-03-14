/**
 * @file main.c 
 * @author Taylor Martin
 * @brief custom shell environment
 * @version 0.1
 * @date 11-17-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "shell.h"
#include <stdio.h>
#include <string.h> // strcmp
#include <stdlib.h> // exit

#define MAX_ARGS 20
#define MAX_ARG_LEN 256

int main() 
{
    char* arglist[MAX_ARGS+1];
    char command[MAX_ARG_LEN];

    while(1)
    {
        printf("Trmart_Shell->");
        fgets(command, MAX_ARG_LEN, stdin);
        //remove newline character from command string
        command[strlen(command) - 1] = '\0';
        //if the user types exit
        if(strcmp(command,"exit") == 0)
        {
            exit(0);//exit successfully
        }
        else if(*command != '\0')
        {
            int numArgs = commandToArray(command,arglist); 

            if(strcmp(arglist[0],"cd") == 0)
            {
                if(numArgs == 2)
                {
                    cd(arglist);
                } 
            }
            else if(strcmp(arglist[0],"junk") == 0)
            {
                if (numArgs == 1)
                {
                    createJunk(); 
                }
                else if (numArgs == 2)
                {
                    junkDirectory(arglist);
                }
                
            }
            else
            {
                execute(arglist);
            }
        }

    }
    return 0;
}