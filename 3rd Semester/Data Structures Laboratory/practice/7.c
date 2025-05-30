#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int call[MAX], front = -1, rear = -1;

void insert() {
    int callerid;
    printf("Enter Caller ID: ");
    scanf("%d", &callerid);
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        call[++rear] = callerid;
        printf("Caller ID added -> %d\n", callerid);
    }
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("Caller ID deleted -> %d\n", call[front++]);
        if (front > rear) front = rear = -1; // Reset queue
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Caller ID list: ");
        for (int i = front; i <= rear; i++) {
            printf("%d\t", call[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter Choice:\n1. Add Call\n2. Remove Call\n3. Display Call List\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}