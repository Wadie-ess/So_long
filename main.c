#include "so_long.h"
#include<mlx.h>
#include "get_next_line.h"
 void	ft_set_map(char *map_path, t_game *game)
{
	int		lines_count;
	int		fd;
	int		i;

	lines_count = 0;
	fd = open(map_path, O_RDONLY);
	while (get_next_line(fd))
		lines_count++;
	game->map = malloc(sizeof(char *) * (lines_count));
	close(fd);
	i = -1;
	fd = open(map_path, O_RDONLY);
	while (++i < lines_count && game->map)
		game->map[i] = get_next_line(fd);
	close(fd);
	game->lines_count = lines_count;
	if (game->map)
		game->chars_count = ft_strlen(game->map[i - 1]);
} 

int main()
{   
    t_game *game;
    t_mlx  *mlx;
    game = malloc(sizeof(t_game));
    mlx = malloc(sizeof(t_mlx));
    int width;
    int height;
    ft_set_map(MAP_PATH, game);
    //char **map = game->map;
   // printf("%d",game->chars_count);
    height = game->lines_count * BLOCK_SIZE;
    width = game->chars_count * BLOCK_SIZE;
    mlx->mlx = mlx_init();
    mlx->mlx_window = mlx_new_window(mlx->mlx,width, height, "a7a");

    ft_draw_map(game->lines_count, game->chars_count, mlx->mlx, mlx->mlx_window);
    mlx_loop(mlx->mlx);

    return (0);  
}