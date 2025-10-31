// Write a program to implement push and display operations on stack using Array

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int stack[MAX];
int top=-1;

void push(int n){
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }
    top++;
    stack[top]=n;
    printf("%d pushed in stack\n", n);
}

void pop(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

void peek(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    printf("Top element: %d\n", stack[top]);
}

void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack Elements: ");
        for(int i=0; i<=top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    push(10);
    push(20);
    push(30);

    pop();
    peek();
    display();

    return 0;
}