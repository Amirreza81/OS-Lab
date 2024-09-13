#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int ret = fork();
    if (ret < 0) {
        printf("Failed to fork a process");
        return 1;
    } else if (ret == 0) {
        printf("My parent pid before adoption is : %d\n", getppid());
        sleep(5);
        printf("My parent pid after adoption is : %d\n", getppid());
        return 0;
    } else {
        printf("The parent pid is : %d\n", getpid());
        sleep(1);
        printf("The parent job is done\n");
    }
    return 0;
}