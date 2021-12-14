#include <mlx.h>
#include "so_long.h"

///// put pixel dyali
/* typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;
 */

/* void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
} */
 void ft_draw_img(t_game *game, char c, int i, int j)
{
    int h;
    int w;
    void *img;
    char *file;
    file = NULL;
    if(c == 'P')
        file = SPODY;
    if(c == 'C')
        file = SOPU;
    if(c == '0')
        file = BACKGROUND;
    if(c == '1')
        file = WALL;
    if(c == 'E')
        file = WALL;
    
    img  = mlx_xpm_file_to_image(game->mlx->mlx, file, &w, &h);
    w = BLOCK_SIZE * i;
    h = BLOCK_SIZE * j;
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->mlx_window,img, w,h);
    mlx_destroy_image(game->mlx->mlx, img);
}
void ft_draw_map(t_game *game)
{
    int i = 0;
    int j = 0;
    int lines_count = ft_count_lines();
    int chars_count = ft_count_lines();
    char **map;
    map = ft_getmap();
    while (i < lines_count)
    {
        while (j < chars_count)
        {
            ft_
            j++;
        }
        
        i++;
    }
    
    



}

int main()
{
   

  /*   void *instance;
  //  t_data image;
    char *relative_path = "assets/wall.xpm";
    void *img;
    int img_width;
    int img_height;

    instance = (void *)mlx_init();
    img = mlx_xpm_file_to_image(instance, relative_path, &img_width, &img_height);
    void *mlx = mlx_new_window(instance, 1080, 720, "a7a");
    //image.img = mlx_new_image(instance, 1920, 1080);
    //image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    //my_mlx_pixel_put(&image, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(instance, mlx, img, 100, 20);
    mlx_put_image_to_window(instance, mlx, img, 330, 20);
    mlx_put_image_to_window(instance, mlx, img, 530, 20);
    mlx_loop(instance);  */
}
