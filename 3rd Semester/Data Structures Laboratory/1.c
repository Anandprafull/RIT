#include<stdio.h>
#include<stdlib.h>

int a[100], n;

void create();
void display();
void insert();
void delete();

void main(){
	int choice;
	while(1){
		printf("\n Enter your choice: \n1. Create\n2. Display\n3. Insert\n 4. Delete\n5. Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: insert();
				break;
			case 4: delete();
				break;
			case 5: exit(0);
				}
	}
}

void create(){
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter array elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}

void display(){
	for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

void insert(){
	int ele,pos;
	printf("Enter theelement to be inserted: ");
	scanf("%d",&ele);
	printf("Enter the position at which the element has o be inserted");
	scanf("%d",&pos);
	if(pos<0|| pos>n){
		printf("Invalid");
		return;
	}
	for(int i=n;i>=pos;i--){
		a[i]=a[i-1];
	}
	a[pos]=ele;
	n++;
}

void delete(){
	int i,p;
	printf("Enter element position");
	scanf("%d",&p);
	for(i=p;i<=n;i++)
	{
		a[i-1]=a[i];
	}
	n--;
}
