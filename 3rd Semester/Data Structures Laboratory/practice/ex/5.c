// Program 5 Evaluation of Postfix Expression
//  Write a C program to evaluate a valid postfix expression using stack. Assume that the
//  postfix expression is read as a single line consisting of non-negative single digit operands
//  and binary operators. The operators are +- * and /

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20

int stack[MAX],top=-1;

void push(int x){
        if(top<MAX-1){
            stack[++top]=x;
        }
        else{
        printf("Stack Overflow");
        }
}

int pop(){
    return (top!=-1)?(stack[top--]):(printf("STack Underflow"));
}

int main(){
    char exp[20],*e,x;
    int n1,n2,n3;
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    for(e=exp;*e;e++){
        if(isdigit(*e)){
            push(*e-'0');
        }
        else{
            n1=pop();
            n2=pop();   
            switch(*e){
                case '+':n3=n2+n1;break;
                case '-':n3=n2-n1;break;
                case '*':n3=n2*n1;break;
                case '/':n3=n2/n1;break;
            }
            push(n3);

        }
    }
    printf("The result of postfix %s=%d\n",exp,pop());
    return 0;
}


// #include<stdio.h>
// #include<ctype.h>
// #define MAX 20

// int stack[20], top=-1;

// void push(int x){
//     (top==MAX-1) ? (printf("Stack Overflow")) : (stack[++top]=x);
// }

// int pop(){
//     return (top==-1)? (printf("Stack Underflow"),-1) : stack[top--];
// }

// int main(){
//     char exp[MAX],*e;
//     int n1,n2,n3;
//     printf("Enter the postfix expression: ");
//     scanf("%s",&exp);

//     for(e=exp;*e;e++){
//         if(isdigit(*e)){
//             push(*e-'0');
//         }
//         else{
//             n1=pop();
//             n2=pop();
//             switch(*e){
//                 case '+':n3=n2+n1; break;
//                 case '-':n3=n2-n1; break;
//                 case '*':n3=n2*n1; break;
//                 case '/':n3=n2/n1; break;
//             }
//             push(n3);
//         }
//     }
//     printf("Result %s = %d",exp,pop());
//     return 0;
// }