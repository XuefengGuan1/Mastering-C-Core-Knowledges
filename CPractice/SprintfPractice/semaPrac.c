#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#define MAX_THREAD 5

sem_t mySem;

void* myThread(void* arg);

int main()
{
    sem_init(&mySem, 0, 3);

    pthread_t thread[MAX_THREAD];

    for (int i = 0; i < MAX_THREAD; i++)
    {
        int *index = &i;
        pthread_create(&thread[i], NULL, myThread, (void *)index);
    }

    for (int i = 0; i < MAX_THREAD; i++)
    {
        pthread_join(thread[i], NULL);
    }
    sem_destroy(&mySem);

    return 0;
}

void *myThread(void *arg)
{

    sem_wait(&mySem);
    printf("thread is currently in the critical section\n");

    sleep(5);
    printf("exiting\n");
    sem_post(&mySem);
    return NULL;
}