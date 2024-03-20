#include <stdio.h>
void function(int *a, int size, int b)
{
    int *aptr = a;
    while (*aptr < b * 100)
        aptr++;

    int i = 0;
    for (i = b * 100; i < (b + 1) * 100; i++)
    {
        if (*aptr == i)
            aptr++;
        else
            printf("%d ", i);
    };
}

int main()
{
    int a[20] = {1, 5, 9, 11, 46, 77, 80, 100, 111, 123,
                 222, 333, 366, 399, 411, 433, 455, 466, 477, 488};
    function(a, 500, 4);
}