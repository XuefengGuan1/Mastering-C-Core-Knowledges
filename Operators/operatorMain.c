#include <stdio.h>

int main()
{
    // + - * / operations
    int x = 5;
    int y = 6;
    printf("x+y, expect 11, actual: %d\n", x + y);
    printf("x-y, expect -1, actual: %d\n", x - y);
    printf("x*y, expect 30, actual: %d\n", x * y);
    printf("x/y, expect 0 because this is int type, no decimals, actual: %d\n", x / y);

    // logical %% || !
    if (x == 5 && y == 6)
    {
        printf("x ==5, y ==6\n");
    }
    if (x == 5 || y == 6)
    {
        printf("x == 5 or y == 6 or both true\n");
    }
    if (!(x == 7))
    {
        printf("x is not equal to 7\n");
    }

    // Bitwise operation
    printf("int size: %ld\n", sizeof(int));
    // 32 bit int
    int a = 5;
    int b = 7;
    // a = 0000 0000 0000 0000 0000 0000 0000 0101
    // b = 0000 0000 0000 0000 0000 0000 0000 0111
    int bitwiseV;
    bitwiseV = a & b;
    printf("result of a&b, expected: 5, actual: %d\n", bitwiseV);
    bitwiseV = a | b;
    printf("result of a|b, expected: 7,  actual: %d\n", bitwiseV);
    bitwiseV = a ^ b;
    printf("result of a^b, expected: 2,  actual: %d\n", bitwiseV);
    bitwiseV = ~a;
    printf("result of ~a, expected: a negative number,  actual: %d\n", bitwiseV);
    bitwiseV = a << 1;
    printf("result of a<<1, expected: 10,  actual: %d\n", bitwiseV);
    bitwiseV = a >> 1;
    printf("result of a>>1, expected: 2,  actual: %d\n", bitwiseV);

    // comparision practice
    if (1 == 1)
    {
        printf("1 == 1\n");
    }
    if (1 != 2)
    {
        printf("1 != 2\n");
    }
    if (1 < 2)
    {
        printf("1 < 2\n");
    }
    if (2 > 1)
    {
        printf("2 > 1\n");
    }
    if (2 >= 1)
    {
        printf("2 >= 1\n");
    }
    if (1 <= 1)
    {
        printf("1 <= 1\n");
    }
}