// Write a program to perform following operations on circular SLL
// 1. Insert a node 2. Delete a node 3. Display/Traverse

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

    if(head==NULL){
        head = newNode;
        newNode->next=head;
        return;
    }
    struct Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next=head;
}

void deleteNode(int value){
    struct Node* temp = head;
    struct Node* prev = NULL;

    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    
    if(head->data==value){
        if(head->next==head){
            free(head);
            head=NULL;
            return;
        }
        struct Node* last=head;
        while(last->next!=head){
            last=last->next;
        }
        last->next=head->next;
        temp=head;
        head=head->next;
        free(temp);
        return;
    }

    while(temp->next!=head && temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    if(temp->data!=value){
        printf("%d not found.", value);
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void display(){
    struct Node* temp = head;
    if(temp==NULL){
        printf("List is empty\n");
        return;
    }
    printf("\nLinked List Elements: ");
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    } while(temp!=head);
}

int main(){
    insertNode(10);
    insertNode(20);
    insertNode(30);

    display();

    deleteNode(20);
    display();

    return 0;
}