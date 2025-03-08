#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int arr[MAX];
    int front, rear;
} Deque;

void initialize(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq)
{
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(Deque *dq)
{
    return dq->front == -1;
}

void insertFront(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = MAX - 1;
    }
    else
    {
        dq->front--;
    }
    dq->arr[dq->front] = value;
}

void insertRear(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
}

void deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted from front: %d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->front == MAX - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }
}

void deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deleted from rear: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = MAX - 1;
    }
    else
    {
        dq->rear--;
    }
}

void display(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    Deque dq;
    initialize(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 2);
    display(&dq);

    deleteFront(&dq);
    display(&dq);

    deleteRear(&dq);
    display(&dq);

    return 0;
}
