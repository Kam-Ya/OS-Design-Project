#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteFile(){
    char fileName[50];

    printf("\nWhat is the name of the file to delete:");
    scanf("%s",fileName);

    if(remove(fileName)==0){
        printf("\n%s successfully removed");
    }
    else{
        printf("\nOperation failed");
    }
}