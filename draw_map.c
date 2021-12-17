#include "so_long.h"

void ft_draw_img(t_data *data, char c, int i, int j)
{
 
    int h;
    int w;
    void *img;
    char *file;
    file = NULL;
    if (c == 'P')
        file = SPODY;
    if (c == 'C')
        file = SOPU;
    if (c == '0')
        file = BACKGROUND;
    if (c == '1')
        file = WALL;
    if (c == 'E')
        file = WALL;

    img = mlx_xpm_file_to_image(data->mlx, file, &w, &h);
    w = BLOCK_SIZE * i;
    h = BLOCK_SIZE * j;
    mlx_put_image_to_window(data->mlx, data->mlx_window, img, w, h);
    mlx_destroy_image(data->mlx, img);
}

void ft_draw_map(t_data *data)
{
    int i = -1;
    int j = 0;
    char **map;
    int lines_count = data->lines_count;
    int chars_count = data->chars_count;
    map = data->map;
    mlx_clear_window(data->mlx, data->mlx_window);
    while (++i < lines_count)
    {
        j = -1;
        while (++j < chars_count)
            ft_draw_img(data, map[i][j], j, i);
    }
}