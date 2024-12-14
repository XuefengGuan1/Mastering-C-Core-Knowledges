#include <stdio.h>

// Queue, binary tree, binary search tree

// Circular Queue implementation with array
// Only supports insert and pop
#define MAX_SIZE 100
typedef struct MyQ
{
    int queueArray[MAX_SIZE];
    int frontIndex;
    int rearIndex;
} MyQ;

MyQ *queueCreation(MyQ *);
MyQ *queueInsert(MyQ *, int);
MyQ *queuePop(MyQ *);

int main()
{
    MyQ *myQ = (MyQ*) malloc(sizeof(MyQ));
    myQ = queueCreation(myQ);

    myQ = queueInsert(myQ, 5);
    myQ = queuePop(myQ);

    free(myQ);
    myQ = NULL;
    return 0;
}

MyQ *queueCreation(MyQ *q)
{
    q->frontIndex = 0;
    q->rearIndex = 0;
    return q;
}

MyQ *queueInsert(MyQ *q, int value)
{
    if((q->rearIndex+1) % MAX_SIZE == q->frontIndex){
        printf("queue full\n");
        return q;
    }
    q->queueArray[q->rearIndex] = value;
    q->rearIndex = (q->rearIndex+1)%100;
    return q;
}

MyQ *queuePop(MyQ *q)
{
    if(q->rearIndex == q->frontIndex){
        printf("queue is already empty");
        return q;
    }
    q->frontIndex = (q->frontIndex +1)%100;

    return q;
}