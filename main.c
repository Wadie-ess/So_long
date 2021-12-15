#include "so_long.h"
#include <mlx.h>
#include "get_next_line.h"
void ft_set_map(char *map_path, t_data *data)
{
    int fd;
    int i;
    int lines_count;

    lines_count = 0;
    fd = open(map_path, O_RDONLY);
    while (get_next_line(fd))
        lines_count++;
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
    t_data *data;
    t_mlx *mlx;
    int window_width;
    int window_height;
    data = malloc(sizeof(t_data));
    mlx = malloc(sizeof(t_mlx));
    ft_set_map(MAP_PATH, data);
    window_height = data->lines_count * BLOCK_SIZE;
    window_width = data->chars_count * BLOCK_SIZE;
    mlx->mlx = mlx_init();
    mlx->mlx_window = mlx_new_window(mlx->mlx, window_width, window_height, "a7a");
    data->mlx = mlx;

    ft_draw_map(data);
    mlx_loop(mlx->mlx);

    return (0);
}