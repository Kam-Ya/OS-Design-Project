#include <stdio.h>
#include <stdlib.h>
#include "createFile.h"
#include "copyFile.h"
#include "deleteFile.h"
#include "moveFile.h"
#include "renameFile.h"
#include "textFile.h"

int main(){
    int menu;
while(1){
    printf("Welcome to the file management system\nPlease enter what command you want to run.\n1 - createFile\n2 - copyFile\n3 - deleteFile\n4 - moveFile\n5- renameFile");
    scanf("%d",&menu);
    if (menu==1){
        createFile();
    }
    else if (menu==2){
        copyFile();
    } else if (menu == 3) {
        deleteFile();
    } else if (menu == 4) {
        move();
    } else if(menu == 5) {
        renameFile();
    }

    }
}