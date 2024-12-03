#define _CRT_SECURE_NO_WARNINGS  // Disable warnings for unsafe functions like scanf in MSVC
#include <stdio.h>              // Standard input/output library
#include <stdlib.h>             // Standard library for functions like exit
#include "createFile.h"         // Header file for the createFile function
#include "copyFile.h"           // Header file for the copyFile function
#include "deleteFile.h"         // Header file for the deleteFile function
#include "moveFile.h"           // Header file for the moveFile function
#include "renameFile.h"         // Header file for the renameFile function
#include "textFile.h"           // Header file for the textFiles functions
#include "getHelp.h"            // Header file for the getHelp functions

int main() {
    int menu;  // Variable to store the user's menu selection
    int c;     // Variable for clearing input buffer

    // Print welcome Message
    printf("\nWelcome to the file management system\n");

    // Infinite loop for continuously displaying the menu until the user exits
    while (1) {
        // Display the menu options to the user
        printf("Please enter what command you want to run\n");
        printf("1 - createFile\n");
        printf("2 - copyFile\n");
        printf("3 - deleteFile\n");
        printf("4 - moveFile\n");
        printf("5 - renameFile\n");
        printf("6 - to manipulate a text file\n");
        printf("7 - to get help on the above commands\n");
        printf("8 - to exit\n");

        // Read the user's menu selection
        scanf("%d", &menu);

        // Clear the input buffer to prevent issues with subsequent input
        c = "";  // Reset the variable
        while ((c = getchar()) != '\n' && c != EOF); // Consume all leftover characters in stdin

        // Print the user's menu selection for confirmation
        printf("You Picked: %d\n", menu);

        // Execute the appropriate function based on the user's menu selection
        if (menu == 1) {
            createFile();  // Call the createFile function
        }
        else if (menu == 2) {
            copyFile();    // Call the copyFile function
        }
        else if (menu == 3) {
            deleteFile();  // Call the deleteFile function
        }
        else if (menu == 4) {
            move();        // Call the move function
        }
        else if (menu == 5) {
            renameFile();  // Call the renameFile function
        }
        else if (menu == 6) {
            textFiles();   // Call the textFiles functions
        }
        else if (menu == 7) {
            getHelp();       // Call the getHelp function
        }
        else if (menu == 8) {
            exit(0);       // Exit the program
        }
        else {
            // Inform the user if they entered an invalid option
            printf("\nInvalid Input\n");
        }
    }
}
