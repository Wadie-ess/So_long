/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessendo <wadieessendoubi@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:09:54 by oessendo          #+#    #+#             */
/*   Updated: 2021/12/20 13:29:15 by oessendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_img(t_data *data, char c, int i, int j)
{
	int		h;
	int		w;
	void	*img;
	char	*file;

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
		file = EXTI;
	img = mlx_xpm_file_to_image(data->mlx, file, &w, &h);
	w = BLOCK_SIZE * i;
	h = BLOCK_SIZE * j;
	mlx_put_image_to_window(data->mlx, data->mlx_window, img, w, h);
	mlx_destroy_image(data->mlx, img);
}

void	ft_draw_map(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map;
	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
			ft_draw_img(data, map[i][j], j, i);
	}
}
