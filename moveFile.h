#ifndef MOVEFILE_H
#define MOVEFILE_H
#define MAX_FILENAME_LENGTH 50

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void move() {
    //Variables
    char from[MAX_FILENAME_LENGTH];
    char to[MAX_FILENAME_LENGTH];
    FILE* file;

    // Get file name from user
    printf("Enter the name of the file you want to move: ");
    scanf("%s", from);

    // Check if the old file exists
    file = fopen(from, "r");
    if (file == NULL) {
        printf("\nError: File '%s' does not exist.\n", from);
        return;
    }
    fclose(file);

    printf("Enter the name of the files destination: ");
    scanf("%s", to);
    
    rename(from, to); // Move the file
}

#endif