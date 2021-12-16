#include "so_long.h"
void	ft_move_player(t_data *data, int direction)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (direction == KEY_UP)
		i = -1;
	if (direction == KEY_DOWN)
		i = 1;
	if (direction == KEY_LEFT)
		j = -1;
	if (direction == KEY_RIGHT)
		j = 1;
	data->map[data->p_y][data->p_x] = '0';
	data->p_y += i;
	data->p_x += j;
/* 	if (data->map[data->p_y][data->p_x] == 'C')
		data->n_coins--;
	if (data->map[data->p_y][data->p_x] == 'E')
	{
		if (data->n_coins == 0)
		{
			mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
			exit(0);
		}
	} */
	data->map[data->p_y][data->p_x] = 'P';
	ft_draw_map(data);
}
int ft_move_hook(int keycode, t_data *data)
{
    // check if player can move
    ft_move_player(data, keycode);
    return (1);
    

}
int ft_hook(int keycode, t_data *data)
{
    if(keycode == KEY_ESC)
    {
        mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_window);
        exit(0);
    }
    if(keycode == KEY_DOWN)
        ft_move_hook(keycode, data);
    if(keycode == KEY_LEFT)
        ft_move_hook(keycode, data);
    if(keycode == KEY_RIGHT)
        ft_move_hook(keycode, data);
    if(keycode == KEY_UP)
        ft_move_hook(keycode, data);   


    return (0);
}