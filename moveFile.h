#ifndef MOVEFILE_H
#define MOVEFILE_H
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void move() {
    char from[50];
    char to[50];

    printf("Enter the name of the file you want to move: ");
    scanf("%s", from);

    printf("Enter the name of the files destination: ");
    scanf("%s", to);
    
    rename(from, to);
}

#endif