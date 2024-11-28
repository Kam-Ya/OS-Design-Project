#ifndef MOVEFILE_H
#define MOVEFILE_H
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <copyFile.h>

void move() {
    char *from;
    char *to;

    printf("Enter the name of the file you want to move: ");
    scanf("%s", &from);

    printf("Enter the name of the files destination: ");
    scanf("%s", &to);

    copyFile(from, to);
}

#endif