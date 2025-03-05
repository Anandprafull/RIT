#include <stdio.h>

static int step = 0; // Step counter

void ToH(int n, char source, char spare, char dest) {
    if (n == 1) {
        printf("\nStep %d: Move disk %d from %c to %c", ++step, n, source, dest);
    } else {
        ToH(n - 1, source, dest, spare);
        printf("\nStep %d: Move disk %d from %c to %c", ++step, n, source, dest);
        ToH(n - 1, spare, source, dest);
    }
}

int main() {
    int n;
    printf("Enter the number of rings: ");
    scanf("%d", &n);
    ToH(n, 'A', 'B', 'C'); // Move n rings from A to C using B
    return 0;
}