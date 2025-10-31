// Conversion of Infix Expression to Postfix Expression Using Stack

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;
    
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        
        if (isalnum(c)) {  // operand
            postfix[k++] = c;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        } 
        else {  // operator
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    
    while (top != -1)
        postfix[k++] = pop();
    
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}