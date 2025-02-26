#include <stdio.h>
#define MAX 5 // Define maximum stack size

// Stack structure
typedef struct
{
    int arr[MAX]; // Stack array
    int top;      // Top index
} Stack;

// Function to initialize the stack
void initStack(Stack *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    s->arr[++(s->top)] = data;
    printf("%d pushed onto stack\n", data);
}

// Function to pop an element from the stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Function to get the top element of the stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function to display the stack
void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}

// Main function
int main()
{
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60); // Will cause overflow

    display(&s);

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    display(&s);

    printf("Top element: %d\n", peek(&s));

    return 0;
}
