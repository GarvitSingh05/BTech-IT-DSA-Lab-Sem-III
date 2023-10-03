#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
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

// Function to insert a node at the start of the circular linked list
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
    }
}

// Function to insert a node after a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position! Position should be non-negative.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        if (position == 0) {
            newNode->next = newNode;
            *head = newNode;
        } else {
            printf("Invalid position! Position exceeds the list length.\n");
        }
    } else if (position == 0) {
        newNode->next = *head;
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp2 = *head;
        int ptr = 0;
        while (ptr < position - 1 && temp2->next != *head) {
            temp2 = temp2->next;
            ptr++;
        }
        if (ptr != position - 1) {
            printf("Invalid position! Position exceeds the list length.\n");
        } else {
            newNode->next = temp2->next;
            temp2->next = newNode;
        }
    }
}

// Function to delete the first node in the circular linked list
void deleteAtStart(struct Node** head) {
    if (*head == NULL) {
        printf("Circular linked list is empty. Nothing to delete!\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == *head) {
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        *head = (*head)->next;
        temp->next = *head;
    }
    free(temp);
}

// Function to delete the temp node in the circular linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Circular linked list is empty. Nothing to delete!\n");
        return;
    }

    if ((*head)->next == *head) {
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
    
   
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("Circular linked list is empty. Nothing to delete!\n");
        return;
    }
    if (position == 0) {
        deleteAtStart(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    int ptr = 0;
    while (ptr < position && temp->next != *head) {
        prev = temp;
        temp = temp->next;
        ptr++;
    }
    if (ptr != position) {
        printf("Invalid position! Position exceeds the list length.\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtStart(&head, 5);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 2);

    printf("Circular Linked List after insertions:\n");
    displayList(head);

    deleteAtStart(&head);
    deleteAtEnd(&head);
    deleteAtPosition(&head, 1);

    printf("Circular Linked List after deletions:\n");
    displayList(head);

    return 0;
}
