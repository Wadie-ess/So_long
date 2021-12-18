#include "so_long.h"
#include <mlx.h>
#include "get_next_line.h"

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