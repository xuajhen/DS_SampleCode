
void swap(int *s1, int *s2)
{
    if (s1 == s2)
        return;
    *s1 ^= *s2;
    *s2 ^= *s1;
    *s1 ^= *s2;
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

void q_sort(int *arr, int front, int end)
{
    if (front < end)
    {
        int pivot = partition(arr, front, end);
        q_sort(arr, front, pivot - 1);
        q_sort(arr, pivot + 1, end);
    }
}