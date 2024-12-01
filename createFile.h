#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile(){
char fileName[50];

    
    puts("What is the name of your file: ");
    scanf("%s", fileName);
    // file pointer
    FILE* fptr;


    // creating file using fopen() access mode "w"
    fptr = fopen(fileName, "w+");

    // checking if the file is created
    if (fptr == NULL) {
        printf("\nFile failed to create, exiting program");
        exit(0);
    }
    else {
        printf("\nThe file is created successfully with name %s \n",fileName);
        fclose(fptr);
    }
    scanf("%s", fileName);
}

#endif