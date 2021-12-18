#include "so_long.h"
#include "get_next_line.h"
void ft_set_map(char *map_path, t_data *data)
{
    int fd;
    int i;
    int lines_count;
    char    *s;
    data->n_moves = 0;
    lines_count = 0;
    fd = open(map_path, O_RDONLY);
    s = get_next_line(fd);
    while (s)
    {
        lines_count++;
        free(s);
        s = get_next_line(fd);
    }
        
    data->map = malloc(sizeof(char *) * (lines_count));
    close(fd);
    i = -1;
    fd = open(map_path, O_RDONLY);
    while (++i < lines_count && data->map)
        data->map[i] = get_next_line(fd);
    close(fd);
    data->lines_count = lines_count;
    if (data->map)
        data->chars_count = ft_strlen(data->map[i - 1]);
}
