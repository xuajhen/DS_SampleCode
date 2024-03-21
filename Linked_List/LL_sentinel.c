#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int val;
    struct node_t *next;
} node_t;

node_t *removeElementsSimple(node_t *node, int val)
{
    if (node == NULL) // if list is empty
    {
        return node;
    }
    // if list is non-empty
    node_t *cur = node;
    node_t *pre = NULL;
    while (cur->val != val)
    {
        pre = cur;
        cur = cur->next;
    }
    if (pre) // non head
    {
        pre->next = cur->next;
    }
    else // head
    {
        node = cur->next;
    }
    free(cur);
    cur = NULL;

    return node;
}

node_t *removeElements(node_t *node, int val)
{
    if (node == NULL) // if list is empty
    {
        return node;
    }
    // if list is non empty
    node_t **indir = &node;
    while ((*indir)->val != val)
    {
        indir = &(*indir)->next;
    }
    node_t *delNode = (*indir);
    (*indir) = (*indir)->next;
    free(delNode);

    return node;
}

node_t *insertNodeHead(node_t *node, int val)
{
    node_t *NewNode = (node_t *)malloc(sizeof(node_t));
    NewNode->val = val;
    NewNode->next = node;
    node = NewNode;
    return node;
}

void insertNodeHeadDPtr(node_t **node, int val)
{
    node_t *NewNode = (node_t *)malloc(sizeof(node_t));
    NewNode->val = val;
    NewNode->next = (*node);
    (*node) = NewNode;
}

node_t *insertNodeTail(node_t *node, int val)
{
    node_t *NewNode = (node_t *)malloc(sizeof(node_t));
    if (!node) // if the list is empty
    {
        NewNode->val = val;
        NewNode->next = node;
        node = NewNode;
    }
    else // if the list is non empty
    {
        node_t *cur = node;
        while (cur->next)
        {
            cur = cur->next;
        }
        NewNode->val = val;
        NewNode->next = NULL;
        cur->next = NewNode;
    }

    return node;
}

void insertNodeTailDPtr(node_t **node, int val)
{
    node_t *NewNode = (node_t *)malloc(sizeof(node_t));
    if (!(*node)) // if the list is empty
    {
        NewNode->val = val;
        NewNode->next = (*node);
        *node = NewNode;
    }
    else // if the list is non empty
    {
        node_t **cur = node;
        while ((*cur)->next)
        {
            cur = &(*cur)->next;
        }
        NewNode->val = val;
        NewNode->next = NULL;
        (*cur)->next = NewNode;
    }
}

node_t *insertNodeIndex(node_t *node, int val, int index)
{
    node_t *cur = node;
    node_t *pre = NULL;
    while (cur && index > 0)
    {
        pre = cur;
        cur = cur->next;
        index--;
    }

    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->val = val;
    if (!pre) // pre is null, insert to head;
    {
        newNode->next = cur;
        node = newNode;
    }
    else
    {
        pre->next = newNode;
        newNode->next = cur;
    }

    return node;
}

node_t *DeleteNodeIndex(node_t *node, int index)
{
    node_t *cur = node;
    node_t *pre = NULL;
    while (cur && index > 0)
    {
        pre = cur;
        cur = cur->next;
        index--;
    }

    // node_t *newNode = (node_t *)malloc(sizeof(node_t));
    // newNode->val = val;
    if (!pre) // pre is null, delete to head;
    {
        // newNode->next = cur;
        node = cur->next;
    }
    else
    {
        pre->next = cur->next;
    }
    // free(cur);
    return node;
}

void Print_list(node_t *head)
{
    node_t *currNode = head;
    while (currNode)
    {
        printf(" %d ->", currNode->val);
        currNode = currNode->next;
    }
    printf(" NULL \n");
}

int *getIndex(node_t *node, int index)
{
    node_t *cur = node;
    // MyLinkedList *pre = NULL;
    while (cur && index > 0)
    {
        // pre = cur;
        cur = cur->next;
        index--;
    }
    return cur->val;
}

int main()
{
    node_t *head = NULL;
    head = insertNodeHead(head, 7);
    Print_list(head);
    head = insertNodeHead(head, 2);
    Print_list(head);
    head = insertNodeHead(head, 1);
    Print_list(head);
    head = insertNodeIndex(head, 0, 3);
    Print_list(head);
    head = DeleteNodeIndex(head, 2);
    Print_list(head);
    head = insertNodeHead(head, 6);
    Print_list(head);
    head = insertNodeTail(head, 4);
    Print_list(head);
    printf("get = %d \n", getIndex(head, 4));
    // insertNodeHeadDPtr(&head, 20); // head
    // Print_list(head);
    // insertNodeTailDPtr(&head, 25); // tail
    // Print_list(head);
    //  head = removeElements(head, 20); //
    //  head = removeElements(head, 25); // tail
    // head = removeElements(head, 15); // middle
    // Print_list(head);
    // head = removeElementsSimple(head, 20); //  head
    // Print_list(head);
    // head = removeElementsSimple(head, 25); // tail
    // Print_list(head);
    //  head = removeElementsSimple(head, 15); // middle
    // head = DeleteNodeIndex(head, 3);
    // Print_list(head);

    return 0;
}
