#ifndef MOVEFILE_H
#define MOVEFILE_H
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void move(char *file, char *dest) {
    if (rename(file, dest)) {
        return;
    } else {
        printf("Error: %d\n", errno);
    }
}

#endif