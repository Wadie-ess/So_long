#include "so_long.h"
int validate_map(t_data *data)
{
    if(!validate_map_player(data))
        return 0;
    return 1;
}
int	validate_map_player(t_data *data)
{
	int	n_player;
	int	i;
	int	j;

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