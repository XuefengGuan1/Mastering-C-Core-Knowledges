#include <stdio.h>

int findFactorial(int num);

int main()
{
    printf("result: %d\n", findFactorial(4));

    printf("result: %d\n", findFactorial(5));
    return 0;
}

int findFactorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    return findFactorial(num - 1) * num;
}
