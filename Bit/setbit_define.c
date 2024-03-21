#include <stdio.h>
#include <stdlib.h>
#define set(x, n) (x | (0x01 << n))
int main()
{
    unsigned int x = 0x7321;
    unsigned int n = 1;
    x = set(x, n);

    printf("%x \n", x);

    return 0;
}
