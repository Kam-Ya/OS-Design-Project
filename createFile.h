#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a file
void createFile() {
    char fileName[50];

    // Get file name from user
    puts("What is the name of your file: ");
    scanf("%s", fileName);

    FILE* fptr; // File pointer to manage file operations

    // Attempt to open the file to check if it exists
    fptr = fopen(fileName, "r");
    if (fptr != NULL) { // If the file exists
        printf("File Already Exists. Exiting Back to main menu.\n");
        fclose(fptr); // Close the file before exiting
        return; // Exit the function
    }

    // Attempt to create a new file
    fptr = fopen(fileName, "w+");
    if (fptr == NULL) { // If the file creation fails
        printf("\nFile failed to create, exiting program.\n");
        exit(0); // Exit the program with an error
    } else { // If the file is created
        printf("\nThe file is created successfully with name %s \n", fileName);
        fclose(fptr); // Close the file
        return; // Exit the function
    }

}

#endif
