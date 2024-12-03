#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getTextFileHelp.h"

void appendText(){
    // Variables
    char fileName[50];
    char addText[1025];
    FILE* fptr;

    printf("You have selected to Append Text\n");

    // Gets file name from user
    printf("Please type the name of your file: ");
    scanf("%s", fileName);

    // Opens file in read mode
    fptr = fopen(fileName, "r");

    // Checks file exists
    if (fptr){
        // closes file and reopens it in append mode
        fclose(fptr);
        fptr = fopen(fileName, "a");

        // Gets new text from user
        puts("Please add up to 1024 characters to append, press enter to finish");
        scanf("%s", addText);

        // appends it to the file and closes
        fprintf(fptr, "%s", addText);
        fclose(fptr);
    }
    else{
        // Warns user if file does not exist
        puts("File does not exist please create the file first");
    }
}

void insertText(){
    // Variables
    char fileName[50];
    char readchar[50];
    char insert[1024];
    int position;
    FILE* fptr;


    puts("You have selected to Insert Text");

    // Get file name
    puts("Please type the name of your file");
    scanf("%s", fileName);

    // Get new text
    printf("Please enter text you want ot insert: ");
    scanf("%s", insert);

    // Get insert location
    printf("Please enter where you want to insert: ");
    scanf("%d", &position);

    //Open file in read mode
    fptr = fopen(fileName, "r");

    if (fptr){
        // Open temporary files for handling the split and merge operations
        FILE *temp = fopen("callmeIshmael.txt", "w+");  // Temp file for content before the insertion point
        FILE *temp2 = fopen("Warendures.txt", "w+");    // Temp file for content after the insertion point

        // Read and write content up to the insertion point to `temp`
        fgets(readchar, position, fptr);
        fprintf(temp, "%s", readchar);
        fclose(temp);

        // Write the remaining content to `temp2`
        while (fgets(readchar, 50, fptr)) {
            fprintf(temp2, "%s", readchar);
        }
        fclose(temp2);
        fclose(fptr);

        // Clear the original file
        fptr = fopen(fileName, "w");
        fprintf(fptr, "%s", "");  // Overwrite file with an empty string
        fclose(fptr);

        // Reopen the file in append mode to merge content
        fptr = fopen(fileName, "a");
        temp2 = fopen("Warendures.txt", "r");
        temp = fopen("callmeIshmael.txt", "r");

        // Write content from `temp` (before insertion point) back to the file
        while (fgets(readchar, 50, temp)) {
            fprintf(fptr, "%s", readchar);
        }

        // Insert the new text
        fprintf(fptr, "%s", insert);

        // Write content from `temp2` (after insertion point) back to the file
        while (fgets(readchar, 50, temp2)) {
            fprintf(fptr, "%s", readchar);
        }

        // Close all files and clean up temporary files
        fclose(fptr);
        fclose(temp);
        fclose(temp2);
        remove("callmeIshmael.txt");
        remove("Warendures.txt");
    
    }
    else{
        // If file doesnt exist, notify user
        puts("File does not exist please create the file first");
    }

}

void removeText() {
    //Variables
    char fileName[50];
    FILE* fptr;

    puts("You have selected to Remove Text");

    // Get file name
    puts("Please type the name of your file");
    scanf("%s", fileName);

    // Attempt to open the file in read mode to check if it exists
    fptr = fopen(fileName, "r");

    if (fptr) { // If the file exists
        fclose(fptr); // Close the file opened in read mode

        // Reopen the file in write mode to clear its content
        fptr = fopen(fileName, "w");
        fprintf(fptr, "%s", ""); // Write an empty string to clear the file
        fclose(fptr); // Close the file after clearing content
    } else {
        // If the file doesn't exist, notify the user
        puts("File does not exist, please create the file first");
    }
}


// Method to show content of a file in pages
void showContent() {
    //variables
    char fileName[50];
    int linesPerPage;
    int startPage, endPage;
    int currentLine = 0, currentPage = 1;
    char readChars[256];
    int charsInLine = 256;

    FILE* fptr;

    puts("You have selected to Show Content");

    // Gets file to show the content of
    puts("Please type the name of your file:");
    scanf("%s", fileName);

    // Open file in read mode to check it exists
    fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("Error: File '%s' does not exist. Please create the file first.\n", fileName);
        return;
    }

    // Get lines per page
    printf("Enter the number of lines per page: ");
    if (scanf("%d", &linesPerPage) != 1 || linesPerPage <= 0) {
        printf("Error: Invalid input for lines per page.\n");
        fclose(fptr);
        return;
    }

    // Count total lines and pages
    int totalLines = 0;
    while (fgets(readChars, charsInLine, fptr)) {
        totalLines++;
    }
    rewind(fptr);

    // Calculates total number of pages, adding "+ linesPerPage - 1" to make sure the final value rounds up and doesnt cut off any content
    int totalPages = (totalLines + linesPerPage - 1) / linesPerPage;
    printf("The file has %d lines, which equals %d pages with %d lines per page.\n", totalLines, totalPages, linesPerPage);

    // Get page range to display
    printf("Enter the start and end page numbers to display (e.g., 2 3): ");
    if (scanf("%d %d", &startPage, &endPage) != 2 || startPage < 1 || endPage < startPage || endPage > totalPages) {
        printf("Error: Invalid page range.\n");
        fclose(fptr);
        return;
    }

    // Display selected pages
    printf("Displaying pages %d to %d:\n", startPage, endPage);
    currentLine = 0;
    currentPage = 1;

    while (fgets(readChars, charsInLine, fptr)) {  // Read a line of text from the file into `readChars`

        // Check if the current page is within the specified range (startPage to endPage)
        if (currentPage >= startPage && currentPage <= endPage) {
            // Print the page header when a new page starts (only on the first line of the page)
            if (currentLine == 0) {
                printf("----------(%d)----------\n", currentPage);  // Display the current page number
            }

            // Print the current line of text
            printf("%s", readChars);
        }

        currentLine++;  // Increment the current line counter

        // Check if the maximum number of lines per page has been reached
        if (currentLine == linesPerPage) {
            currentLine = 0;  // Reset the line counter for the new page
            currentPage++;    // Move to the next page

            // If the current page exceeds the endPage, stop processing
            if (currentPage > endPage) {
                break;  // Exit the loop if we've reached the end page
            }
        }
    }



    fclose(fptr);
    printf("\n----------(End)----------\n");
}


void textFiles(){
    // Variable for users choice
    int option;

    // Displays menu
    puts("\nYou have selected text file management, please select one of the following actions:");
    puts("1. Append Text to File");
    puts("2. Insert Text in File");
    puts("3. Remove Text from File");
    puts("4. Show Content in File");
    puts("5. Get help for text file operations");
    puts("6. Exit to main menu");

    // Scan in input
    scanf("%d", &option);

    if (option == 1) {
        appendText();
    } else if (option == 2) {
        insertText();
    } else if (option == 3) {
        removeText();
    } else if (option == 4) {
        showContent();
    } else if (option == 5) {
        getTextFileHelp();
    } else if (option == 6) {
        return;
    }
}

#endif