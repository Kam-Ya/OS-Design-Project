#ifndef RENAMEFILE_H
#define RENAMEFILE_H
#define MAX_FILENAME_LENGTH 50


#include <stdio.h>
#include <stdlib.h>

void renameFile() {
    //Variables
    char oldName[MAX_FILENAME_LENGTH];
    char newName[MAX_FILENAME_LENGTH];
    FILE* file;

    // Gets name of old file
    printf("\nWhat is the old name of the file: ");
    scanf("%s", oldName);

    // Check if the old file exists
    file = fopen(oldName, "r");
    if (file == NULL) {
        printf("\nError: File '%s' does not exist.\n", oldName);
        return;
    }
    fclose(file);

    //gets new name of file
    printf("\nWhat is the new name of the file: ");
    scanf("%s", newName);


    // Check if the new file name is already taken
    file = fopen(newName, "r");
    if (file != NULL) {
        printf( "\nError: A file with the name '%s' already exists.\n", newName);
        fclose(file);
        return;
    }

    // Attempt to rename the file
    if (rename(oldName, newName) == 0) {
        printf("\nFile renamed successfully to '%s'.\n", newName);
    } else {
        printf("\nFailed to rename file. Please check permissions and try again.\n");
    }
}

#endif
