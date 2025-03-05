#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF 1024

int main(int c, char *v[]) {
    if (c != 3) return printf("Usage: %s <pattern> <file>\n", v[0]), 1;
    int fd = open(v[2], O_RDONLY), len = 0; 
    if (fd < 0) return perror("Error"), 1;

    char buf[BUF + 1], line[2 * BUF]; 
    while (read(fd, buf, BUF) > 0) {
        for (char *s = buf, *nl; *s; s = nl + 1) {
            if ((nl = strchr(s, '\n'))) *nl = 0;
            strcpy(line + len, s), len += strlen(s);
            if (!nl || len >= sizeof(line)) continue;
            line[len] = 0, strstr(line, v[1]) && printf("%s\n", line);
            len = 0;
        }
    }

    if (len) line[len] = 0, strstr(line, v[1]) && printf("%s\n", line);
    close(fd);
}

