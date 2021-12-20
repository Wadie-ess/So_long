/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_spody.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessendo <wadieessendoubi@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:45:32 by oessendo          #+#    #+#             */
/*   Updated: 2021/12/20 22:24:13 by oessendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_data *data, int direction)
{
	int	i;
	int	j;

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
	if (data->map[data->p_y][data->p_x] == 'C')
				data->n_coins--;
	if (data->map[data->p_y][data->p_x] == 'E')
	{
		if (data->n_coins == 0)
			ft_destroy(data);
	}
	data->map[data->p_y][data->p_x] = 'P';
	ft_draw_map(data);
}

int	ft_can_move(int keycode, t_data *data)
{
	if (keycode == KEY_RIGHT)
	{
		if (data->map[data->p_y][data->p_x + 1] == '1'
		|| (data->map[data->p_y][data->p_x + 1] == 'E' && data->n_coins > 0))
			return (0);
	}
	if (keycode == KEY_LEFT)
	{
		if (data->map[data->p_y][data->p_x - 1] == '1'
		|| (data->map[data->p_y][data->p_x - 1] == 'E' && data->n_coins > 0))
			return (0);
	}
	if (keycode == KEY_UP)
	{
		if (data->map[data->p_y - 1][data->p_x] == '1'
		|| (data->map[data->p_y - 1][data->p_x] == 'E' && data->n_coins > 0))
			return (0);
	}
	if (keycode == KEY_DOWN)
	{
		if (data->map[data->p_y + 1][data->p_x] == '1'
		|| (data->map[data->p_y + 1][data->p_x] == 'E' && data->n_coins > 0))
			return (0);
	}
	return (1);
}

int	ft_move_hook(int keycode, t_data *data)
{
	if (ft_can_move(keycode, data) == 1)
	{
		ft_move_player(data, keycode);
		data->n_moves++;
		printf("%d\n", data->n_moves);
	}
	return (1);
}

int	ft_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
		exit(0);
	}
	if (keycode == KEY_DOWN)
		ft_move_hook(keycode, data);
	if (keycode == KEY_LEFT)
		ft_move_hook(keycode, data);
	if (keycode == KEY_RIGHT)
		ft_move_hook(keycode, data);
	if (keycode == KEY_UP)
		ft_move_hook(keycode, data);
	return (0);
}

int	ft_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_window);
	exit(0);
	return (0);
}
