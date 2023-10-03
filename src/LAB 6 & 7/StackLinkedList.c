#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};

void initialise(struct Stack* stack) {
    stack->top == NULL;
}

void push(struct Stack* stack, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Overflow Condition. Cannot add elements to the stack");
        return;
    }
    newNode->data = val;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if(stack->top == NULL) {
        printf("Underflow Condition. Cannot remove elements from the stack");
        return 0;
    }
    struct Node* temp = stack->top;
    int poppedVal = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedVal;
}

void displayStack(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* ptr = stack->top;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialise(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);
    printf("Initial Stack : \n");
    displayStack(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    printf("Stack after popping : \n");
    displayStack(&stack);
}