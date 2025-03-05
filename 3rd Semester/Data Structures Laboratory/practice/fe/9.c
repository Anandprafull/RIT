#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct node{
	char name[MAX];
	struct node *next;
} N;

N *head=NULL;

void insert(){
	char name[MAX];
	printf("Enter name to be inserted: ");
	scanf("%s",name);

	N *nn = malloc(sizeof(N));

	if(!nn){ printf("No Space");}

	strcpy(nn->name,name);
	nn->next=NULL;

	if(!head ||strcmp(head->name,name)>=0){
		nn->next=head;
		head=nn;
	}else{
		N *temp=head;
		while(temp->next && strcmp(temp->next->name,name)<0){
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}

}

void delete(){
	char name[MAX];
	printf("Enter name to be deleted");
	scanf("%s",name);

	N *temp=head,*prev;

	while(temp && strcmp(temp->name,name)!=0){
		prev=temp;
		temp=temp->next;
	}
	if(!temp){printf("Name not found");}

	if(prev) prev->next=temp->next;
	else head=temp->next;
	free(temp);
}

void display(){
	N *temp=head;
	printf("Names in the list: ");
	while(temp){
		printf("%s",temp->name);
		temp=temp->next;
	}
	printf("\n");
}



int main(){
	int c;
	while(1){
	printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	scanf("%d",&c);
	switch(c){
		case 1: insert();break;
		case 2: delete();break;
		case 3: display();break;
		case 4: exit(0);
		default: printf("Invalid choice");
	}
	}
}
