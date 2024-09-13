#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
    pid_t current_process_pid = getpid();
    if (current_process_pid < 0) {
        printf("Failed to get current process pid");
        return 1;
    }
    printf("current process pid is %d\n", current_process_pid);
    return 0;
}
