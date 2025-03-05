#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 100

int main() {
    char filename[] = "file.txt";
    int fd, new_fd, n;
    char buffer[MAX_SIZE];
    ssize_t bytes_read;

    printf("Enter the number of characters to read and append: ");
    scanf("%d", &n);

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    lseek(fd, 0, SEEK_END);
    new_fd = dup(fd);
    if (new_fd == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        exit(EXIT_FAILURE);
    }

    lseek(fd, -n, SEEK_END);
    bytes_read = read(fd, buffer, n);
    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        close(new_fd);
        exit(EXIT_FAILURE);
    }

    if (write(new_fd, buffer, bytes_read) != bytes_read) {
        perror("Error writing to file");
        close(fd);
        close(new_fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    close(new_fd);
    printf("%ld characters read and appended successfully.\n", bytes_read);
    return 0;
}

