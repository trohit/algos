include <stdio.h>
#include <assert.h>
int heapsize = 0;
void swap(int *a, int *b)
{
        printf("\n%s: %u <> %u", __FUNCTION__, *a, *b);
        int t = *a;
        *a = *b;
        *b = t;
}
/*
 * Builds a heap of an element and its subtree.
 * Then works its way to get the max element to the top of the heap if needed.
 */
void heapify(int *a, int i, int heaplen)
{
        int max = i;
        int l = i*2 +1;
        int r = (i*2) + 2;
        printf("\n%s: i:%i elm:%u heaplen:%u", __FUNCTION__, i, a[i], heaplen);
        if (l <= heaplen && a[l] > a[i]) {
                max = l;
        } else {
                max = i;
        }
        if (r <= heaplen && a[r] > a[max]) {
                max = r;
        }
        if (i != max) {
                swap(&a[i], &a[max]);
                heapify(a, max, heaplen);
        }
}
/*
 * display helper function
 */
void disparr(int *a, int len)
{
        int i;
        //assert(len == 5);
        printf("\n%s:[", __FUNCTION__);
        for (i = 0; i < len; i++)
                printf("%u ", a[i]);
        printf("]");
}

/*
 * Called just once.
 * Starts from the n/2th element and decrements till the first is heapified.
 * Starts from the n/2th element as elements beyond that do not have any children.
 */
void buildheap(int *a, int arrlen)
{
        int i;
        heapsize = arrlen - 1;
        for (i = heapsize /2 ; i >= 0; i--) {
                printf("\n%s:i:%u", __FUNCTION__, i);
                heapify(a, i, heapsize);
        }
        disparr(a, arrlen);
}
/*
 * The sort procedure cherry picks the max element from the heap.
 * then it reduces the heap size, swaps the first element with the last element
 * and repeats this process till the first element is reached.
 */
void sort(int *a, int arrlen)
{
        int i = 0;
        buildheap(a, arrlen);
        for (i = arrlen - 2; i >= 0; i--) {
                printf("%s:cherrypick %u <>%u", __FUNCTION__,  a[heapsize], a[0]);
                swap(&a[heapsize], &a[0]);
                printf(":POSTcherrypick ");
                disparr(a, arrlen);
                heapsize--;
                heapify(a, 0, heapsize);
        }
        return;
}
int main()
{
        int i = 0;
        int tab [] = {70,50,10,90,15};
        unsigned int arrlen = sizeof(tab) / sizeof(tab[0]);
        printf("arrlen:%u\n", arrlen);
        disparr(tab, arrlen);
        sort(tab, arrlen);
        printf(" Sorted nos:");
        disparr(tab, arrlen);
        printf("\n");
        return 0;
}

