#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024  

int main(int c, char *v[]) {
    if (c != 3) return fprintf(stderr, "Usage: %s <src> <dst>\n", v[0]), 1;

    FILE *src = fopen(v[1], "rb"), *dst = fopen(v[2], "wb");
    if (!src || !dst) return perror("Error opening file"), src ? fclose(src), 1 : 1;

    char buf[SIZE];
    size_t r;
    while ((r = fread(buf, 1, SIZE, src))) fwrite(buf, 1, r, dst);

    fclose(src), fclose(dst);
    printf("File copied successfully.\n");
    return 0;
}

