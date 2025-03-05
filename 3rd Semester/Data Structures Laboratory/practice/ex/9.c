// Program 9 Linked list for sorted names
//  Write a program to create a singly linked list that maintains a list of names in alphabetical order.
//  Implement the following operations on the list.
//  a. Insert a new name
//  b. Delete a specified name

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[50];
    struct node *next;
} N;

N *head = NULL;

void insert(){
    char name[50];
    printf("Enter the name ");
    scanf("%s",name);

    N *nn=(N *)malloc(sizeof(N));
    strcpy(nn->name,name);
    nn->next=NULL;

    if(!head ||strcmp(head->name,name)>=0){
        nn->next=head;
        head=nn;
    } else {
        N *temp=head;
        // Traverse the list to find the correct position for the new node
        while(temp->next && strcmp(temp->next->name,name)<0){
            temp=temp->next;
        }
        // Insert the new node at the correct position
        nn->next=temp->next;
        temp->next=nn;
    }
}

void delete(){
    char name[50];
    printf("Enter the name ");
    scanf("%s",name);

    N *temp = head,*prev=NULL;

    while(temp && strcmp(temp->name,name)!=0){
        prev=temp;
        temp=temp->next;
    }

    if(!temp){
        printf("Name not found");
        return;
    }
    if(prev){
        prev->next=temp->next;
    } else{
        head=temp->next;
    }
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
    printf("\n1.insert\n2.Delete\n3.display\n4.exit");
    scanf("%d",&c);
    switch(c){
        case 1: insert(); break;
        case 2: delete(); break;
        case 3: display(); break;
        case 4: exit(0);
    }
    }
}