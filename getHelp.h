#ifndef GETHELP_H
#define GETHELP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getHelp(){
    int help;  // Variable to store the user's menu selection
    int c;     // Variable for clearing input buffer


    // Infinite loop for continuously displaying the menu until the user exits
    while (1) {
        // Display the menu options to the user
        printf("\nWhich Command would you like help with?\n");
        printf("1 - createFile\n");
        printf("2 - copyFile\n");
        printf("3 - deleteFile\n");
        printf("4 - moveFile\n");
        printf("5 - renameFile\n");
        printf("6 - to exit\n");

        // Get menu choice
        scanf("%d", &help);

        // Clear the input buffer to prevent issues with subsequent input
        c = 0;  // Reset the variable
        while ((c = getchar()) != '\n' && c != EOF); // Consume all leftover characters in stdin

        // Print the user's menu selection for confirmation
        printf("You Picked: %d\n", help);

        // Execute the appropriate function based on the user's menu selection
        if (help == 1) {
           printf("createFile: Creates a new file with the given name if it does not exist");
        }
        else if (help == 2) {
            printf("copyFile: Copy all contents of a file to a different file");
        }
        else if (help == 3) {
            printf("deleteFile: Permanently remove a file");
        }
        else if (help == 4) {
            printf("moveFile: Moves a file from it original folder to another specified folder");
        }
        else if (help == 5) {
            printf("renameFile: changes a files name to a new specified one");
        }
        else if (help == 6) {
            return;       // Return to Main Menu
        }
        else {
            // Inform the user if they entered an invalid option
            printf("\nInvalid Input\n");
        }
    }

}

#endif