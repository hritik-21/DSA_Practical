// Double Ended Queue using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueueFront(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(front==NULL){
        front = newNode;
        rear = newNode;
    }
    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void enqueueRear(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(front==NULL){
        front = newNode;
        rear = newNode;
    }
    else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeueFront(){
    if(front==NULL){
        printf("Stack is empty.");
        return;
    }
    struct Node *temp = front;
    if(front==rear){
        front = NULL;
        rear = NULL;
    }
    else{
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

void dequeueRear(){
    if(front==NULL){
        printf("Stack is empty.");
        return;
    }
    struct Node *temp = rear;
    if(front==rear){
        front = NULL;
        rear = NULL;
    }
    else{
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

int main(){

    return 0;
}
