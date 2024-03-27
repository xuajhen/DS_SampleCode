#include <stdio.h>
#include <stdlib.h>
/*
    heap is a complete binary tree
    for example, we can use the array to implement max heap using index
    parent index * 2 + 1 = left child
    parent index * 2 + 2 = right child
    (child index - 1) / 2 = parent index


*/
typedef struct heap_t
{
    int *arr;
    int size;
    int capacity;
} heap;

/*  Heapify : is the main function in buliding a heap.
    1. We first store the index of a node with the maximum value between the current node,
       left child, and right child in variable max.
    2. After that, we check whether the index of a left and right child is within the range
       that is less than equal to the size of the heap and greater than equal to zero.
    3. If the min and index are not equal, we swap their value and call maxHeapify() to maintain
       the max heap.
    4. otherwise, we return.

*/
void maxHeapify(heap *h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int max = index;

    // checking whether our left or child element
    // is at right index of not to avoid index error
    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;

    // store left or right element in max if any of these is smaller that its parent
    if (left != -1 && h->arr[left] > h->arr[max])
        max = left;
    if (right != -1 && h->arr[right] > h->arr[max])
        max = right;

    // swapping the nodes
    if (max != index)
    {
        int temp = h->arr[max];
        h->arr[max] = h->arr[index];
        h->arr[index] = temp;
        // recursively calling for their child elements to maintain max heap
        maxHeapify(h, max);
    }
}

heap *createHeap(int capacity, int *nums)
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = capacity;
    h->arr = (int *)malloc(sizeof(int) * capacity);

    int i;
    for (i = 0; i < capacity; i++)
    {
        h->arr[i] = nums[i];
    }
    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0)
    {
        maxHeapify(h, i);
        i--;
    }
    return h;
}

int extractMax(heap *h)
{
    int deleteItem;
    // checking if the heap is empty or not
    if (h->size == 0)
    {
        printf("\n Heap id empty.");
    }

    // store the node in deleteItem that is to be deleted.
    deleteItem = h->arr[0];
    // Replace the deleted node with the last node
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    // call maxheapify top down for 0th index to maintain the heap property.
    maxHeapify(h, 0);
    return deleteItem;
}

// defining maxHeapify bottom up function
void insertHelper(heap *h, int index)
{
    // store parent of element at index
    int parent = (index - 1) / 2;

    if (h->arr[parent] < h->arr[index])
    {
        // swapping when child is smaller than parent element
        int temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;

        // recursively calling
        insertHelper(h, parent);
    }
}

void insert(heap *h, int data)
{
    // checking if heap is full or not
    if (h->size < h->capacity)
    {
        // Inserting data into an array
        h->arr[h->size] = data;
        // calling maxheapify bottom up function
        insertHelper(h, h->size);
        // Incrementing size of array
        h->size++;
    }
}

void printHeap(heap *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    heap *hp = createHeap(9, arr);
    printHeap(hp);
    extractMax(hp);
    printHeap(hp);
}