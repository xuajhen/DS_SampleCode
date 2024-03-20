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

int main()
{
    node_t *head = NULL;
    head = insertNodeHead(head, 5);
    head = insertNodeHead(head, 10);
    insertNodeHeadDPtr(&head, 15);
    insertNodeHeadDPtr(&head, 20); // head
    insertNodeTailDPtr(&head, 25); // tail
    // head = removeElements(head, 20); //
    // head = removeElements(head, 25); // tail
    head = removeElements(head, 15);       // middle
    head = removeElementsSimple(head, 20); //  head
    head = removeElementsSimple(head, 25); // tail
    // head = removeElementsSimple(head, 15); // middle
    Print_list(head);

    return 0;
}
