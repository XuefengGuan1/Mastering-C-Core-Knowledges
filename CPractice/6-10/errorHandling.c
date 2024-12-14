// File copy operation

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;

    // char buf[1024];
    fd = open("./errorHandlingText.txt", O_RDWR);
    if(fd == -1){
        printf("File open failed\n");
        return -1;
    }
    int fileSize = lseek(fd, 0, SEEK_END);
    if(fileSize == -1){
        printf("can't navigate through file\n");
    }
    int checkReturn = lseek(fd, 0, SEEK_SET);
    if(checkReturn == -1){
        printf("can't reset file pointer\n");
    }

    char *fileContent = (char *)malloc(sizeof(char) * fileSize + 1);
    if(fileContent == NULL){
        printf("malloc failed\n");
        return -1;
    }
    int charsRead = read(fd, fileContent, fileSize);
    if(charsRead == -1){
        printf("file reading failed\n");
    }
    fileContent[fileSize] = '\0';

    printf("printing file content:\n %s\n", fileContent);

    checkReturn = write(fd, "adding", 6);
    if(checkReturn == -1){
        printf("write failed\n");
        return -1;
    }
    free(fileContent);
    fileContent = NULL;
    return 0;
}