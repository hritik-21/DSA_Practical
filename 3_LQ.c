// Write a program to implement insert and display operations on a linear queue.

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int data){
    if(rear==MAX-1){
        printf("Queue is full. Cannot Enqueue.\n");
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        queue[rear]=data;
        printf("Enqueued %d\n", data);
    }
    else{
        rear++;
        queue[rear]=data;
        printf("Enqueued %d\n", data);
    }
}

void dequeue(){
    int n;
    if(front==-1){
        printf("Queue is Empty. Cannot Dequeue.\n");
    }
    else if(front==rear){
        n=queue[front];
        front=-1;
        rear=-1;
        printf("Dequeued %d\n", n);
    }
    else{
        n=queue[front];
        front++;
        printf("Dequeued %d\n", n);
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty.\n");
    }
    printf("Queue Elements: ");
    for(int i=0; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    return 0;
}
