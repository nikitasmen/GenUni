#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char a[10];
    struct node *next;
};

int menu();
void push(struct node **stack);
void pop(struct node **stack);
void empty(struct node **stack);
void stackTop(struct node *stack);

int main() {
    struct node *stack = NULL; // Initialize the stack pointer to NULL
    int i;

    do {
        i = menu();
        switch(i) {
            case 1:
                printf("Push operation:\n");
                push(&stack);
                break;
            case 2:
                printf("Pop operation:\n");
                pop(&stack);
                break;
            case 3:
                printf("Check if stack is empty:\n");
                empty(&stack);
                break;
            case 4:
                printf("Stack top element:\n");
                stackTop(stack);
                break;
            case 0:
                printf("Exit\n");
                empty(&stack); // Clean up the stack before exiting
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (i != 0);

    return 0;
}

// Display the menu
int menu() {
    int i;
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Check if stack is empty\n");
    printf("4. Display top element of stack\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &i);
    return i;
}

void push(struct node **stack) {
    struct node *newn ;
   
    printf("Enter value to push: ");
    scanf("%s", newn->a);
    newn->next = *stack;
    *stack = newn;
}

void pop(struct node **stack) {
   
    struct node *temp = *stack;
    *stack = (*stack)->next;
    printf("'%s' popped from stack.\n", temp->a);
    free(temp);
}

// Check if the stack is empty
void empty(struct node **stack) {
  
    struct node *temp;
    while (*stack != NULL) {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    
}

// Display the top element of the stack
void stackTop(struct node *stack) {
   
     printf("Top element is: %s\n", stack->a);
}