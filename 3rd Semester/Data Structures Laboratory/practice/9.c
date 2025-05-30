#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    struct node *next;
} Node;

Node *head = NULL;

void insert() {
    char name[50];
    printf("Enter the name: ");
    scanf("%s", name);

    Node *nn = (Node *)malloc(sizeof(Node));
    strcpy(nn->name, name);
    nn->next = NULL;

    if (!head || strcmp(head->name, name) >= 0) {
        nn->next = head;
        head = nn;
    } else {
        Node *temp = head;
        while (temp->next && strcmp(temp->next->name, name) < 0) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
}

void delete() {
    char name[50];
    printf("Enter the name: ");
    scanf("%s", name);
    Node *temp = head, *prev = NULL;

    while (temp && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Name not found!\n");
        return;
    }
    if (prev) prev->next = temp->next;
    else head = temp->next; // Deleting the head
    free(temp);
}

void display() {
    Node *temp = head;
    printf("Names in the list: ");
    while (temp) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter choice:\n1. Insert name\n2. Delete name\n3. Display List\n4. Exit\n");
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