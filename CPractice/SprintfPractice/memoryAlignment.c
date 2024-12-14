#include <stdio.h>
#include <stdint.h>

typedef struct MyStruct
{
    char w[1];
    int64_t x;
    int y;
    char hi[2];
    //char wel[2];
} MyStruct;

int main()
{
    MyStruct *example;

    printf("pointer char %p\n", (void *)example->hi);
    printf("pointer int %p\n", (void *)&example->x);
    printf("size of int %ld\n", sizeof(int64_t));

    printf("size of struct %ld\n", sizeof(MyStruct));
}