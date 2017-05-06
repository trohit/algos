/*
 * Simple program to merge 2 arrays
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* 
 * memory allocated in this function.
 * needs to be freed by caller
 */
int* merge(int arra[], int arrb[], int alen, int blen)
{
        int *arrc = malloc (sizeof(int) * (alen + blen));
        int clen = alen + blen;
        int a = 0;
        int b = 0;
        int c = 0;
        while (a < alen && b < blen) {
                if (arra[a] < arrb[b]) {
                        arrc[c++] = arra[a++];
                } else {
                        arrc[c++] = arrb[b++];
                }
        }
        assert((a == alen) || (b == blen));
        while (a < alen) {
                arrc[c++] = arra[a++];
        }
        while (b < blen) {
                arrc[c++] = arrb[b++];
        }
        return arrc;
}
void disparr(const char *title, int *arr, int len)
{
        int i = 0;
        printf("\n%s", title);
        for (i = 0; i < len; i++) {
                printf("[%u]", arr[i]);
        }
}
int main()
{
        int arra[] = {10,20,30,40,100};
        int arrb[] = {5,15,20,25,90};

        int alen = sizeof(arra) / sizeof(arra[0]);
        int blen = sizeof(arrb) / sizeof(arrb[1]);

        int *c = merge(arra, arrb, alen, blen);
        disparr("arr a", arra, alen);
        disparr("arr b", arrb, blen);
        disparr("arr c", c, alen + blen);
        free(c);
        return 0;
}
