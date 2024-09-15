#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void function(int number) {
    if (number <= 0) {
        return;
    }
    int i = number;
    printf("Address of i is: %p\n", &i);
    function(number - 1);
}

int main() {
    function(100);
    return 0;
}