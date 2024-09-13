#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int ret = fork();
    if (ret < 0) {
        printf("Failed to fork a process");
        return 1;
    } else if (ret == 0) {
        execlp("ls", "ls", "-g", "-h", (char *)NULL);
        return 0;
    } else {
        wait(NULL);
    }
    return 0;
}