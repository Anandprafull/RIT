#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 100

int main() {
    char buf[MAX];
    int fd = open("file.txt", O_RDWR);
    if (fd < 0) return perror("Error opening file"), 1;

    int n;
    printf("Enter number of characters to read and append: ");
    scanf("%d", &n);

    lseek(fd, -n, SEEK_END);
    ssize_t r = read(fd, buf, n);
    
    lseek(fd, 0, SEEK_END);
    write(fd, buf, r);

    close(fd);
    printf("%ld characters read and appended.\n", r);
    return 0;
}

