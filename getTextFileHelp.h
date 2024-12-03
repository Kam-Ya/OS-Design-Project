#ifndef GETTEXTFILEHELP_H
#define GETTEXTFILEHELP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getTextFileHelp(){
    int help;  // Variable to store the user's menu selection
    int c;     // Variable for clearing input buffer


    // Infinite loop for continuously displaying the menu until the user exits
    while (1) {
        // Display the menu options to the user
        printf("\nWhich Command would you like help with?\n");
        puts("1. Append Text to File");
        puts("2. Insert Text in File");
        puts("3. Remove Text from File");
        puts("4. Show Content in File");
        puts("5. Exit to main menu");

        // Read the user's menu selection
        scanf("%d", &help);

        // Clear the input buffer to prevent issues with subsequent input
        c = NULL;  // Reset the variable
        while ((c = getchar()) != '\n' && c != EOF); // Consume all leftover characters in stdin

        // Print the user's menu selection for confirmation
        printf("You Picked: %d\n", help);

        // Execute the appropriate function based on the user's menu selection
        if (help == 1) {
            printf("Append Text: Add text to the end of the file");
        }
        else if (help == 2) {
            printf("Insert Text: Inserts text to a specified location within the file");
        }
        else if (help == 3) {
            printf("Remove Text: Overwrites the text file until it is empty");
        }
        else if (help == 4) {
            printf("Show Content: Displays the text content of a file in numbered pages ");
        }
        else if (help == 5) {
            return;       // Return to Main Menu
        }
        else {
            // Inform the user if they entered an invalid option
            printf("\nInvalid Input\n");
        }
    }

}

#endif GETTEXTFILEHELP_H
