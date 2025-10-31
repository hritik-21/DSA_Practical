// Conversion of Infix Expression to Prefix Expression Using Stack

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

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

void reverse(char exp[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    char rev[MAX], temp[MAX];
    int i, k = 0;

    strcpy(rev, infix);
    reverse(rev);

    for (i = 0; rev[i]; i++) {
        if (rev[i] == '(')
            rev[i] = ')';
        else if (rev[i] == ')')
            rev[i] = '(';
    }

    for (i = 0; rev[i]; i++) {
        if (isalnum(rev[i])) {
            temp[k++] = rev[i];
        } else if (rev[i] == '(') {
            push(rev[i]);
        } else if (rev[i] == ')') {
            while (top != -1 && stack[top] != '(')
                temp[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(rev[i]))
                temp[k++] = pop();
            push(rev[i]);
        }
    }

    while (top != -1)
        temp[k++] = pop();
    
    temp[k] = '\0';
    reverse(temp);
    strcpy(prefix, temp);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}