#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
struct Node *deleteAtIndex(struct Node *head, int index)
{
    if (index == 0)
        return deleteFirst(head); // Handle index 0 case

    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1 && q != NULL; i++)
    {
        p = p->next;
        q = q->next;
    }

    if (q == NULL)
        return head; // If index is out of bounds

    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
struct Node *deleteAtLast(struct Node *head)
{
    if (head == NULL || head->next == NULL) // Handle empty or single node case
    {
        free(head);
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

// Case 4: Deleting the element with a given value from the linked list
struct Node *deleteByValue(struct Node *head, int value)
{
    if (head == NULL)
        return head;

    // If the head itself holds the value to be deleted
    if (head->data == value)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    while (q != NULL && q->data != value)
    {
        p = p->next;
        q = q->next;
    }

    if (q != NULL) // If value is found
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion:\n");
    linkedListTraversal(head);

    // head = deleteFirst(head);  // Delete first element
    // head = deleteAtIndex(head, 2); // Delete at index 2
    // head = deleteByValue(head, 3); // Delete node with value 3
    head = deleteAtLast(head); // Delete last element

    printf("Linked list after deletion:\n");
    linkedListTraversal(head);

    return 0;
}
