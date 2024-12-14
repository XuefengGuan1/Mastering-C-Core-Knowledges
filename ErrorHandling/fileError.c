#include <stdio.h>
#include <errno.h>
#include <fcntl.h>  //open close
#include <unistd.h> //read write
#include <string.h>

int main()
{
    int fd;
    char buf[100];
    if ((fd = open("./text.txt", O_RDONLY)) == -1)
    {
        printf("Error opening: %s\n", strerror(errno));
        return -1;
    }

    if (read(fd, buf, 99) == -1)
    { 
        printf("Error opening: %s\n", strerror(errno));
        return -1;
    }
    printf("what is the file content: %s\n",buf);

    return 0;
}