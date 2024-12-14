// Remove duplacate characters
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void *removeDuplicated(char *myString, int size);

int main()
{
    char myString[] = {"hellooeaellooabc"};
    int size = strlen(myString);
    removeDuplicated(myString, size);
    printf("what is my string now: %s\n", myString);
}

void *removeDuplicated(char *myString, int size)
{
    bool myBool[256] = {false};
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (myBool[(int)myString[i]] == false)
        {
            myBool[(int)myString[i]] = true;
            myString[count] = myString[i];
            count++;
        }
    }
    myString[count] = '\0';
}