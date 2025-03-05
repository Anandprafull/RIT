#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>

void print_permissions(mode_t mode) {
    char perms[] = "----------"; // Default for regular files
    if (S_ISDIR(mode)) perms[0] = 'd';  // Directory
    if (mode & S_IRUSR) perms[1] = 'r';
    if (mode & S_IWUSR) perms[2] = 'w';
    if (mode & S_IXUSR) perms[3] = 'x';
    if (mode & S_IRGRP) perms[4] = 'r';
    if (mode & S_IWGRP) perms[5] = 'w';
    if (mode & S_IXGRP) perms[6] = 'x';
    if (mode & S_IROTH) perms[7] = 'r';
    if (mode & S_IWOTH) perms[8] = 'w';
    if (mode & S_IXOTH) perms[9] = 'x';
    printf("%s ", perms);
}

int main() {
    struct dirent *dir;
    struct stat mystat;
    DIR *dp = opendir(".");
    
    if (!dp) {
        perror("opendir");
        return 1;
    }

    while ((dir = readdir(dp)) != NULL) {
        if (dir->d_name[0] == '.') continue; // Skip hidden files

        if (stat(dir->d_name, &mystat) == -1) {
            perror("stat");
            continue;
        }

        print_permissions(mystat.st_mode);
        printf("%2ld %6ld %s %s\n",
               mystat.st_nlink,
               (long)mystat.st_size,
               dir->d_name,
               ctime(&mystat.st_mtime)); // Last modified time
    }

    closedir(dp);
    return 0;
}

