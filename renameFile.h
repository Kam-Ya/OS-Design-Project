#ifndef RENAMEFILE_H
#define RENAMEFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void renameFile(){
    char oldName[58];
    char newName[50];

    printf("\nWhat is the old name of the file: ");
    scanf("%s", oldName);

    printf("\nWhat is the new name of the file: ");
    scanf("%s", newName);

    if(rename(oldName,newName)==0){
        printf("\nFile renamed to %s",newName);
    }
    else{
        printf("\nFailed to rename file");
    }
    

}

#endif