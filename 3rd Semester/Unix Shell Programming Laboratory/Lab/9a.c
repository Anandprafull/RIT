#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 1024  

int main(int argc, char *argv[]) { 
    if (argc != 3) { 
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]); 
        exit(EXIT_FAILURE); 
    } 
 
    FILE *source, *destination; 
    char buffer[SIZE]; 
    size_t bytesRead; 

    // Open the source file in binary read mode 

    source = fopen(argv[1], "rb"); 

    if (source == NULL) { 
        perror("Error opening source file"); 
        exit(EXIT_FAILURE); 
    } 
 
    // Open or create the destination file in binary write mode 

    destination = fopen(argv[2], "wb"); 

    if (destination == NULL) { 
        perror("Error opening destination file"); 
 
        fclose(source); // Close the source file if destination cannot be opened 
        exit(EXIT_FAILURE); 
    } 
 
    // Copy the content from source to destination 
    //
    while ((bytesRead = fread(buffer, 1, SIZE, source)) > 0) { 
        fwrite(buffer, 1, bytesRead, destination); 
    } 

    // Close the files 

    fclose(source); 
    fclose(destination); 
 
    printf("File copied successfully.\n"); 
    return 0; 
}

