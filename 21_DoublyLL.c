#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node
void deleteNode(Node **head, int key)
{
    if (*head == NULL)
        return;
    Node *temp = *head;

    // Find the node to delete
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
        return; // Key not found

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next; // Deleting the first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Display the list
void display(Node *head)
{
    Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    display(head);

    deleteNode(&head, 20);
    display(head);

    return 0;
}
