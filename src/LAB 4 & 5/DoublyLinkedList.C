#include<stdio.h>
#include<stdlib.h>

struct Node { 
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode -> next = *head;
        (*head) -> prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp; 
        
    }
}

void insertAtPosition(struct Node** head, int data, int position){ 
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    } else if(position == 0) {
        newNode -> next = *head;
        (*head) -> prev = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        int ptr = 0;
        while(ptr < position - 1 && temp -> next != NULL) {
            temp = temp -> next;
            ptr++;
        }

        if(ptr != position - 1){
            printf("Inavlid Position");
        } else {
            newNode -> next = temp -> next;
            newNode -> prev = temp;
            if(temp -> next != NULL) {
                temp -> next -> prev = newNode;
            }
            temp -> next = newNode;
        }
    }
}

void deleteAtStart(struct Node** head) { 
    if(*head == NULL){
        printf("List is empty. Nothing to delete");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head) -> next;
    if(*head != NULL){
        (*head) -> prev = NULL;
    }
    free(temp);
}

void deleteAtEnd(struct Node** head){
    if(*head == NULL){
        printf("List is empty. Nothing to delete");
        return;
    }

    struct Node* temp = *head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    if(temp -> prev != NULL) {
        temp -> prev -> next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    
    while(temp != NULL) {
        printf("%d", temp -> data);
        temp = temp -> next;
        printf("\n");
    }
    printf("\n");
}

void deleteAtPosition (struct Node** head, int position) {
    if(*head == NULL){
        printf("List is empty. Nothing to delete");
        return;
    }
    if(position < 0){
        printf("Invalid Position. It should be non-negative");
        return;
    }
    if(position == 0){
        deleteAtStart(head);
        return;
    }

    struct Node* temp = *head;
    int ptr = 0;
    while(ptr < position && temp -> next != NULL) {
        temp = temp -> next;
        ptr++;
    }
    if(ptr != position) {
        printf("Inavlid position. Exceeds the list length\n");
    } else {
        temp -> prev -> next = temp-> next;
        if(temp -> prev != NULL){
            temp -> next -> prev = temp -> prev;
        }
        free(temp);
    }
}



int main(){
    struct Node* head = NULL;
    
    insertAtStart(&head, 12);
    insertAtEnd(&head, 67);
    insertAtStart(&head, 98);
    insertAtEnd(&head, 45);
    insertAtStart(&head, 4);
    printf("Initial List : \n");
    displayList(head);
    
    printf("Insert At Position 3 : \n");
    insertAtPosition(&head, 21, 3);
    displayList(head);

    printf("Delete At Position 4 : \n");
    deleteAtPosition(&head, 4);
    displayList(head);
    
    
}