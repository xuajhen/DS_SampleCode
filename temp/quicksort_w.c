#include <stdio.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 9;
    int arr[] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}