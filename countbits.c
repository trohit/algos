#include <stdio.h>
int countbits(int n)
{
        int i;
        int setbits = 0;
        for (i = 0; i < sizeof(int)*8; i++) {
                int mask = 1 << i;
                int res = n & ( 1<<i);
                if (res)
                        setbits++;
        }
        return setbits;
}

int main()
{
        int num;
        printf("Enter a num: ");
        scanf("%u", &num);
        printf("bits set: %u\n", countbits(num));
        return 0;
}
