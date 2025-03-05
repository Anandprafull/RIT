#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int arr[MAX],n=0;

void create(){
	
	printf("Enter no of elements: ");
	scanf("%d",&n);

	printf("Enter elements ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
	printf("Array with %d elements created",n);
}

void display(){
	printf("Array elements are: ");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

void insert(){
	int pos,ele;
	printf("Enter position to be inserted");
	scanf("%d",&pos);
	printf("Enter element to be inserted ");
	scanf("%d",&ele);
	for(int i=n;i>pos;i--){
		arr[i]=arr[i-1];
	}
	arr[pos]=ele;
	n++;
	printf("Element %d inserted at position %d ",ele,pos);
}

void delete(){
	int pos;
	printf("Enter the pos of element to be deleted");
	scanf("%d",&pos);
	for(int i=pos;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	n--;
	printf("Element  at position %d deleted ",pos);
}

int main(){
	int c;
	while(1){
		printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
		scanf("%d",&c);
		switch(c){
			case 1: create();break;
			case 2: display();break;
			case 3: insert();break;
			case 4: delete();break;
			case 5: exit(0);break;
			default: printf("Invalid choice");
		}
	}
}

