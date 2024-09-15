#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    void *initial_sbrk = sbrk(0);
    printf("Initial end of heap: %p\n", initial_sbrk);

    int count = 0;
    void *current_sbrk = initial_sbrk;
    while (current_sbrk == initial_sbrk) {
        malloc(1024 * 1024);
        current_sbrk = sbrk(0);
        if (count > 1) {
            printf("Loop count is greater than 1\n");
            return 0;
        }
        count++;
    }

    printf("Loop count is %d\n", count);
    return 0;
}
