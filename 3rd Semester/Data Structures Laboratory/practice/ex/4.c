// Program 4 Infix to Postfix Conversion
//  Write a C program to convert and print a given valid parenthesized infix arithmetic
//  expression to postfix expression. The expression consists of single character operands
//  and binary operators +- * /. Apply the concept of stack data structure to solve this
//  problem

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20

char stack[MAX];
int top=-1;

void push(char x){
    stack[++top]=x;
}

char pop(){
    return (top==-1)?(printf("Underflow"),-1):(stack[top--]);
}

int priority(char x){
    if (x=='(') return 0;
    if (x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    return 0;
}

int main(){
    char exp[MAX],*e,x;
    printf("ENter infix expression");
    scanf("%s",exp);
    for(e=exp;*e;e++){
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e=='('){
            push(*e);        
        }
        else if(*e==')'){
            while((x=pop())!='(')
                printf("%c",pop());
        }
        else{
            while(top!=-1 && priority(stack[top])>=priority(*e))
            printf("%c",pop());
            push(*e);
        }
    }
    while(top!=-1){
        printf("%c\n",pop());
        return 0;
    }
}




























// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>
// #define MAX 20

// char stack[MAX];
// int top=-1;

// void push(char x){
//     (top==MAX-1)? (printf("Stack Overflow")) : (stack[++top]=x);
// }

// char pop(){
//     return (top==-1)? (printf("Stack UNderflow"),-1): (stack[top--]);
// }

// int priority(char x){
//     if(x=='(') return 0;
//     if(x=='+'||x=='-') return 1;
//     if (x=='*'||x=='/') return 2;
//     return 0;
// }

// int main(){
//     char exp[MAX],*e,x;
//     printf("Enter the infix expression");
//     scanf("%s",exp);

//     for(e=exp;*e;e++){
//         if(isalnum(*e)){
//             printf("%c",*e);
//         }
//         else if(*e=='(')
//             push(*e);
//         else if(*e==')'){
//             while((x=pop()!='(')) printf("%c",x);
//         }
//         else{
//             while(top!=-1 && priority(stack[top]>=priority(*e)))
//                 printf("%c",pop());
//                 push(*e);
//         }
//     }
//     while(top!=-1){
//         printf("%c",pop());
//         return 0;
//     }
// }