/**
 * @file utmplib.h
 * @brief Interface file for utmp buffering.
 * @version 0.1
 * @date 2020-09-29
 * 
 */
#ifndef UTMPLIB_H
#define UTMPLIB_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <utmp.h>

int utmpOpen(char *filename);
struct utmp* utmpNext();
int utmpReload();
void utmpClose();

#endif