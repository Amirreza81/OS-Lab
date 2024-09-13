#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    pid_t parent_pid = getppid();
    printf("parent pid is %d\n", parent_pid);
    return 0;
}