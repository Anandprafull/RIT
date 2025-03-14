#include <stdio.h>
#include <stdlib.h>

#define MAX 3

struct CQ
{
    int data;
};

struct CQ queue[MAX];
int front = -1, rear = -1;

void insert();
void delete();
void display();

void main()
{
    int choice;
    while (1)
    {
        printf("\nEnter choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
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
        default: printf("\ninvalid choice");
        }
    }
}

void insert()
{
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear].data = ele;
    }
    else if (((rear + 1) % MAX) == front)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear].data = ele;
    }
}

void delete()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow");
    }
    else if (front == rear)
    {
        printf("Deleted element: %d", queue[front].data);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element: %d", queue[front].data);
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i;
    if (front == -1 || rear == -1)
    {
        printf("\nEmpty queue!");
    }
    else
    {
        printf("\nFront -> %d", front);
        printf("\nItems ->");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d\t", queue[i].data);
        }
        printf("%d", queue[i].data); //
        printf("\nRear -> %d\n", rear);
    }
}
