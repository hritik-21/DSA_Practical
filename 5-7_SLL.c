// Write a program to perform following operations on SLL
// 1. create a LL(Insert)
// 2. delete a node
// 3. reverse
// 4. Display/Traverse

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(int value){
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    if(temp != NULL && temp->data==value){
        head = temp->next;
        free(temp);
        return;
    }
    else {
        while(temp != NULL && temp->data!=value){
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL){
            printf("%d not found.\n", value);
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
}

void reverse(){
    struct Node* prev = NULL;
    struct Node* temp = head;
    struct Node* next = NULL;

    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head=prev;
}

void display(){
    struct Node* temp = head;
    if(temp==NULL){
        printf("List is empty\n");
        return;
    }
    printf("\nLinked List Elements: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

int main(){
    insertNode(10);
    insertNode(20);
    insertNode(30);

    reverse();
    display();

    deleteNode(20);
    display();

    return 0;
}