#include <stdio.h>
#include <stdlib.h>
#include "createFile.h"
#include "copyFile.h"

int main(){
    int menu;
while(1){
    puts("Welcome to the file management system");
    scanf("%d",&menu);
    if (menu==1){
        createFile();
    }
    else if (menu==2){
        copyFile();
    }

    }
}