#include "so_long.h"
void ft_draw_img(void *mlx, void *mlx_window, char c, int i, int j)
{
    t_game *game;
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

    img = mlx_xpm_file_to_image(mlx, file, &w, &h);
    w = BLOCK_SIZE * i;
    h = BLOCK_SIZE * j;
    mlx_put_image_to_window(mlx, mlx_window, img, w, h);
    mlx_destroy_image(mlx, img);
}

void ft_draw_map(void *mlx, void *mlx_window)
{
    int i = -1;
    int j = 0;
    char **map;
    int lines_count = ft_count_lines();
    int chars_count = ft_count_chars();
    map = ft_getmap();
    mlx_clear_window(mlx, mlx_window);
    while (++i < 4)
    {
        j = -1;
        while (++j < 13)
            ft_draw_img(mlx, mlx_window, map[i][j], j, i);
    }
}