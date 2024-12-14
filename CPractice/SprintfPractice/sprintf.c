#include <stdio.h>
#include <string.h>

int main()
{
    char myArr[100] = "nice ";
    int size = strlen(myArr);
    printf("what is my size %d\n", size);
    // size; // remove the \0
    int myName = 123;
    char greetings[] = ", welcome here!";

    size += sprintf(myArr + size, "%d", myName);

    size += sprintf(myArr + size, "%s", greetings);

    printf("my new string is: %s", myArr);
    printf("\n");
    return 0;
}