// Reverse int array in place
#include <stdio.h>
void reverseArr(int *arr, int size);

int main()
{
    int myArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11};
    int size = sizeof(myArr) / sizeof(myArr[0]);
    reverseArr(myArr, size);
    for(int i = 0; i < size; i++){
        printf(" %d",myArr[i]);
    }
    printf("\n");
    return 0;
}

void reverseArr(int *arr, int size)
{
    int *left = arr;
    int *right = arr + size - 1;
    while (left < right)
    {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
        
        left++;
        right--;
    }
}