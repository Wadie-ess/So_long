#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
int ft_count_lines()
{
    int line_count;
    line_count = 0;
    int fd;
    fd = open("map.ber", O_RDONLY);
    while (get_next_line(fd) != NULL)
        line_count++;
    return line_count;
}

int main()
{

    int line_count;
    int colum_count;
    int i;
    int j;
    i = 0;
    int reded;
    line_count = ft_count_lines();
    //colum_count = ft_count_chars();
    int fd = open("map.ber", O_RDONLY);
     //int fd2 = open("map.ber", O_RDONLY);
    char **map;
    map = malloc(line_count * sizeof(char *));
    while (i < line_count)
    {   
        map[i] = get_next_line(fd);
        i++;
    }
    i = 0;

    while (i < line_count)
    {
        printf("%s",map[i]);
        i++;
    }
    
    printf("len dyal l file is %d", colum_count);
    printf("che7al mn star is %d", line_count);
}