#ifndef COPYFILE_H
#define COPYFILE_H
#define MAX_FILENAME_LENGTH 50
#define MAX_READ_LENGTH 256

#include <stdio.h>
#include <stdlib.h>

void copyFile() {
    // Variables
    char fileName[MAX_FILENAME_LENGTH];
    char copyFile[MAX_FILENAME_LENGTH];
    char readChar[MAX_READ_LENGTH]; // Allocate space for reading lines
    FILE* fptr = NULL;
    FILE* fptrCopy = NULL;

    printf("Please type the name of the file to be copied: ");
    scanf("%s", fileName);

    // Try opening the source file
    fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("Error: Source file '%s' does not exist\n", fileName);
        return;
    }

    printf("Please enter the name of the destination file: ");
    scanf("%s", copyFile);


    // Try opening the destination file
    fptrCopy = fopen(copyFile, "w");
    if (fptrCopy == NULL) {
        printf("Error: Unable to create or open destination file '%s'.\n", copyFile);
        fclose(fptr); // Close the source file before exiting
        return;
    }

    // Copy content from source to destination
    printf("Copying content from '%s' to '%s'.\n", fileName, copyFile);
    while (fgets(readChar, sizeof(readChar), fptr)) {
        fputs(readChar, fptrCopy);
    }

    // Close the files
    fclose(fptr);
    fclose(fptrCopy);

    printf("File copy operation completed successfully.\n");
}

#endif
