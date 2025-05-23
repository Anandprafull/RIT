#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int call[MAX];
int front = -1, rear = -1;

void insert();
void delete();
void display();

void main()
{
    int choice;
    while (1)
    {
        printf("\nEnter Choice: \n1.Add call\n2.Remove Call\n3.Display Call list\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }
}

void insert()
{
    int callerid;
    printf("Enter Callerid:");
    scanf("%d", &callerid);

    if (rear == MAX - 1)
    {
        printf("Queue Overflow");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear += 1;
        call[rear] = callerid;
        printf("\n CallerId added -> %d", callerid);
    }
}

void delete()
{
    if (front == -1)
        printf("Queue Underflow");

    else
    {
        printf("\nCaller Id deleted-> %d", call[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if (rear == -1 || front == -1)
    {
        printf("\n Queue is Empty!");
    }
    else
    {
        printf("\n CallerId list :");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", call[i]);
        }
    }
}