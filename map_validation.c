#include "so_long.h"
int validate_map(t_data *data)
{
	if (!validate_map_player(data) || !ft_check_border(data))
		return 0;
	return 1;
}
int ft_check_border(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		if (i == 0 || i == data->lines_count - 1)
		{

			while (++j < data->chars_count)
			{
				if (data->map[i][j] != '1')
					return (0);
			}
		}
		if (data->map[i][0] != '1')
			return (0);
		if (data->map[i][data->chars_count - 1] != '1')
			return (0);
	}

	return (1);
}
int validate_map_player(t_data *data)
{
	int n_player;
	int i;
	int j;

	n_player = 0;
	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
		{
			if (data->map[i][j] == 'P')
			{
				n_player++;
				data->p_x = j;
				data->p_y = i;
			}
		}
	}
	if (n_player == 1)
		return (1);
	else
		return (0);
}
int ft_check_map_shape(t_data *data)
{
	int i;
	i = 0;
	while (++i < data->lines_count - 1)
	{
		if (data->chars_count != ft_strlen(data->map[i]) - 1)
			return (0);
	}
	if (data->chars_count != ft_strlen(data->map[data->lines_count - 1]))
			return (0);
	return (1);
}

// test
  int main()
{
	t_data data;
	ft_set_map(MAP_PATH, &data);
	printf("%d", ft_check_map_shape(&data));
	return 0;
}  