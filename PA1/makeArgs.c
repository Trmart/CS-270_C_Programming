#include "makeArgs.h"


int makearg(char *s , char ***args)
{
    assert(s != NULL); 
    
    int argc = countWords(s); 
    
    *args = (char**)malloc(sizeof(char*) * argc); 

    int index = 0; 
    char *startPtr = NULL; 
    char *tempPtr = s; 

    for(int j = 0; j < argc; j++)
    {
        int strLen = 0; 
        
        while(isSpace(*tempPtr))
        {
            ++tempPtr; 
        }

        if(*tempPtr == '\0')
            break; 
        
        startPtr = tempPtr; 

        while(!isSpace(*tempPtr) && *tempPtr != '\0')
        {
            ++tempPtr; 
            ++strLen; 
        }

        (*args)[j] = (char*)malloc(sizeof(char) * (strLen + 1));  

        copyString(startPtr , (*args)[j], strLen); 
    }
    return argc;  
}


int countWords(char *s)
{
    int index = 0; 
    int argc = 0; 
    int whiteSpaceFlag = 1; 
    
    while(s[index] != '\0')
    {   if(!isSpace(s[index]))
        {
            whiteSpaceFlag = 0; 
            ++argc; 
            while(!whiteSpaceFlag && s[index] != '\0')
            {
                ++index; 
                whiteSpaceFlag = isSpace(s[index]); 
            }
        }
        else
        {
            ++index; 
        }
    }
    return argc; 
}


int isSpace(char c)
{
    return (c ==' '|| c == '\t' || c == '\n'); 
}


void copyString(char *source, char* destination, int n)
{
    for(int i = 0; i < n; i++)
    {
        destination[i] = source[i]; 
    }
    destination[n] = '\0'; 
}
