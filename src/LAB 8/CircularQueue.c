#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct CircularQueue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct CircularQueue* q) {
    return (q->front == NULL);
}

void enqueue(struct CircularQueue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } 
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->rear->next = q->front;
    printf("%d enqueued to the queue.\n", value);
}

int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int removedValue = q->front->data;
    struct Node* temp = q->front;
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } 
    else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }
    free(temp);
    return removedValue;
}
int main() {
    struct CircularQueue q;
    initializeQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    enqueue(&q, 40);
    enqueue(&q, 50);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    return 0;
}
