/**
 * @file utmplib.c
 * @author Taylor Martin
 * @brief Definition file for utmp buffering.
 * @version 0.1
 * @date 10/23/2021
 * 
 */
#include "utmplib.h"

#define NRECS 3                    // number of utmp records to buffer

/* IMPORTANT NOTE:
 * static global variables - is a global variable that
 * can only be accessed by functions in the SAME C program file
 */
static struct utmp utmpbuf[NRECS]; // buffer/storage
static int numRecs = 0;            // number of records stored
static int curRec = 0;             // current record
static int fdUtmp = -1;            // read utmp file descriptor

/**
 * @brief Opens the filename for reading and returns
 *        the file desriptor.
 * 
 * @param filename  name of file to open
 * @return int      file descriptor
 */
int utmpOpen(char *filename)
{
    // STEP 1: Open filename for reading
    // NOTE: Use the global static variable fdUtmp here
    fdUtmp = open(&filename,O_RDONLY); 
    // STEP 2: Return the file descriptor fdUtmp
    return fdUtmp; 
}

/**
 * @brief WRIT
 * 
 * @return struct utmp* 
 */
struct utmp* utmpNext()
{
    // STEP 1: Check if the current records is equal to 
    // number of records in the buffer and there is
    // no left to reload from the utmp file to the buffer
    // return NULL.
    if(curRec == numRecs && utmpReload() == 0) 
    {
        return NULL; 
    }

    struct utmp *recp;
    // STEP 2: Assign recp to the current record (curRec) in the buffer     
    // recp = ...;
    recp = &utmpbuf[curRec]; 
    // STEP 3: Increment current record (curRec)
    curRec++; 
    // STEP 4: Return recp, the next record in the buffer
    return recp; 
}

/**
 * @brief Reads n number of utmp records (NRECS) 
 *        from the utmp file (fdUtmp) into a buffer (utmpbuf).
 *        Compute the number of utmp records that 
 *        was actually read and return that value.
 * 
 * @return int  number of utmp records in the buffer
 */
int utmpReload()
{
    int amtRead;

    // STEP 1: Read NRECS of utmp records from 
    // utmp file (fdUtmp) into buffer (utmpbuf) 
    // amtRead = read(...);
    amtRead = read(fdUtmp,utmpbuf,NRECS * sizeof (struct utmp)); 
    // STEP 2: Compute the number of records (numRecs) read
    // numRecs = ...;
    numRecs = amtRead; 
    // STEP 3: Reset currect Record (curRec) to zero
    curRec = 0; 
    // STEP 4: Return number of records (numRecs)
    return numRecs; 
}

/**
 * @brief Closes the static global variable fdUtmp which used
 *        as a file descriptor for utmp file.
 * 
 */
void utmpClose()
{
    // STEP 1: Only close fdUtmp if it is open
    if(fdUtmp==1)
    {
        close(fdUtmp); 
    }
    return; 
}