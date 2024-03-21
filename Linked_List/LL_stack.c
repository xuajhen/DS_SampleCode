#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int val;
    struct node_t *next;
} node_t;

node_t *initial_qstack()
{
    node_t *s = (node_t *)malloc(sizeof(node_t));
    s->next = NULL;
    return s;
}

void push(node_t *s, int val)
{
    // insert on head
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->val = val;
    newNode->next = s->next;
    s->next = newNode;
}

void pop(node_t *s)
{
    // pop from head
    if (s->next)
    {
        printf("pop %d \n", s->next->val);
        node_t *first = s->next;
        s->next = first->next;
        free(first);
    }
    else
    {
        printf("stack is empty.\n");
    }
}

int main()
{
    node_t *s = initial_qstack();
    push(s, 1);
    push(s, 2);
    pop(s);
    pop(s);
    pop(s);
    return 0;
}
