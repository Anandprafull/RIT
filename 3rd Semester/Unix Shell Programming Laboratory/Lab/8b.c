#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    printf("Files in the current directory:\n");

    DIR *dir = opendir(".");
    if (!dir) { perror("Error"); exit(EXIT_FAILURE); }

    struct dirent *d;
    while ((d = readdir(dir))) 
        if (d->d_name[0] != '.') 
            printf("%s\n", d->d_name);

    closedir(dir);
    return 0;
}

