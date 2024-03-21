#include <stdio.h>

int ispow2(unsigned int *x)
{
    return (*x != 0) && ((*x & (*x - 1)) == 0);
}

int main()
{
    int a = 30;
    if (ispow2(&a))
        printf("ispower2\n");
    else
        printf("NOT power2\n");

    return 0;
}