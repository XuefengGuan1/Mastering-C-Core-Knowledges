#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{

    // File operation using low-level file I/O open, read, write, close
    int fd;
    char myBuf[16];
    int position = 0;
    char destination[2000] = {0};
    int advanceV = 0;
    fd = open("myFile.txt", O_RDWR | O_APPEND);
    while ((advanceV = read(fd, myBuf, 16)) > 0)
    {
        memcpy(destination + position, myBuf, advanceV);
        position += advanceV;
    }
    destination[position] = '\0';
    // write(fd, "new content", 11);
    printf("%s\n", destination);
    close(fd);

    // File operation using high-level file I/O, fopen, fread, fwrite, fclose
    printf("fopen, fread, fwrite, fclose starts\n");
    FILE *myF;
    char myBuf2[16];
    char destination2[2000] = {0};
    int advanceV2 = 0;
    int position2 = 0;

    myF = fopen("myFile.txt", "r");
    while ((advanceV2 = fread(myBuf2, 1, 16, myF)) > 0)
    {
        memcpy(destination2 + position2, myBuf2, advanceV2);
        position2 += advanceV2;
    }
    destination2[position2] = '\0';
    printf("%s\n", destination2);
    fclose(myF);
}