/**
 * @file directory_operations.h
 * @author Taylor Martin
 * @brief directory_operations initialization file
 * @version 0.1
 * @date 11/1/2021
 * 
 */

#ifndef DIRECTORYOPERATIONS_H
#define DIRECTORYOPERATIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h> 
#include <grp.h>
#define MAX_PATH 512

void ls(const char *directory_name);
void lsialR(const char *directory_name);
void showStatInfo(const char *file_name, struct stat *buffer);
void modeToLetters(int mode, char str[]);
char* uidToName(uid_t id);
char* gidToName(gid_t id);

#endif