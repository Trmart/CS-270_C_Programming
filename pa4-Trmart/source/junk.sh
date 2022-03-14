# Taylor Martin
# CS-270
# Nov 17 2021

#!/bin/bash

# Creates a junk directory as a hidden directory (.junk)
# within users home directory.

#  checks for errors and exits if an error is detected
#  set -e

directory_check() 
{
    [! -d $1] || return 0
    mkdir -p $1
}

if [$# -eq 0 ];
    #check to see if .junk directory exists
    then directory_check "${HOME}/.junk"
    #create the .junk directory
    touch "${HOME}/.junk"
elif [ "$1" = "-l"]; #if arg[1] flag is "-l"
    then echo "$(ls -l ~/.junk)" #perform "ls -l"
elif ["$1" = "-p"]; #if arg[1] flag is "-p"
    then $(rm -f ~/.junk/*) #empty the .junk directory
elif [-f $1]; 
    then for file in "$1";
            do mv "$file" "${HOME}/.junk" #move file to the .junk directory
        done
else
    echo "ERROR: INVALID ARGUMENT(S)."
fi