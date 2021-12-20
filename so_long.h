/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessendo <wadieessendoubi@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:41:22 by oessendo          #+#    #+#             */
/*   Updated: 2021/12/20 22:55:29 by oessendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53
# define BUFFER_SIZE 1
# define SOPU "assets/sopo_1.xpm"
# define SPODY "assets/spopi_1.xpm"
# define WALL "assets/wall.xpm"
# define EXTI "assets/exit.xpm"
# define BACKGROUND "assets/background.xpm"
# define BLOCK_SIZE 50

typedef struct s_data
{
	char	**map;
	int		move_count;
	int		lines_count;
	int		chars_count;
	int		p_x;
	int		p_y;
	int		n_coins;
	int		n_moves;
	void	*mlx;
	void	*mlx_window;
	char	*map_path;
}t_data;

int		ft_count_chars(void);
int		ft_check_border(t_data *data);
int		ft_set_map(t_data *data);
void	ft_draw_map(t_data *data);
int		validate_map(t_data *data);
int		validate_map_player(t_data *data);
int		ft_move_hook(int keycode, t_data *data);
int		ft_hook(int keycode, t_data *data);
void	ft_move_player(t_data *data, int direction);
int		ft_check_map_shape(t_data *data);
int		ft_check_map_values(t_data *data);
int		ft_destroy(t_data *data);
void	ft_count_lines(t_data *data, int fd);
char	*ft_strstr(char *str, char *to_find);
int		ft_check_argument(t_data *data);

#endif