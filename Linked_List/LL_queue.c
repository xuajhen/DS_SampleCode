#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int val;
    struct node_t *next;
    // struct node_t *pre;
} node_t;

typedef struct queue_t
{
    struct node_t *qlist;
    struct node_t *tail;
    // struct node_t *head;
} queue_t;

queue_t *initial_qlist()
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->qlist = (node_t *)malloc(sizeof(node_t));
    q->qlist->next = NULL;
    // q->head = NULL;
    q->tail = NULL;
    return q;
}

void push(queue_t *q, int val)
{
    // insert on tail
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->val = val;
    newNode->next = NULL;
    if (!q->tail) // q is empty
    {
        q->qlist->next = newNode;
        q->tail = newNode;
        // q->head = newNode;
    }
    else // q is non empty
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

void pop(queue_t *q)
{
    // pop from head
    if (q->qlist->next)
    {
        printf("pop %d \n", q->qlist->next->val);
        node_t *first = q->qlist->next;
        q->qlist->next = first->next;
        free(first);
    }
    else
    {
        printf("queue is empty.\n");
    }
}

int main()
{
    queue_t *q = initial_qlist();
    push(q, 1);
    push(q, 2);
    pop(q);
    pop(q);
    pop(q);
    return 0;
}
