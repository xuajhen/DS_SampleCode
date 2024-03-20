#include <stdio.h>
#include <stdbool.h>

void swap(int *s1, int *s2)
{
    int temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void xor_swap(int *s1, int *s2)
{
    if (s1 == s2)
        return;
    *s1 = *s1 ^ *s2;
    *s2 = *s2 ^ *s1;
    *s1 = *s1 ^ *s2;
}

int partition(int *arr, int front, int end)
{
    int pivot = arr[end];
    int i = front - 1;
    for (int j = front; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            xor_swap(&arr[i], &arr[j]);
        }
    }
    // swap pivot pos
    i++;
    xor_swap(&arr[i], &arr[end]);

    return i;
}

void q_sort(int *arr, int front, int end)
{
    if (front < end)
    {
        int pivot_idx = partition(arr, front, end);
        q_sort(arr, front, pivot_idx - 1);
        q_sort(arr, pivot_idx + 1, end);
    }
}

int main()
{
    int length = 9;
    int a[9] = {9, 5, 3, 1, 2, 4, 6, 8, 7};
    q_sort(a, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}