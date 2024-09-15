#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MyStruct {
    int a;
    int b;
    char name[20];
};

int main()
{
    struct MyStruct* myStruct = (struct MyStruct * ) malloc(sizeof(struct MyStruct));
    myStruct -> a = 0;
    myStruct -> b = 1;
    strcpy(myStruct -> name, "myStruct");
    printf("myStruct = %p\n", myStruct);
    printf("myStruct values : a = %d, b = %d, name = %s\n", myStruct -> a, myStruct -> b, myStruct -> name);
    free(myStruct);
    return 0;
}