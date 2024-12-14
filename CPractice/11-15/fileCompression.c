// Compress the file with RLE

#include <stdio.h>
#include <unistd.h> //read, write
#include <fcntl.h>  //open, close
#include <stdlib.h> //malloc, free
#include <string.h> //string manipulations

int fileCompress(char *originalFile, char *compressedText);

int main()
{
    int fd;
    fd = open("./fileToCompress.txt", O_RDWR);
    if (fd == -1)
    {
        printf("File open failed\n");
        return -1;
    }

    int fileSize;
    fileSize = lseek(fd, 0, SEEK_END);
    if (fileSize == -1)
    {
        printf("traversing through the file failed\n");
        return -1;
    }
    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        printf("Moving file pointer to the front failed\n");
        return -1;
    }

    char *fileContent = (char *)malloc(sizeof(char) * fileSize + 1);
    int bytesRead = read(fd, fileContent, fileSize);
    if (bytesRead == -1)
    {
        printf("read file failed\n");
        return -1;
    }
    char *compressedData = (char *)malloc(sizeof(char) * fileSize * 2);

    int compressedLength = fileCompress(fileContent, compressedData);

    int fdOut;
    fdOut = open("./compressedFile.txt", O_WRONLY);
    if (fdOut == -1)
    {
        printf("opening file to write failed\n");
        return -1;
    }

    if (write(fdOut, compressedData, compressedLength-1) == -1)
    {
        printf("write failed \n");
        return -1;
    }

    // Clean up
    free(fileContent);
    free(compressedData);
    fileContent = NULL;
    compressedData = NULL;

    close(fd);
    close(fdOut);

    return 0;
}

int fileCompress(char *originalFile, char *compressedText)
{
    // new char, dup char, empty char
    int currIndex = 0;
    char currChar = 0;
    int dupCounter = 0;
    int compressedLength = 0;

    while (originalFile[currIndex] != '\0')
    {
        if (currChar == 0)
        {
            currChar = originalFile[currIndex];
            dupCounter++;
        }
        else if (originalFile[currIndex] == currChar)
        {
            dupCounter++;
        }
        else
        {
            compressedLength += sprintf(compressedText + compressedLength, "%d%c", dupCounter, currChar);

            currChar = originalFile[currIndex];
            dupCounter = 1;
        }
        currIndex++;
    }
    char endline = '\0';
    compressedLength += sprintf(compressedText + compressedLength + endline, "%d%c%c", dupCounter, currChar, '\0');
    printf("stringLength %ld\n, my counter? %d\n", strlen(compressedText), compressedLength);
    printf("what is my string %s\n", compressedText);

    return compressedLength;
}