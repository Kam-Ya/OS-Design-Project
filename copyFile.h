#ifndef COPYFILE_H
#define COPYFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyFile(){
    char fileName[50];
    char copyFile[50];
    char *temp;
    char *readChar;
    int charsInLine=256;
    FILE* fptr;
    FILE* fptrCopy;


    printf("Please type the name of file to be copied: ");
    scanf("%s", fileName);

    printf("Please enter name of destination file: ");
    scanf("%s", copyFile);

    printf("%s, %s", fileName, copyFile);


    fptr = fopen(fileName, "r");

    if (fptr != NULL){
        puts("Copying file");
        fptrCopy = fopen(copyFile, "w");
        while(fgets(readChar, charsInLine, fptr)){
            fprintf(fptrCopy,"%s",readChar);
        }
    }
    else{
        puts("File does not exist please create the file first");
    }
    fclose(fptr);
    fclose(fptrCopy); 
}

#endif