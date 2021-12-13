#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
    int line_count = 1;
    int fd = open("map.ber", O_RDONLY);
    int colum_count = strlen(get_next_line(fd));
    printf("len dyal l file is %d", colum_count);
    while (get_next_line(fd) != NULL)
    {
        line_count++;
    }
    printf("che7al mn star is %d", line_count);
}