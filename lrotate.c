/*
 * Sample Input
 *
 * 5 4
 * 1 2 3 4 5
 * Sample Output
 *
 * 5 1 2 3 4
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void lrotate(int *a, int len)
{
    int t = a[0];
    for(int i = 0; i < len - 1; i++) {
        a[i] = a[i+1];
    }
    a[len - 1] = t;
}
void disp(int *a, int len)
{
    //printf("\n");
    for (int i = 0; i < len; i++)
        printf("%u ", a[i]);
}
int main() {
    //int a[] = {1,2,3,4,5};
    int rot = 0,len = 0;
    scanf("%u %u", &len, &rot);

    int *a = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        scanf("%u", &a[i]);
    }
    //disp(a, len);
    for (int i = 0; i < rot; i++) {
        lrotate(a, len);
        //disp(a, len);
    }
    disp(a, len);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
