#include <cstdio>
#include "makeArgs.h"

using namespace std; 



int main()
{
    const int MAX_SIZE = 512; 
    char **args, arr[MAX_SIZE]; 

    printf("$ "); 
    
    fgets(arr, MAX_SIZE , stdin); 

    int argc = makearg(arr,&args); 

    printf("\n"); 

    for(int i = 0; i < argc ; i++)
    {
        printf("%d: %s\n", i , args[i]); 
    }

    return 0; 
}
