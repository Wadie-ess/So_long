#include "so_long.h"

///// put pixel dyali
/* typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;
 */

/* void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
} */
/* void ft_draw_img(void *mlx, void *mlx_window, char c, int i, int j)
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
} */

/* void ft_draw_map(void *mlx, void *mlx_window)
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
} */

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
   return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
}
