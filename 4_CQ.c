// Write a program to implement delete and display operations on a circular queue using Array.

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;

int isFull(){
    return (front == (rear+1)%MAX);
}

int isEmpty(){
    return (front == -1);
}

void enqueue(int data){
    if(isFull()){
        printf("Queue is full. Cannot Enqueue.\n");
        return;
    }
    
    if(isEmpty()){
        front=0;
    }
    rear=(rear+1)%MAX;
    queue[rear]=data;
    printf("Enqueued %d\n", data);
}

void dequeue(){
    int n;
    if(isEmpty()){
        printf("Queue is Empty. Cannot Dequeue.\n");
        return;
    }
    n=queue[front];

    if(front == rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
    printf("Dequeued %d\n", n);
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue Elements: ");
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    display();
    dequeue();
}