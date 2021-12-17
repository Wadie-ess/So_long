#include "so_long.h"
#include <mlx.h>
#include "get_next_line.h"
void ft_set_map(char *map_path, t_data *data)
{
    int fd;
    int i;
    int lines_count;
    char    *s;

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

int main()
{
    t_data data;
    int window_width;
    int window_height;
   
    ft_set_map(MAP_PATH, &data);
       if(validate_map(&data) == 0)
        return 0;
    window_height = data.lines_count * BLOCK_SIZE;
    window_width = data.chars_count * BLOCK_SIZE;
    //printf("%d",data->p_y);
     data.mlx = mlx_init();
    data.mlx_window = mlx_new_window(data.mlx, window_width, window_height, "a7a");
    mlx_hook(data.mlx_window, 2, 1L << 0, ft_hook, &data);
    ft_draw_map(&data);
    mlx_loop(data.mlx); 

    return (0);
}