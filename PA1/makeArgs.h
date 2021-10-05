
#ifndef MAKEARGS_H
#define makeArgs_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>


int makearg(char *s,char ***args); 
int countWords(char *s); 
int isSpace(char c); 
void copyString(char *source, char* destination, int n); 


#endif
