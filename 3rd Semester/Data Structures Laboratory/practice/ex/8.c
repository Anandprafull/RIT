// Program 8 Circular Queue using Structure
//  Write a C program to simulate the working of a Circular Queue of integers. Represent a
//  circular queue element as a structure and use an array of structures as your
//  implementation method. Start and end of the circular queue must be identified by an empty
//  array element.

#include<stdio.h>
#include<stdlib.h>
#define MAX 3

struct CQ { int data;};

struct CQ queue[MAX];
int front=-1,rear=-1;

void insert(){
    int ele;
    printf("Enter the ele ");
    scanf("%d",&ele);
    if(front==-1 && rear==-1){
        front=rear=0;
    } 
    else if((rear+1)%MAX==front){
        printf("Overflow");
        return;
    }
    rear=(rear+1)%MAX;
    queue[rear].data=ele;
}

void delete(){
    if (front==-1){
        printf("Queue Underflow");
        return;
    }
    printf("Deleted element %d\n",queue[front].data);
    if(front==rear){
        front=rear=-1;
    } else{
        front=(front+1)%MAX;
    }
}

void display(){
    if(front==-1){
        printf("Empty Queue");
        return;
    }
    printf("front->%d\n",front);
    for(int i=front;i!=rear;i=(i+1)%MAX){
        printf("%d\t",queue[i].data);
    }
    printf("%d\n Rear->%d\n",queue[rear].data,rear);
}

int main(){
    int c;
    while(1){
        printf("\n1.insert\n2.delete\n3.display\n4.exit");
        scanf("%d",&c);
        switch(c){
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}