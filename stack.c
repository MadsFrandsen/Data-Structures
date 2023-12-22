/*
Stack implementation:

Use a typedef struct to represent the stack itself.
Should contain:
    An array representing the stack itself.
    An integer representing the index of the top
    An integer representing the capacity of the stack, i.e. the size

Following functions need to be created:
    Push - put new element on top of stack
    Pop - removes top element from stack
    Peek - read top element without pushing
    isEmpty - check if stack is empty
    isFull - check if stack is full
    initStack - initializes stack
    freeStack - free entire stack
    increaseStack - increases the size of the stack
    reduceStack - reduces teh size of the stack

*/

#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 10

typedef struct
{
    int *arr;
    int top;
    int capacity;
} Stack;

// Function to initialize a stack
void initStack(Stack *stack)
{
    stack->arr = (int *)malloc(INIT_CAPACITY * sizeof(int));
    if (stack->arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->capacity = INIT_CAPACITY;
}

// Function to check if stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to check if stack is full
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Function to increase the stack size
void increaseStack(Stack *stack)
{
    stack->arr = (int *)realloc(stack->arr, 2 * stack->capacity * sizeof(int));
    if (stack->arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = 2 * stack->capacity;
}

// Function to reduce the stack size
void reduceStack(Stack *stack)
{
    stack->arr = (int *)realloc(stack->arr, (stack->capacity / 2) * sizeof(int));
    if (stack->arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = stack->capacity / 2;
}

// Function to push new element on top of the stack
void pushStack(Stack *stack, int value)
{
    if (isFull(stack))
    {
        increaseStack(stack);
    }

    stack->arr[stack->top + 1] = value;
    stack->top++;
}

// Function to pop the top element
int popStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty");
        exit(EXIT_FAILURE);
    }
    int val = stack->arr[stack->top];
    stack->top--;

    if (stack->top <= (stack->capacity / 4) && stack->capacity != INIT_CAPACITY)
    {
        reduceStack(stack);
    }

    return val;
}

// Function to peek the top of the stack
int peekStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

// Function to free the stack
void freeStack(Stack *stack)
{
    free(stack->arr);
}


void printMenu() {
    printf("You can perform the following operations:\n");
    printf("\t1. Push an element to the stack.\n");
    printf("\t2. Pop an element from the stack.\n");
    printf("\t3. Peek the top of the stack.\n");
    printf("\t4. Quit.\n");
}

int main(int argc, char **argv)
{
    Stack myStack;

    initStack(&myStack);

    int operation = -1;
    int val;

    while (operation != 4) {
        printMenu();
        int num_received = scanf("%d", &operation);
        if (num_received == 1 && operation > 0 && operation <= 4) {
            switch(operation) {
                case 1:
                    // Push
                    printf("Please type an integer value you want to push.\n");
                    num_received = scanf("%d", &val);
                    if (num_received == 1) {
                        pushStack(&myStack, val);
                    } else {
                        printf("Invalid input. Please specify an integer.\n");
                        while (getchar() != '\n');
                    }
                    break;
                case 2:
                    // Pop
                    val = popStack(&myStack);
                    printf("Popped value %d from the stack\n", val);
                    break;
                case 3:
                    // Peek
                    val = peekStack(&myStack);
                    printf("Top of the stack: %d\n", val);
                    break;
                case 4:
                    // Quit
                    break;
            }
        } else {
            // Invalid input, clear the input buffer
            printf("Invalid input. Please enter a valid option.\n");
            while (getchar() != '\n');
        }
    }

    freeStack(&myStack);

    return 0;
}