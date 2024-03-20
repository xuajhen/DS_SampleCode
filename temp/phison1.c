#include <stdio.h>

void function(int *a, int size)
{
    int *aptr = a;
    int i;
    for (i = 0; i <= 500; i++)
    {
        if (*aptr == i)
            aptr++;
        else
            printf("%d ", i);
    }
}

int main()
{
    int a[20] = {1, 5, 9, 11, 46, 77, 80, 100, 111, 123,
                 222, 333, 366, 399, 411, 433, 455, 466, 477, 488};
    function(a, 500);
}