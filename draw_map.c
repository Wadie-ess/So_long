#include "so_long.h"

void ft_draw_img(t_game *game, char c, int i, int j)
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

    img = mlx_xpm_file_to_image(game->mlx->mlx, file, &w, &h);
    w = BLOCK_SIZE * i;
    h = BLOCK_SIZE * j;
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->mlx_window, img, w, h);
    mlx_destroy_image(game->mlx->mlx, img);
}

void ft_draw_map(t_game *game)
{
    int i = -1;
    int j = 0;
    char **map;
    int lines_count = game->lines_count;
    int chars_count = game->chars_count;
    map = game->map;
    mlx_clear_window(game->mlx->mlx, game->mlx->mlx_window);
    while (++i < lines_count)
    {
        j = -1;
        while (++j < chars_count)
            ft_draw_img(game, map[i][j], j, i);
    }
}