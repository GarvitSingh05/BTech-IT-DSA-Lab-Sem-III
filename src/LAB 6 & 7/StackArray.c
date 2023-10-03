#include<stdio.h>

#define SIZE 50

int Stack[SIZE];
int top = -1;

void push(int arr[], int val) {
   if(top == SIZE - 1){
        printf("Overflow Condition");
   }
   else {
    top++;
    arr[top] = val;
   }
}

int pop(int arr[]){
    if(top == -1){
        printf("Underflow condition");
    }
    else {
        int poppedVal = arr[top];
        top--;
        return poppedVal;
    }
}

void displayStack(int arr[], int size){
    printf("Stack : \n");
    for(int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}

int main() {
    push(Stack, 53);
    push(Stack, 82);
    push(Stack, 36);
    push(Stack, 78);
    push(Stack, 12);
    push(Stack, 45);
    push(Stack, 90);
    push(Stack, 66);
    push(Stack, 71);
    displayStack(Stack, 9);
    pop(Stack);
    pop(Stack);
    pop(Stack);
    printf("After Popping\n");
    displayStack(Stack, 6);
}