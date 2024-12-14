// Matrix multiplication

// Malloc in matrix creation ->row ->col

#include <stdio.h>
#include <stdlib.h>

#define ROW_MAX 5
#define COL_MAX 5

int **matrixCreation(int row, int col);
void **matrixInit(int **myMat, int row, int col);
void **matrixPrint(int **myMat, int row, int col);

int **matrixMulti(int **matrix1, int **matrix2);

int main()
{
    int **myMat1 = matrixCreation(ROW_MAX, COL_MAX);
    int **myMat2 = matrixCreation(ROW_MAX, COL_MAX);
    matrixInit(myMat1, ROW_MAX, COL_MAX);
    matrixInit(myMat2, ROW_MAX, COL_MAX);

    matrixPrint(myMat1, ROW_MAX, COL_MAX);

    return 0;
}

int **matrixCreation(int row, int col)
{
    int **myMat = (int **)malloc(sizeof(int *) * row);
    if (myMat == NULL)
    {
        printf("ALlocation faile");
        exit(-1);
    }
    for (int i = 0; i < row; i++)
    {
        myMat[i] = (int *)malloc(sizeof(int) * col);
        if (myMat[i] == NULL)
        {
            printf("ALlocation faile");
            exit(-1);
        }
    }
    return myMat;
}

void **matrixInit(int **myMat, int row, int col)
{
    int increaseNum = 1;
    for (int curRow = 0; curRow < row; curRow++)
    {
        for (int curCol = 0; curCol < col; curCol++)
        {
            myMat[curRow][curCol] = increaseNum;
            increaseNum++;
        }
    }
}

void **matrixPrint(int **myMat, int row, int col)
{
    int increaseNum = 1;
    printf("printing the matrix: \n");
    for (int curRow = 0; curRow < row; curRow++)
    {
        for (int curCol = 0; curCol < col; curCol++)
        {
            printf("%d ", myMat[curRow][curCol]);
        }
        printf("\n");
    }
}

int **matrixMulti(int **matrix1, int **matrix2){
    
}