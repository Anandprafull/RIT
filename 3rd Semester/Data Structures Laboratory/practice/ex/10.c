//  Program 10 Stack using Linked List
//  Write a C program to maintain a stack of integers using a linked list implementation
//  method

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} N;

N *top=NULL;

void push(){
    int ele;
    printf("Enter element: ");
    scanf("%d",&ele);

    N *temp = (N *)malloc(sizeof(N));
    if(!temp){
        printf("Overflow");
        return;
    }
    temp->data=ele;
    temp->next=top;
    top=temp;
}

void pop(){
    if(!top){
        printf("Underflow");
        return;
    }

    N *temp = top;
    printf("Popped element is %d\n",temp->data);
    top=temp->next;
    free(temp);
}

void display(){
    if(!top){
        printf("Empty Stack");
        return;
    }
    N *temp = top;
    printf("Stack elements are: ");
    while(temp){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void peek(){
    if(!top){
        printf("Empty Stack");
        return;
    }
    printf("Top element is %d\n ",top->data);

}

int main(){
    int c;
    while(1){
    printf("\n1.Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
    scanf("%d",&c);
    switch(c){
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: peek(); break;
        case 5: exit(0);
        default: printf("Invalid");
    }
    }
}