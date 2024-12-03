#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a file with a user-provided name
void createFile() {
    char fileName[50]; // Array to store the name of the file

    // Prompt the user to enter the file name
    puts("What is the name of your file: ");
    scanf("%s", fileName); // Read the file name input from the user

    FILE* fptr; // File pointer to manage file operations

    // Attempt to open the file in "read" mode to check if it exists
    fptr = fopen(fileName, "r");
    if (fptr != NULL) { // If the file exists
        printf("File Already Exists. Exiting Back to main menu.\n");
        fclose(fptr); // Close the file before exiting
        return; // Exit the function
    }

    // Attempt to create a new file with "write" and "read" permissions ("w+")
    fptr = fopen(fileName, "w+");
    if (fptr == NULL) { // If the file creation fails
        printf("\nFile failed to create, exiting program.\n");
        exit(0); // Exit the program with an error
    } else { // If the file is created successfully
        printf("\nThe file is created successfully with name %s \n", fileName);
        fclose(fptr); // Close the file to ensure all data is saved and resources are released
        return; // Exit the function
    }

}

#endif
