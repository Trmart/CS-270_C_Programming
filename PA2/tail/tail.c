/**
 * @file cp1.c
 * @author Taylor Martin
 * @brief tail definitions file 
 * @version 0.1
 * @date 10/24/2021
 * 
 */
#include "tail.h"

void tail(FILE* fp, int lines)
{
    int num_new_lines = 0; 

    unsigned long long position; 
    char str[2*SIZE]; 

    if(fseek(fp,0,SEEK_END))
    {
        perror("fseek() FUNCTION HAS FAILED"); 
    }
    else
    {
        position = ftell(fp); 

        while(position)
        {
            if(!fseek(fp,--position,SEEK_SET))
            {
                if(fgetc(fp) == '\n')
                {
                    if(num_new_lines++ == lines)
                    {
                        break; 
                    } 
                }
            }
            else
            {
                perror("fseek() FUNCTION HAS FAILED"); 
            }
        }
        while(fgets(str,sizeof(str),fp))
        {
            if(num_new_lines == 10)
            {
                printf("%s",str); 
            }
        }
    }

}