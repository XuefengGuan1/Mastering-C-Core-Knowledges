// Dynamically allocate space for a matrix

#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COLUMN 10

int main()
{
    // Allocate number of rows
    int **myMatrix = (int **)malloc(sizeof(int *) * ROW);
    if (myMatrix == NULL){
        printf("allocation failed\n");
        return -1;
    }
    for (int i = 0; i < ROW; i++)
    {
        myMatrix[i] = (int *)malloc(sizeof(int) * COLUMN);
        if (myMatrix[i] == NULL){
            printf("allocation failed\n");
            return -1;
        }
    }
    int value = 0;
    for (int rowIndex = 0; rowIndex < ROW; rowIndex++)
    {
        for (int ColIndex = 0; ColIndex < COLUMN; ColIndex++)
        {
            myMatrix[rowIndex][ColIndex] = value;
            value++;
        }
    }

    // Print matrix
    for (int rowIndex = 0; rowIndex < ROW; rowIndex++)
    {
        for (int ColIndex = 0; ColIndex < COLUMN; ColIndex++)
        {
            printf("%d ", myMatrix[rowIndex][ColIndex]);
        }
        printf("\n");
    }
    

    // Free Matrix
    for (int i = 0; i < ROW; i++)
    {
        free(myMatrix[i]);
        myMatrix[i] = NULL;
    }
    free(myMatrix);
    myMatrix = NULL;
}