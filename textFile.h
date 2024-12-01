#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendText(){
    char fileName[50];
    char addText[1025];
    FILE* fptr;
    printf("You have selected to Append Text\n");
    printf("Please type the name of your file: ");
    scanf("%s", fileName);

    fptr = fopen(fileName, "r");

    if (fptr){
        fclose(fptr);
        fptr = fopen(fileName, "a");
        puts("Please add up to 1024 characters to append, press enter to finish");
        scanf("%s", addText);
        fprintf(fptr, "%s", addText);
        fclose(fptr);
    }
    else{
        puts("File does not exist please create the file first");
    }
}

void insertText(){
    char fileName[50];
    char readchar[50];
    char insert[1024];
    int position;
    FILE* fptr;
    puts("You have selected to Insert Text");

    puts("Please type the name of your file");
    scanf("%s", fileName);

    printf("Please enter text you want ot insert: ");
    scanf("%s", insert);

    printf("Please enter where you want to insert: ");
    scanf("%d", &position);

    fptr = fopen(fileName, "r");

    if (fptr){
        FILE *temp = fopen("callmeIshmael.txt", "w+");
        FILE *temp2 = fopen("Warendures.txt", "w+");
        fgets(readchar, position, fptr);
        fprintf(temp, "%s", readchar);
        fclose(temp);

        while (fgets(readchar, 50, fptr)) {
            fprintf(temp2, "%s", readchar);
        }
        
        fclose(temp2);
        fclose(fptr);
        fptr = fopen(fileName, "w");

        fprintf(fptr, "%s", "");
        fclose(fptr);
        fptr = fopen(fileName, "a");
        
        temp2 = fopen("Warendures.txt", "r");
        temp = fopen("callmeIshmael.txt", "r");
        while (fgets(readchar, 50, temp)) {
            fprintf(fptr, "%s", readchar);
        }
        fprintf(fptr, "%s", insert);
        while (fgets(readchar, 50, temp2)) {
            fprintf(fptr, "%s", readchar);
        }

        fclose(fptr);
        fclose(temp);
        remove("callmeIshmael.txt");
        remove("Warendures.txt");
    
    }
    else{
        puts("File does not exist please create the file first");
    }

}

void removeText(){
    char fileName[50];
    FILE* fptr;
    puts("You have selected to Remove Text");

    puts("Please type the name of your file");
    scanf("%s", fileName);

    fptr = fopen(fileName, "r");

    if (fptr){
        fclose(fptr);
        fptr = fopen(fileName, "w");
        fprintf(fptr, "%s", "");
        fclose(fptr);
    }
    else{
        puts("File does not exist please create the file first");
    }
}

void showContent(){
    char fileName[50];
    int charsInLine = 256;
    char readChars[256];
    int pagecount=0;
    char cont;

    FILE* fptr;
    puts("You have selected to Show Content");

    puts("Please type the name of your file");
    scanf("%s", fileName);
    fptr = fopen(fileName, "r");

    if (fptr){
        while(fgets(readChars, charsInLine, fptr)){
            puts("---------------");
            printf("%s\n",readChars);
            
        }
    } else{
        puts("File does not exist please create the file first");
    }

}

void textFiles(){
    int option;

    puts("\nYou have selected text file management, please select one of the following actions:");
    puts("1. Append Text to File");
    puts("2. Insert Text in File");
    puts("3. Remove Text from File");
    puts("4. Show Content in File");
    puts("5. Exit to main menu");

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
        return;
    }
}

#endif