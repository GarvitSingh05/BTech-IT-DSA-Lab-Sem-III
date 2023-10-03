#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the start of the singly linked list
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the singly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position! Position should be non-negative.\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    if (position == 0) {
        insertAtStart(head, data);
        return;
    }
    
    struct Node* temp = *head;
    int ptr = 0;
    
    while (ptr < position - 1 && temp != NULL) {
        temp = temp->next;
        ptr++;
    }
    
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

// Function to delete the first node in the singly linked list
void deleteAtStart(struct Node** head) {
    if (*head == NULL) {
        printf("Singly linked list is empty. Nothing to delete!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node in the singly linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Singly linked list is empty. Nothing to delete!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Singly linked list is empty. Nothing to delete!\n");
        return;
    }
    if (position == 0) {
        deleteAtStart(head);
        return;
    }
    struct Node* temp = *head;
    int ptr = 0;
    while (ptr < position - 1 && temp->next != NULL) {
        temp = temp->next;
        ptr++;
    }
    if (ptr != position - 1 || temp->next == NULL) {
        printf("Invalid position! Position exceeds the list length.\n");
        return;
    }
    struct Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

// Function to display the singly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    //Creating List by Insertions
    insertAtEnd(&head, 10);
    insertAtStart(&head, 5);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 2);
    insertAtPosition(&head, 45, 3);
    insertAtStart(&head, 90);

    printf("Singly Linked List after insertions:\n");
    displayList(head);
    
    //Deleting certain elements
    deleteAtPosition(&head, 1);
    deleteAtPosition(&head, 3);

    printf("Singly Linked List after deletions:\n");
    displayList(head);

    return 0;
}
