#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 100

int main() {
    char buf[MAX];
    int fd = open("file.txt", O_RDWR);
    if (fd < 0) return perror("Error opening file"), 1;

    int n, file_size = lseek(fd, 0, SEEK_END);
    printf("Enter number of characters to read and append: ");
    if (scanf("%d", &n) != 1 || n <= 0) return perror("Invalid input"), close(fd), 1;
    
    if (n > file_size) n = file_size; // Prevent seeking beyond file size

    lseek(fd, -n, SEEK_END);
    ssize_t r = read(fd, buf, n);
    if (r < 0) return perror("Error reading file"), close(fd), 1;

    lseek(fd, 0, SEEK_END);
    if (write(fd, buf, r) != r) return perror("Error writing"), close(fd), 1;

    close(fd);
    printf("%ld characters read and appended.\n", r);
    return 0;
}

