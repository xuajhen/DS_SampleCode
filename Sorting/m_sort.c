#include <stdio.h>
#include <stdbool.h>

void merge(int *arr, int front, int mid, int end)
{
    int l_l = mid - front + 1;
    int r_l = end - mid;
    int arr1[l_l];
    int arr2[r_l];
    for (int i = 0; i < l_l; i++)
        arr1[i] = arr[i + front];
    for (int i = 0; i < r_l; i++)
        arr2[i] = arr[i + mid + 1];

    int i = 0;
    int j = 0;
    int idx = front;
    while (i < l_l && j < r_l)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[idx] = arr1[i];
            i++;
        }
        else
        {
            arr[idx] = arr2[j];
            j++;
        }
        idx++;
    }

    while (i < l_l)
    {
        arr[idx] = arr1[i];
        i++;
        idx++;
    }
    while (j < r_l)
    {
        arr[idx] = arr2[j];
        j++;
        idx++;
    }
}

void m_sort(int *arr, int front, int end)
{
    if (front < end)
    {
        // int mid = (front + end) / 2;
        int mid = (front & end) + ((front ^ end) >> 1);
        m_sort(arr, front, mid);
        m_sort(arr, mid + 1, end);
        merge(arr, front, mid, end);
    }
}

int main()
{
    int length = 9;
    int a[9] = {9, 5, 3, 1, 2, 4, 6, 8, 7};
    m_sort(a, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
