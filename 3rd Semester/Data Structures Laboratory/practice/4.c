#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return (top == -1) ? -1 : stack[top--]; }
int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[MAX], *e, x;
    printf("Enter infix expression: ");
    scanf("%s", exp);
    
    for (e = exp; *e; e++) {
        if (isalnum(*e) || *e == '.') printf("%c", *e); // Print operands
        else if (*e == '(') push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(') printf("%c", x);
        } else {
            while (top != -1 && priority(stack[top]) >= priority(*e)) printf("%c", pop());
            push(*e);
        }
    }

    while (top != -1) printf("%c", pop()); // Pop remaining operators
    printf("\n");
    return 0;
}