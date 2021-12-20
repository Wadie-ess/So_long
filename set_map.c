/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessendo <wadieessendoubi@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:00:54 by oessendo          #+#    #+#             */
/*   Updated: 2021/12/20 18:22:24 by oessendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_set_map(t_data *data)
{
	int		fd;
	int		i;

	data->n_moves = 0;
	data->lines_count = 0;
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1 || ft_check_argument(data) == 0)
		return (0);
	ft_count_lines(data, fd);
	data->map = malloc(sizeof(char *) * (data->lines_count));
	if (!data->map)
		return (0);
	close(fd);
	i = -1;
	fd = open(data->map_path, O_RDONLY);
	while (++i < data->lines_count && data->map)
		data->map[i] = get_next_line(fd);
	close(fd);
	if (data->map)
		data->chars_count = ft_strlen(data->map[i - 1]);
	return (1);
}

void	ft_count_lines(t_data *data, int fd)
{
	char	*s;

	s = get_next_line(fd);
	while (s)
	{
		data->lines_count++;
		free(s);
		s = get_next_line(fd);
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[i + j])
		{
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}

int	ft_check_argument(t_data *data)
{
	if (ft_strstr(data->map_path, ".ber") == 0)
		return (0);
	return (1);
}
