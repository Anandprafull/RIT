#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(pipe1[0]);
        close(pipe2[1]);

        char input[BUFFER_SIZE];
        printf("Enter a string: ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0;

        write(pipe1[1], input, strlen(input) + 1);

        char output[BUFFER_SIZE];
        read(pipe2[0], output, BUFFER_SIZE);
        printf("Concatenated String from P2: %s\n", output);

        close(pipe1[1]);
        close(pipe2[0]);
    } else { // Child process
        close(pipe1[1]);
        close(pipe2[0]);

        char received[BUFFER_SIZE];
        read(pipe1[0], received, BUFFER_SIZE);

        const char *concat_str = " - Processed by P2";
        char result[BUFFER_SIZE];

        int i = 0, j = 0;
        while (received[i] != '\0') result[i++] = received[i++];
        while (concat_str[j] != '\0') result[i++] = concat_str[j++];
        result[i] = '\0';

        write(pipe2[1], result, strlen(result) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
        exit(0);
    }

    return 0;
}

