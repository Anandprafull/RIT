#include <stdio.h>
#include <stdlib.h>

#define MAX 3

struct CQ {
    int data;
};

struct CQ queue[MAX];
int front = -1, rear = -1;

void insert() {
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear].data = ele;
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front].data);
    if (front == rear) {
        front = rear = -1; // Reset queue
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Empty queue!\n");
        return;
    }
    printf("Front -> %d\nItems -> ", front);
    for (int i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d\t", queue[i].data);
    }
    printf("%d\nRear -> %d\n", queue[rear].data, rear);
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter choice:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}