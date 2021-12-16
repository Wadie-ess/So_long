#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53
# define BUFFER_SIZE 100
# define SOPU "assets/sopo_1.xpm"
# define SPODY "assets/spopi_1.xpm"
# define WALL "assets/wall.xpm"
# define BACKGROUND "assets/background.xpm"
# define MAP_PATH "maps/map.ber"
# define BLOCK_SIZE 50






typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}t_mlx;

typedef struct s_data
{
	char	**map;
	int		move_count;
	int		lines_count;
	int		chars_count;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		n_coins;
	t_mlx	*mlx;
}t_data;

int ft_count_chars();
int ft_count_lines();
void ft_draw_map(t_data *data);
char **ft_getmap();
int validate_map(t_data *data);
int	validate_map_player(t_data *data);
int ft_move_hook(int keycode, t_data *data);
int ft_hook(int keycode, t_data *data);
void	ft_move_player(t_data *data, int direction);

#endif