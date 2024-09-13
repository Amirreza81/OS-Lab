#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int ret = fork();
    printf("After first fork\n");
    fork();
    printf("After second fork\n");
    fork();
    printf("After third fork\n");
    if (ret == 0) {
        printf("I am the child\n");
        return 23;
    } else {
        int rc = 0;
        wait(&rc);
        printf("I am the parent\n");
    }
    return 0;
}