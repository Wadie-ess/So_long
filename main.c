#include "so_long.h"
int main()
{

    int width;
    int height;

    int lines_count = ft_count_lines();
    int chars_count = ft_count_chars();
    height = lines_count * BLOCK_SIZE;
    width = chars_count * BLOCK_SIZE;
    void *mlx = mlx_init();
    void *mlx_window = mlx_new_window(mlx, width, height, "a7a");

    ft_draw_map(mlx, mlx_window);
    mlx_loop(mlx);

    return (0);
}