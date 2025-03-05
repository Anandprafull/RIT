#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char buf[50];
    ssize_t n;

    // Open the file in read-write mode
    if ((fd1 = open("t1.txt", O_RDWR)) < 0) {
        perror("File open error");
        exit(1);
    }

    // Duplicate the file descriptor using dup2
    fd2 = dup2(fd1, fd1 + 1); // Duplicate fd1 to fd2
    if (fd2 < 0) {
        perror("dup2 error");
        close(fd1);
        exit(1);
    }

    // Prompt the user to enter the number of characters to read
    printf("Enter the number of characters to read: ");
    scanf("%zd", &n);

    if (n <= 0 || n >= sizeof(buf)) {
        fprintf(stderr, "Invalid number of characters to read.\n");
        close(fd1);
        close(fd2);
        exit(1);
    }

    // Read n characters from the file
    if (read(fd1, buf, n) < 0) {
        perror("Read error");
        close(fd1);
        close(fd2);
        exit(1);
    }

    // Null-terminate the buffer for safety
    buf[n] = '\0';

    // Move the fd2 file descriptor to the end of the file
    if (lseek(fd2, 0, SEEK_END) < 0) {
        perror("lseek error");
        close(fd1);
        close(fd2);
        exit(1);
    }

    // Write the read characters back to the file
    if (write(fd2, buf, n) < 0) {
        perror("Write error");
        close(fd1);
        close(fd2);
        exit(1);
    }

    printf("Successfully appended %zd characters to the file.\n", n);

    // Close the file descriptors
    close(fd1);
    close(fd2);

    return 0;
}
