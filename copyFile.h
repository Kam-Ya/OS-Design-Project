#ifndef COPYFILE_H
#define COPYFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyFile(){
    char fileName[50];
    char copyFile[58];
    char readChar[256];
    int charsInLine=256;
    FILE* fptr;
    FILE* fptrCopy;

    puts("Please type the name of your file");
    snprintf(copyFile, sizeof(copyFile), "Copy of %s", fileName);

    fptr = fopen(fileName, "r");

    if (fptr){
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