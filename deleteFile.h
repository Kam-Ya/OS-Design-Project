#ifndef DELETEFILE_H
#define DELETEFILE_H
#define MAX_FILENAME_LENGTH 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void deleteFile(){
    char fileName[MAX_FILENAME_LENGTH];

    // Get file name from user
    printf("\nWhat is the name of the file to delete: ");
    scanf("%s", fileName);

    // checking for success or which error occurred
    if(remove(fileName)==0){ // remove() returns 0 on success
        printf("\n%s successfully removed\n", fileName);
    } else if (errno == ENOENT) { // ENOENT is the error code for file not found
        printf("\nFile does not exist");
    } else if (errno == EACCES) { // EACCES is the error code for permission denied ei. read-only file or directory
        printf("\nPermission to delete denied");
    } else if (errno == EPERM) { // EPERM is the error code for operation not permitted ei. file is a directory
        printf("\nOperation not permitted");
    } else {
        printf("\nUnknown error occurred");
    }
}

#endif