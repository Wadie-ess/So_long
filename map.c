#include "get_next_line.h"
#include "so_long.h"

int ft_count_chars()
{
    int i;
    i = 0;
    int fd2;
    fd2 = open("maps/map.ber", O_RDONLY);
    i = ft_strlen(get_next_line(fd2));
    close(fd2);
    return i - 1;
}

int ft_count_lines()
{
    int line_count;
    line_count = 0;
    int fd;
    fd = open(MAP_PATH, O_RDONLY);
    while (get_next_line(fd))
        line_count++;
    close(fd);
    return line_count;
}
char **ft_getmap()
{
    char **map;
    int line_count;
    int fd;
    int i;
    i = 0;
    fd = open("maps/map.ber", O_RDONLY);
    line_count = ft_count_lines();
    map = malloc(line_count * sizeof(char *));
    while (i < line_count)
    {
        map[i] = get_next_line(fd);
        i++;
    }
    close(fd);
    return map;
}