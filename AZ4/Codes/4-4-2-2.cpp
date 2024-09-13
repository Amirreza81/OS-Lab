#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int variable = 0;
int main() {
    int ret = fork();
    if (ret == 0) {
        variable += 1;
        printf("we are in child process and variable = %d\n", variable);
        return 23;
    } else {
        int rc = 0;
        wait(&rc);
        variable += 1;
        printf("we are in parent process and variable = %d\n", variable);
    }
    return 0;
}
