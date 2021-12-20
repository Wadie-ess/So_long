/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessendo <wadieessendoubi@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:30:18 by oessendo          #+#    #+#             */
/*   Updated: 2021/12/20 14:58:18 by oessendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data		data;
	int			window_width;
	int			window_height;

	if (argc != 2)
	{
		printf("The Number of arguments is incorrect\n");
		return (0);
	}
	data.map_path = argv[1];
	if (ft_set_map(&data) == 0)
		printf("map not exist! ");
	if (validate_map(&data) == 0)
		return (0);
	window_height = data.lines_count * BLOCK_SIZE;
	window_width = data.chars_count * BLOCK_SIZE;
	data.mlx = mlx_init();
	data.mlx_window
		= mlx_new_window(data.mlx, window_width, window_height, "a7a");
	mlx_hook(data.mlx_window, 2, 0, ft_hook, &data);
	mlx_hook(data.mlx_window, 17, 0, ft_destroy, &data);
	ft_draw_map(&data);
	mlx_loop(data.mlx);
	return (0);
}
