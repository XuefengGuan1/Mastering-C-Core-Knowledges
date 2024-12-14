#include <stdio.h>

// Macro
#define MYLUCKYNUM 5

void customFunc(int);
int addition(int, int);
int subtraction(int, int);
int recursiveFunc(int);
static inline int additionInline(int, int);

int main()
{
    // Call standard funcntion
    customFunc(1);

    // Pointer to function
    int x, y, result;
    printf("enter 0 for addition, 1 for subtraction\n");
    scanf("%d", &result);
    printf("enter 2 numbers you want to operate on\n");
    scanf("%d", &x);
    scanf("%d", &y);

    int (*funcs[2])(int, int) = {addition, subtraction};
    // Callback function here
    printf("%d\n", funcs[result](x, y));

    // Recursive function
    printf("Factorial of 5! using recursion, result: %d\n", recursiveFunc(5));

    // Call inline function, this equal to int x = 1+2;
    int inlineResult = additionInline(1, 2);
    printf("simple inline implementation calculate 1+2: %d\n", inlineResult);

    return 0;
}

// Just a standard function
void customFunc(int x)
{
    printf("customFunc\n");
    printf("argument is %d\n", x);
}

// Pointer to function
int addition(int x, int y)
{
    return x + y;
}
int subtraction(int x, int y)
{
    return x - y;
}

// Recursion to calculate factorial
int recursiveFunc(int x)
{
    if (x == 0)
    {
        return 1;
    }
    return x * recursiveFunc(x - 1);
}

// Inline functions
static inline int additionInline(int x, int y)
{
    return x + y;
}