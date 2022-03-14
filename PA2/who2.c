/**
 * @file who2.c
 * @author Taylor Martin
 * @brief Second version of the who program open,
 *        read UTMP file, and show results
 *        - suppress empty records
 *        - format time nicely
 * @version 0.2
 * @date 10/19/21
 * 
 */
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h> // exit()

#define SHOWHOST  // include remote machine an output

void showTime(long timeval);
void showInfo(struct utmp *utbufp);

int main()
{
    struct utmp currentRecord;  // read info into here
    int utmpfd;                  // read from this descriptor
    int reclen = sizeof(struct utmp); 

    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
    {
        perror(UTMP_FILE);   // UTMP_FILE is in utmp.h
        exit(1);
    }

    while (read(utmpfd, &currentRecord, reclen) == reclen)
    {
        showInfo(&currentRecord);
    }

    close(utmpfd);
    return 0;
}

/**
 * @brief Displays contents of the utmp struct in human readable form
 *        *note* these sizes should not be hardwired
 * 
 * @param utbufp pointer to struct utmp data
 */
void showInfo(struct utmp *utbufp)
{
    // not a user process, exclude
    if (utbufp->ut_type != USER_PROCESS)
        return;

    // the logname
    printf("%-8.8s ", utbufp->ut_name);

    // the tty (terminal)
    printf("%-8.8s ", utbufp->ut_line);

    // login time
    showTime(utbufp->ut_time);

#ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host);
#endif

    printf("\n");
}

/**
 * @brief Displays time in a format fit for human consumption
 *        uses ctime to build a string then picks parts out of it
 *        Note: %12.12s prints a string 12 chars wide and LIMITS
 *        it to 12chars only.
 * 
 * @param timeval 
 */
void showTime(long timeval)
{
    struct tm *info; 
    time(&timeval); 
    info = localtime(&timeval); 
    
    printf("%d-%d-%d %d:%d",1900+info->tm_year,1+info->tm_mon,info->tm_mday,info->tm_hour,info->tm_min); 
}