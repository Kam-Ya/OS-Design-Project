#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void textFiles(){
    puts("You have selected text file management, please select one of the following actions:");
    puts("1. Append Text to File");
    puts("2. Insert Text in File");
    puts("3. Remove Text from File");
    puts("4. Show Content in File");
    puts("5. Exit to main menu");
}

void appendText(){
    char fileName[50];
    char addText[1024];
    FILE* fptr;
    puts("You have selected to Append Text");
    puts("Please type the name of your file");
    scanf("%s",fileName);

    fptr = fopen(fileName, "r");

    if (fptr){
        fclose(fptr);
        fptr = fopen(fileName, "a");
        puts("Please add up to 1024 characters to append, press enter to finish");
        scanf("%s",addText);
        fprintf(fptr, addText);
    }
    else{
        puts("File does not exist please create the file first");
    }
}

void insertText(){
    char fileName[50];
    char insert[1024];
    int position;
    FILE* fptr;
    puts("You have selected to Insert Text");

    puts("Please type the name of your file");
    scanf("%s",fileName);

    fptr = fopen(fileName, "r");

    if (fptr){
        fclose(fptr);
        fptr = fopen(fileName, "");
        
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
    scanf("%s",fileName);

    fptr = fopen(fileName, "r");

    if (fptr){
        fclose(fptr);
        fptr = fopen(fileName, "");
        
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
    scanf("%s",fileName);

    fptr = fopen(fileName, "r");

    if (fptr){
    while(fgets(readChars, charsInLine, fptr)){
        printf("Reading Page %d\n",pagecount);
        puts("---------------");
        for (int i=0;i<=20;i++){
        if(fgets(readChars, charsInLine, fptr)){
        fgets(readChars, charsInLine, fptr);
        printf("%s\n",readChars);
       
        }
        else{
            puts("End of File");
        }
        
    }
     puts("-------------");
        puts("Continue? (Y/N)");
        scanf("%c",cont);
        if(cont=='Y'){}
        else{break;}
    }
    }
    else{
        puts("File does not exist please create the file first");
    }

}