#Macros 
CC = gcc
CFLAGS = 

#Dependency Rules For Non-File Targets
all: who3
clobber: clean 
		rm -f *~ \#*\#
clean:
		rm -f who *.o

#Dependency Rules For File Targets
who3: who3.o utmplib.o
		$(CC) $(CFLAGS) who3.o utmplib.o -o who3
who3.o: who3.c utmplib.h
		$(CC) $(CFLAGS) -c who3.c
utmplib.o: utmplib.c utmplib.h
		$(CC) $(CFLAGS) -c utmplib.c
