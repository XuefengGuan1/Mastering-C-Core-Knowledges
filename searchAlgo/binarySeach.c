#include <stdio.h>

int binarySearch(int target, int *arr, int size);

int main()
{
    int myArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int size = sizeof(myArr) / sizeof(myArr[0]);

    printf("value is: %d\n", binarySearch(5, myArr, size));
    return 0;
}

// Return -1 if not found
// Return anything other than -1 means found
int binarySearch(int target, int *arr, int size)
{
    int mid;
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        printf("what is my mid %d\n", mid);

        if (target == mid)
        {
            return mid;
        }
        else if (target < mid)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}