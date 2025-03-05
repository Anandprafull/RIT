#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int arr[MAX], n = 0; // Current number of elements

void create() {
    printf("Enter size (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) n = MAX;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
}

void display() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insert() {
    if (n == MAX) {
        printf("Array is full.\n");
        return;
    }
    int pos, elem;
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &elem);
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = elem; n++;
}

void delete() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    int pos;
    printf("Enter position (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }
    printf("Deleted: %d\n", arr[pos]);
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

int main() {
    int choice;
    while (1) {
        printf("1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}
