void merge_o(int *arr, int front, int middle, int end)
{
    int l_l = middle - front + 1;
    int l[l_l];
    int r_l = end - middle;
    int r[r_l];

    for (int i = 0; i < l_l; i++)
        l[i] = arr[front + i];
    for (int i = 0; i < r_l; i++)
        r[i] = arr[middle + 1 + i];
    int i = 0, j = 0;
    int idx = front;
    while (i < l_l && j < r_l)
    {
        if (l[i] < r[j])
        {
            arr[idx] = l[i];
            idx++;
            i++;
        }
        else
        {
            arr[idx] = r[j];
            idx++;
            j++;
        }
    }

    while (i < l_l)
    {
        arr[idx] = l[i];
        idx++;
        i++;
    }
    while (j < l_l)
    {
        arr[idx] = l[j];
        idx++;
        j++;
    }
}

void merge(int *arr, int front, int end)
{
    if (front < end)
    {
        int middle = (front + end) / 2;
        // int middle = (front^end) >> 1 + (front & end);
        merge(arr, front, middle);
        merge(arr, middle + 1, end);
        merge_o(arr, front, middle, end);
    }
}