#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int call[MAX],front=-1,rear=-1;

void add(){
	int callerid;
	printf("Enter callerid to add");
	scanf("%d",&callerid);
	if(rear==MAX-1){
		printf("Overflow");
	}
	else{
		if(front==-1)
			front=0;
		call[++rear]=callerid;
		printf("Callerid added -> %d",callerid);
	}
	}

void remova(){
	if(front==-1){
		printf("Underflow");
	}
	else{
		printf("Callerid deleted->%d",call[front++]);
		if(front>rear)
			front=rear=-1;
	}
}

void display(){
	for(int i=front;i<=rear;i++){
		printf("%d",call[i]);
	}
	printf("\n");
}

int main(){
	int c;
	while(1){
		printf("\n1.Add Call\n2.Remove Call\n3. Display Call list\n4.Exit\n");
		scanf("%d",&c);
		switch(c){
			case 1:add();break;
			case 2:remova();break;
			case 3:display();break;
			case 4:exit(0);
			default:printf("Invalid choice");
		}
	}
	return 0;
}

