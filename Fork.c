#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    pid_t p = fork();

    if (p < 0) {
        perror("fork failed");
        exit(1);
    } else if (p == 0) {
        printf("Hello from Child! (PID: %d)\n", getpid());
    } else {
        printf("Hello from Parent! (Child PID: %d)\n", p);
    }
    return 0;
}