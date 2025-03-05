// Program 7 Call holding in call centre
//  ACall center phone system has to hold the phone calls from customers and provide
//  service based on the arrival time of the calls. Write a C program to simulate this system
//  using appropriate data structure. Program should have options to add and remove the
//  phone calls in appropriate order for their service

#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int call[MAX], front=-1,rear=-1;

void insert(){
    int callerid;
    printf("Enter callerid: ");
    scanf("%d",&callerid);
    if(rear==MAX-1){
        printf("Overflow");
        return;
    }
    else{
        if(front==-1){
            front=0;
        }
        call[++rear]=callerid;
        printf("Callerid added->%d\n",callerid);
    }
}

void delete(){
    if(front==-1){
        printf("Queue underflow");
        return;
    }
    else{
        printf("Callerid deleted->%d\n",call[front++]);
        if(front>rear){
            front=rear=-1;
        }
    }
}

void display(){
    if(front==-1){
        printf("Queue Empty");
        return;
    }
    else{
        printf("Callerid list: ");
        for(int i=front;i<=rear;i++){
            printf("%d\t",call[i]);
        }
        printf("\n");
    }
}

int main(){
    int c;
    while(1){
        printf("\n1.Add Call\n2.Remove Call\n3.Display call list\n4.Exit\n");
        scanf("%d",&c);
        switch(c){
            case 1:insert();break;
            case 2:delete();break;
            case 3:display();break;
            case 4:exit(0);
        }
    }
}