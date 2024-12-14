// Implementation of strlen, strcpy, strcmp

#include <stdio.h>
#include <string.h>

int strLength(char *myStr);
void strCopy(char *dest, char *source);
int strComp(char *str1, char *str2);

int main()
{
    char myString[] = "hello";
    printf("string length is: %d\n", strLength(myString));

    char destString[10] = "";
    strCopy(destString, myString);
    printf("what is dest: %s, length of dest %d\n", destString, strLength(destString));

    char diffString[5] = "hell";
    char diffString2[7] = "hello";
    char diffString3[6] = "wello";
    strComp(myString, diffString);
    strComp(myString, diffString2);
    strComp(myString, diffString3);
    return 0;
}

int strLength(char *myStr)
{
    int curr = 0;

    while (myStr[curr] != '\0')
    {
        curr += 1;
    }
    return curr;
}

void strCopy(char *dest, char *source)
{
    memcpy(dest, source, strLength(source) + 1);
}

int strComp(char *str1, char *str2)
{
    if (strLength(str1) != strLength(str2))
    {
        printf("string not equal\n");
        return 1;
    }
    int currIndex = 0;
    for (int i = 0; i < strLength(str1) +1; i++){
        if(str1[i] != str2[i]){
            printf("string not equal\n");
            return 1;
        }
    }

    printf("equal!\n");
    return 0;
}