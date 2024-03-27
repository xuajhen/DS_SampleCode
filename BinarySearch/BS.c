#include <stdio.h>
#include <stdlib.h>

void binarySearch(int *arr, int target)
{
    int right = sizeof(arr);
    int left = 0;
    while (left <= right)
    {
        // int middle = (left + right) / 2;
        int middle = ((left ^ right) >> 1) + (left & right);

        if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else if (arr[middle] > target)
        {
            right = middle - 1;
        }
        else if (arr[middle] == target)
        {
            printf("find target at index %d \n", middle);
            break;
        }
    }
    printf("NOT FOUND.\n");
}

int main()
{
    int arr[9] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int target = 8;
    binarySearch(arr, target);

    return 0;
}