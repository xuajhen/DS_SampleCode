#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}

void quicksort(int *arr, int front, int end)
{
    if (front < end)
    {
        int pivot = partition(arr, front, end);
        quicksort(arr, front, pivot - 1);
        quicksort(arr, pivot + 1, end);
    }
}

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