#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
void lrotate(int *a, unsigned int len, unsigned int n)
{
    unsigned int t = a[0];
    unsigned int sp = (n % len); // pos from where the transformed array begins from
    unsigned int i;
    unsigned int j;
    unsigned int newpos;
    unsigned int *tmparr = malloc(sizeof(int) * sp);
    for (i = 0; i < sp; i++) {
        tmparr[i] = a[i];
    }
    //printf("\nsp:%u\n", sp);
    for (i = sp, j = 0; i < len; i++) {
        //newpos = i % len;
        //printf("\n a[%u] = a[%u]", j, newpos);
        a[j++] = a[i];
    }
    //printf("\n assigning remaining elms");
    i = 0;
    while (j < len) {
        //printf("\n a[%u] = tmparr[%u]", j, i);
        a[j] = tmparr[i];
        j++;
        i++;
    }
}
void disp(int *a, unsigned int len)
{
    //printf("\n");
    for (unsigned int i = 0; i < len; i++)
        printf("%u ", a[i]);
}
int main() {
    //int a[] = {1,2,3,4,5};
    unsigned int rot = 0,len = 0;
    scanf("%u %u", &len, &rot);
    //len = 5;
    //rot = 4;

    int *a = malloc(sizeof(int) * len);
    for (unsigned int i = 0; i < len; i++) {
        scanf("%u", &a[i]);
        //a[i] = i+1;
    }
    disp(a, len);
    lrotate(a, len, rot);
    disp(a, len);
    return 0;
}
