// In memory Database, a hashtable?

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ARR_MAX 1024
#define KEY_MAX 16

typedef struct Item
{
    char key[KEY_MAX];
    int value;
    bool occupied;
} Item;

typedef struct HashTab
{
    Item arr[ARR_MAX];
} HashTab;

HashTab *hashInit();
int hashingAlgo(char *key);
void hashInsert(char *key, int value, HashTab *myHash);
void hashDelete(char *key, HashTab *myHash);

int main()
{
    HashTab *myHash = hashInit();
    hashInsert("hello", 10, myHash);
    hashInsert("wello", 5, myHash);
    hashDelete("hi", myHash);
    hashDelete("wello", myHash);

    // Clean up
    free(myHash);
    myHash = NULL;
    return 0;
}

HashTab *hashInit()
{
    HashTab *newHash = (HashTab *)malloc(sizeof(HashTab));
    if (newHash == NULL)
    {
        printf("malloc failed");
        exit(-1);
    }
    for (int i = 0; i < ARR_MAX; i++)
    {
        newHash->arr[i].occupied = false;
    }
    return newHash;
}

// DJB2
int hashingAlgo(char *key)
{
    int hashNum = 5381;
    int charVal;
    while (charVal = *key++)
    {
        hashNum = ((hashNum << 5) + hashNum + charVal) % ARR_MAX;
    }
    return hashNum;
}

void hashInsert(char *key, int value, HashTab *myHash)
{
    int hashNum = hashingAlgo(key);
    while (myHash->arr[hashNum].occupied == true)
    {
        hashNum++;
    }
    strcpy(myHash->arr[hashNum].key, key);
    myHash->arr[hashNum].value = value;
    myHash->arr[hashNum].occupied = true;
}

void hashDelete(char *key, HashTab *myHash)
{
    int hashNum = hashingAlgo(key);
    int initialHashNum = hashNum;
    while (myHash->arr[hashNum].occupied == true)
    {
        if (strcmp(myHash->arr[hashNum].key, key) == 0)
        {
            myHash->arr[hashNum].occupied = false;
            printf("the key %s is deleted!\n", key);
            return;
        }
        hashNum++;
        if (hashNum == initialHashNum)
        {
            printf("the key you specified wasn't found\n");
            return;
        }
    }
}