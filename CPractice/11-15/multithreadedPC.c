// Circular multithread-safe buffer

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 16

typedef struct MyQu
{
    int myArr[MAX];
    int front; // pop
    int rear;  // insert
    pthread_mutex_t myMut;
} MyQu;

MyQu *initQ();
void insertQ(int value, MyQu *myQ);
void popQ(MyQu *myQ);
void printQ(MyQu *myQ);

void *consumerFunc(void *arg);
void *producerFunc(void *arg);

int main()
{
    // init thread, init mutex
    // create thread(to start the thread)
    // write a thread function
    //  protect critical area with mutex
    // free, destroy, join all the extra data
    pthread_t producer;
    pthread_t comsumer;
    MyQu *myQ = initQ();

    pthread_create(&producer, NULL, producerFunc, (void *)myQ);
    pthread_create(&comsumer, NULL, consumerFunc, (void *)myQ);

    pthread_join(producer, NULL);
    pthread_join(comsumer, NULL);

    printQ(myQ);

    // Clean up
    pthread_mutex_destroy(&(myQ->myMut));
    free(myQ);
    myQ = NULL;
}

MyQu *initQ()
{
    MyQu *newQ = (MyQu *)malloc(sizeof(MyQu));
    newQ->front = 0;
    newQ->rear = 0;
    pthread_mutex_init(&(newQ->myMut), NULL);
    return newQ;
}

void insertQ(int value, MyQu *myQ)
{
    pthread_mutex_lock(&(myQ->myMut));
    if ((myQ->rear + 1) % MAX == myQ->front)
    {
        pthread_mutex_unlock(&(myQ->myMut));
        printf("the queue is full\n");
        return;
    }
    myQ->myArr[myQ->rear] = value;
    myQ->rear = (myQ->rear + 1) % MAX;
    pthread_mutex_unlock(&(myQ->myMut));
    return;
}

void popQ(MyQu *myQ)
{
    pthread_mutex_lock(&(myQ->myMut));
    if (myQ->rear == myQ->front)
    {
        pthread_mutex_unlock(&(myQ->myMut));
        // empty
        printf("the queue is empty\n");
        return;
    }
    myQ->front = (myQ->front + 1) % MAX;
    pthread_mutex_unlock(&(myQ->myMut));
    return;
}

void printQ(MyQu *myQ)
{
    int curr = myQ->front;
    while (curr < myQ->rear)
    {
        printf("%d ", myQ->myArr[curr]);
        curr = (curr + 1) % MAX;
    }
    printf("\n");
}

void *producerFunc(void *arg)
{
    MyQu *myQ = (MyQu *)arg;
    for (int i = 0; i < 100; i++)
    {
        printf("proucer\n");
        sleep(1);
        insertQ(i, myQ);
    }
    return NULL;
}

void *consumerFunc(void *arg)
{
    MyQu *myQ = (MyQu *)arg;
    for (int i = 0; i < 5; i++)
    {
        printf("comsumer\n");
        sleep(1);
        popQ(myQ);
    }
    return NULL;
}
