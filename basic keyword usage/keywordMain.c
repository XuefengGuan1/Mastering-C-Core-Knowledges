#include <stdio.h>
#include <stdlib.h>
#include "keywordUsage.h"

// This variable was defined in keywordUsage.c
extern int externalLinkage;

// Global variable but accessible within the entire program
int externalLinkage = 5;

int main()
{
    // Check externalLinkage value
    printf("what is my value %d\n", externalLinkage);

    // Creating a const value, trying to modify the const would create an error
    const int constVal = 5;
    printf("what is my constVal: %d\n", constVal);
    // ConstVal++;

    // Typedef practice
    typedef int i;
    i typedefI = 1;
    int normalInt = 2;
    printf("what is value using typedef: %d, what is the value using int: %d\n", typedefI, normalInt);

    // Pratice struct
    struct myStruct
    {
        int x;
        int y;
    } myStruct;
    struct myStruct mySmallStruct;
    mySmallStruct.x = 5;
    mySmallStruct.y = 6;
    printf("what is my struct values: %d, %d\n", mySmallStruct.x, mySmallStruct.y);

    // Pratice typedef on structs
    typedef struct myStruct2
    {
        int x;
        int y;
    } myStruct2;
    myStruct2 mySmallStruct2;
    mySmallStruct2.x = 7;
    mySmallStruct2.y = 8;
    printf("what is my struct2 with typedef values: %d, %d\n", mySmallStruct2.x, mySmallStruct2.y);

    // Pratice typedef on structs with pointers
    typedef struct myStruct3
    {
        int x;
        int y;
    } myStruct3;
    myStruct3 *mySmallStruct3 = (myStruct3 *)malloc(sizeof(mySmallStruct3));
    mySmallStruct3->x = 10;
    mySmallStruct3->y = 11;
    printf("what is my struct3 with typedef values: %d, %d\n", mySmallStruct3->x, mySmallStruct3->y);
    free(mySmallStruct3);
    mySmallStruct3 = NULL;

    // Union practice
    union myUnion
    {
        int x;
        int y;
    } myUnion;
    union myUnion mySmallUnion;
    mySmallUnion.x = 5;
    printf("what is my value of x: %d\n", mySmallUnion.x);
    mySmallUnion.y = 3;
    printf("what is my value of x after modifying y: %d, and whats the value of y: %d\n", mySmallUnion.x, mySmallUnion.y);

    // Sizeof practice, just simply check for the size of a variable
    printf("size of char, expected to be 1, actual value: %ld\n", sizeof(char));
    printf("size of int, expected to be 8 or 16 depend on the system, actual value: %ld\n", sizeof(int));

    // Enum practive
    enum Weekdays
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday
    };
    enum Weekdays today = Monday;
    switch (today)
    {
    case 0:
        printf("Monday\n");
        break;
    case 1:
        printf("Tueday\n");
        break;
    case 2:
        printf("Wednesday\n");
        break;
    case 3:
        printf("Thursday\n");
        break;
    case 4:
        printf("Friday\n");
        break;
    default:
        printf("Weekend!!\n");
    }

    // Pointer practice of * and &
    int someV = 5;
    int *someVPtr = &someV;
    printf("someV value: %d, someVPtr value: %d\n", someV, *someVPtr);
    someV++;
    printf("someV++, someV value: %d, someVPtr value: %d\n", someV, *someVPtr);

    // -> dereference and access value, used in struct
    struct myStruct4{
        int x;
    };
    struct myStruct4 *mySmallStruct4 = (struct myStruct4*) malloc(sizeof(struct myStruct4));
    mySmallStruct4->x =100;
    printf("Value of x in myStruct4, used ->: %d\n", mySmallStruct4->x);
    free(mySmallStruct4);
    mySmallStruct4 = NULL;

    // Keyword auto is useless, it just tells the compiler to automatically control its scope
    // In modern world auto is automatically applied to all variables

    // Regiter variable practice, but again, modern compilers usually ignore this keyword
    register int registerV = 5;
    
    return 0;
}