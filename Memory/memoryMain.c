#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strCopy(char*);

int main(){
    // Using return value from malloc.
    char* strPtr = strCopy("hello");
    printf("%s\n",strPtr);
    free(strPtr);
    strPtr = NULL;
    
    // use Calloc to allocate space of a size 5 array and initialize everything to 0
    int* callocPtr = (int*) calloc (5, sizeof(int));

    return 0;
}

// Use dynamic allocation create a new string and add '!' at the end of a string
char* strCopy(char* originalStr){
    int strLen = strlen(originalStr);
    char* newStr = (char*) malloc(sizeof(char) * strLen + 2);
    strcpy(newStr, originalStr);
    newStr[strLen] = '!';
    newStr[strLen+1] = '\0';
    return newStr;
}