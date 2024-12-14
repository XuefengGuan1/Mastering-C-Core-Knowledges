#include <stdio.h>
#include <string.h>

int main(){
    char myArr[] = "my name is aaa, and my age is: ";
    int size = strlen(myArr);
    int age = 5;

    size += sprintf(myArr+size, "%d", age);

    printf("what is my new arr: %s, what is my arr length now %d\n", myArr, size);

    return 0;
}