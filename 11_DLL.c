// Write a program to perform following operations on DLL
// 1. Insert a node 2. Delete a node 3. Display/Traverse

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if(head==NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int value){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    // Deleting head
    if(head->data == value){
        struct Node* toDelete = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        free(toDelete);
        return;
    }

    // Deleting middle or last node
    struct Node* temp = head->next;
    while(temp != NULL && temp->data != value){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("%d not found.\n", value);
        return;
    }

    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}

// Function to display the DLL
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    insertNode(10);
    insertNode(20);
    insertNode(30);
    display();

    deleteNode(20);
    display();

    deleteNode(10);
    display();

    deleteNode(30);
    display();

    return 0;
}