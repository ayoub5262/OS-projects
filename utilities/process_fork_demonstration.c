#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int x = 1;
void next(){printf("%d ", x++);}

int main() {
    next();
    pid_t pid = fork();
    if (pid > 0) {
        wait(NULL);
        next();
        next();
    } else if (pid == 0) {
        next();
    } else {
        next();
        printf("fork failed\n");
    }
    return 0;
}











































































































