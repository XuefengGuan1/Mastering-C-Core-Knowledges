// Implement circular buffer

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 11

typedef struct CirBuffer
{
    int arr[MAX];
    int front; // Pop
    int rear;  // Insert
    pthread_mutex_t myMutex;
} CirBuffer;

void enqueue(CirBuffer *myBuffer, int value);
void dequeue(CirBuffer *myBuffer);
void checkFull(CirBuffer *myBuffer);
void checkEmpty(CirBuffer *myBuffer);

CirBuffer *queueInit();
void printQ(CirBuffer *myBuffer);

void *threadFunc(void *myBuffer);

int main()
{
    CirBuffer *myBuffer = queueInit();

    // Thread, mutex creation
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, threadFunc, (void *)myBuffer);
    pthread_create(&thread2, NULL, threadFunc, (void *)myBuffer);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printQ(myBuffer);
    pthread_mutex_destroy(&(myBuffer->myMutex));
    // free
    free(myBuffer);
    myBuffer = NULL;
    return 0;
}

CirBuffer *queueInit()
{
    CirBuffer *myQ = (CirBuffer *)malloc(sizeof(CirBuffer));
    if (myQ == NULL)
    {
        printf("allocation failed");
        exit(-1);
    }
    pthread_mutex_init(&(myQ->myMutex), NULL);
    myQ->front = 0;
    myQ->rear = 0;

    return myQ;
}

void enqueue(CirBuffer *myBuffer, int value)
{
    pthread_mutex_lock(&(myBuffer->myMutex));
    if ((myBuffer->rear + 1) % MAX == myBuffer->front)
    {
        return;
    }
    myBuffer->arr[myBuffer->rear] = value;
    myBuffer->rear = (myBuffer->rear + 1) % MAX;
    pthread_mutex_unlock(&(myBuffer->myMutex));
    printf("%d enqueued\n", value);
}

void dequeue(CirBuffer *myBuffer)
{
    if (myBuffer->front == myBuffer->rear)
    {
        printf("queue is empty\n");
        return;
    }
    myBuffer->front = (myBuffer->front + 1) % MAX;
}

void checkFull(CirBuffer *myBuffer)
{
    if ((myBuffer->rear + 1) % MAX == myBuffer->front)
    {
        printf("list is full\n");
        return;
    }
    printf("queue not full\n");
}

void checkEmpty(CirBuffer *myBuffer)
{
    if (myBuffer->front == myBuffer->rear)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue empty\n");
}

void printQ(CirBuffer *myBuffer)
{
    int currIndex = myBuffer->front;
    while (currIndex != myBuffer->rear)
    {
        printf("%d ", myBuffer->arr[currIndex]);
        currIndex = (currIndex + 1) % MAX;
    }
    printf("\n");
}

void *threadFunc(void *arg)
{
    CirBuffer *myBuffer = (CirBuffer *)arg;
    enqueue(myBuffer, 1);
    enqueue(myBuffer, 2);
    enqueue(myBuffer, 3);
    enqueue(myBuffer, 4);
    enqueue(myBuffer, 5);
    
    return NULL;
}