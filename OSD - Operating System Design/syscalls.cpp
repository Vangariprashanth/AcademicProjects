#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include<string.h>
int main() {
    // a) fork()
    pid_t pid = fork();
    if (pid < 0) {
        perror("Error occured while creating a fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        printf("Child Process created.\n");
         // d) open()
    int f_descriptor = open("Question2.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (f_descriptor == -1) {
        perror("Error occured while opening the file");
        exit(EXIT_FAILURE);
    }
    // e) write()
    const char *data = "Writing Homework1\n";
    ssize_t write_data = write(f_descriptor, data, strlen(data));
    if (write_data == -1) {
        perror("Error occured while writing the file");
        exit(EXIT_FAILURE);
    }
    // g) close()
    if (close(f_descriptor) == -1) {
        perror("Error occured while closing the file");
        exit(EXIT_FAILURE);
    }
    // Read the file which we created
    f_descriptor = open("Question2.txt", O_RDONLY);
    if (f_descriptor == -1) {
        perror("Error occured while opening the file for reading");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    ssize_t read_data = read(f_descriptor, buffer, sizeof(buffer));
    if (read_data == -1) {
        perror("Read failed");
        exit(EXIT_FAILURE);
    }
    printf("Read from file: %s", buffer);
    // g) close() again
    if (close(f_descriptor) == -1) {
        perror("Close for reading failed");
        exit(EXIT_FAILURE);
    }
        exit(EXIT_SUCCESS);
    } else {
        // b) wait()
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Parent Process waited for Child to exit with status: %d\n", WEXITSTATUS(status));
        }
        // c) exit()
        printf("Parent Process is exiting.\n");
        exit(EXIT_SUCCESS);
    }
    return 0;
}

