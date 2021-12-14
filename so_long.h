#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>

# define BUFFER_SIZE 100
# define SOPU "assets/sopo_1.xpm"
# define SPODY "assets/spopi_1.xpm"
# define WALL "assets/wall.xpm"
# define BACKGROUND "assets/background.xpm"
# define MAP_PATH "maps/map.ber"
# define BLOCK_SIZE 50



int ft_count_chars();
int ft_count_lines();
char **ft_getmap();


typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}t_mlx;

typedef struct s_game
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
}t_game;

#endif