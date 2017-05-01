#include <stdio.h>

/*
 * Nice explanation of this at:
 * http://cs-fundamentals.com/tech-interview/c/c-program-to-check-little-and-big-endian-architecture.php
 */ 

typedef union _u {
        int i;
        char c[2];
} u;
int main()
{
        u uu;
        uu.i = 0x0102;
        if (uu.c[0] == 0x01) {
                printf("big endian");
        } else {
                printf("small endian");
        }
        return 0;
}
