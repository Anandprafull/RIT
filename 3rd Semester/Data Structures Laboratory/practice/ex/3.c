//  Program 3 Stack Implementation
//  STACK of Integers (Array Implementation of Stack with maximum size MAX)
//  a) Push an Element onto Stack.
//  b) Pop an Element from Stack.
//  c) Demonstrate how Stack can be used to check Palindrome.
//  d) Demonstrate Overflow and Underflow situations on Stack
//  e) Display the status of Stack
//  f) Exit
//  Support the program with appropriate functions for each of the above operations

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX],top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return (top!=-1)? (stack[top--]):(printf("Stack Underflow"),-1);
}

void display(){
    if(top==-1){
        printf("EMpty stack");
    }else{
    printf("Stack");
        for(int i=top;i>=0;i--){
            printf("%d",stack[i]);
        }
    }
}

void check_pal(){
    for(int floor=0,ceil=top;floor<ceil;floor++,ceil--){
        if(stack[floor]!=stack[ceil]){
            printf("Not Pal");
            return;
        }
    }
    printf("is pal");
}

int main(){
    int c,x;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Check_pal\n5.Exit\n");
        scanf("%d",&c);
        switch(c){
            case 1: printf("ENter the ele: "); scanf("%d",&x); push(x); break;
            case 2: x=pop(); 
                if(x!=-1){
                    printf("The popped element is %d",x);
                }else{
                    printf("Underflow");
                }
                break;
            case 3: display();break;
            case 5: exit(0);
            case 4: check_pal();break;
        }
    }
}
