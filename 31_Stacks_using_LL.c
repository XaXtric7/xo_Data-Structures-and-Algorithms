// Questions arised while coding this..
// 1. How do we know where ptr is pointing?
// Ans. (1). ptr is initially set to the top of the stack (or head of the linked list)
//              This is because when calling linkedListTraversal(top);, we pass the top pointer,
//              which stores the address of the first node.
//      (2). Iteration through the linked list
//              ptr->next stores the address of the next node in the list.
//              In each iteration, ptr moves to the next node (ptr = ptr->next).
//              The loop stops when ptr == NULL, meaning it has reached the end of the list.
// 2. Since linked lists are known for being dynamic and the stacks are pre defined how do we know whats the size of the linked list,
//    and when its gonna overflow ?
//      (1). Linked list size isn't predefined but can be tracked using a counter.
//      (2). Stack overflows when the heap runs out of memory, not when a max size is reached.
//      (3). Detect overflow using malloc() check in push().

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    linkedListTraversal(top);
    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(i));
    }
    return 0;
}
