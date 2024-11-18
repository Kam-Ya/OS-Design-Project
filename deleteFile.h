#ifndef DELETEFILE_H
#define DELETEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void deleteFile(){
    char fileName[50];

    printf("\nWhat is the name of the file to delete:");
    scanf("%s",fileName);

    // checking for success or which error occured
    if(remove(fileName)==0){
        printf("\n%s successfully removed");
    } else if (errno == ENOENT) {
        printf("\nFile does not exist");
    } else if (errno == EACCES) {
        printf("\nPermission to delete denied");
    } else if (errno == EPERM) {
        printf("\nOperation not permitted");
    } else {
        printf("\nUnknown error occured");
    }
}

#endif