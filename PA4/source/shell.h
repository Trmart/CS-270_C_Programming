/**
 * @file shell.h
 * @author Taylor Martin
 * @brief shell module initialization
 * @version 0.1
 * @date 11-17-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SHELL_H
#define SHELL_H

#define PATH 1024
#define UNAME 1024

//ints
int commandToArray(char* command, char* arglist[]); 

//voids
void execute(char* arglist[]); 
void cd(char* arglist[]); 
void junkDirectory(char* arglist[]); 

//helper functions for junkDirectory()
void createJunk();
void moveJunk(char* arglist[]);
void listJunkContents(char* arglist[]);
void deleteJunkContents(char* arglist[]);

#endif 