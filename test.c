#include <stdio.h>

char count_1bit(char n)
{
    n = (n & 0x55) + (n >> 1) & 0x55;
    n = (n & 0x33) + (n >> 2) & 0x33;
    n = (n & 0x0f) + (n >> 4) & 0x0f;
    return n;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    printf("%d \n", (ptr2 - ptr1));
    printf("%d \n", (char *)ptr2 - (char *)ptr1);
    printf("%d \n", count_1bit(5));
}