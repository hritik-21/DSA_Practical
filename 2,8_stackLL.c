// Write a program to implement pop and peek operations on stack using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Stack Overflow\n");
        return;
    }
    n->data=data;
    n->next=top;
    top=n;

    printf("Pushed %d in stack\n", data);
}

void pop(){
    int p;
    struct Node* temp;
    
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Popped %d\n", top->data);
    temp=top;
    top=top->next;
    free(temp);
}

void peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top Element: %d\n", top->data);
}

int main(){
    push(10);
    push(20);
    push(30);

    pop();
    peek();
    pop();

    return 0;
}