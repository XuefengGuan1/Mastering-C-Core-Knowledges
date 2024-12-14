// Hashtable implementation with arrray and linear probing

// myHash malloc, myHash name malloc
#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 1000

typedef struct HashItems
{
    char *name;
    int value;
    int isOccupied; // 0 for NOT occupied, 1 for occupied
} HashItems;

typedef struct HashtableArray
{
    HashItems myArr[TABLE_SIZE];
} HashtableArray;

HashtableArray *hashInit();
int hashing(char *name);
void checkExistance(char* name);
void insertValue(int value, char *name, HashtableArray *myHash);
void deleteValue(int value, char *name, HashtableArray *myHash);

int main()
{
    HashtableArray *myHash = hashInit();
    insertValue(1, "tony", myHash);
    insertValue(1, "tony", myHash);
    deleteValue(5, "jennifer", myHash);

    free(myHash);
    myHash = NULL;
    return 0;
}

HashtableArray *hashInit()
{
    HashtableArray *myHash = (HashtableArray *)malloc(sizeof(HashtableArray));

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        myHash->myArr[i].isOccupied = 0;
        myHash->myArr[i].value = 0;
        myHash->myArr[i].name = NULL;
    }
    return myHash;
}

int hashing(char *name)
{
    int hashNum = 5381;
    int charValule;
    while ((charValule = *name++) != 0)
    {
        hashNum = (hashNum << 5) + hashNum + charValule;
    }
    return hashNum % TABLE_SIZE;
}
void insertValue(int value, char *name, HashtableArray *myHash)
{
    int position = hashing(name);
    while (myHash->myArr[position].isOccupied == 1)
    {
        position++;
    }
    myHash->myArr[position].isOccupied = 1;
    myHash->myArr[position].name = strdup(name);
    myHash->myArr[position].value = value;
}
void deleteValue(int value, char *name, HashtableArray *myHash)
{
    int position = hashing(name);
    int initPosition = position;
    while (strcmp(myHash->myArr[position].name, name) != 0)
    {
        if(hashing(myHash->myArr[position].name) != initPosition){
            printf("the target value is not found in the hashtable\n");
            return;
        }
        position++;
    }
    myHash->myArr[position].isOccupied = 0;
}
