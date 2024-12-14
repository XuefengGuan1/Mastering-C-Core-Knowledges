// Check if a number is power of 2
#include <stdio.h>
#include <stdbool.h>

bool checkNum(int number);

int main()
{
    checkNum(5);
    checkNum(4);
    checkNum(8);
    checkNum(16);
    checkNum(256);
    checkNum(12312);
    checkNum(111);
    checkNum(1);


    return 0;
}

bool checkNum(int number)
{
    int curr = 1;
    while (curr <= number)
    {
        if (curr == number)
        {
            printf("number %d is power of 2\n", number);
            return true;
        }
        curr = curr << 1;
    }
    return false;
}