#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int ret = fork();
    if (ret == 0) {
        for (int i = 1; i <= 100; i++) {
            printf("i = %d\n", i);
        }
        return 23;
    } else {
        wait(NULL);
        printf("Child process job is done\n");
    }
    return 0;
}