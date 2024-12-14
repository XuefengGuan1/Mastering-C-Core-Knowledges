#include <stdio.h>

int linearSearch(int *arr, int target, int size);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("the value is: %d\n", linearSearch(arr, 17, size));
    return 0;
}

int linearSearch(int *arr, int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return arr[i];
        }
    }
    return -1;
}