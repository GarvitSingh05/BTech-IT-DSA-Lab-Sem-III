#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};
void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(struct Queue *q) {
    return (q->front == -1 && q->rear == -1);
}
int isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1 || q->rear == q->front - 1);
}
void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } 
    else {
        q->rear++;
    }
    q->queue[q->rear] = data;
    printf("%d enqueued to the queue.\n", data);
}
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int removedValue = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } 
    else {
        q->front++;
    }
    return removedValue;
}
int main() {
    struct Queue q;
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