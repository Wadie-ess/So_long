#include<mlx.h>
///// put pixel dyali 
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	    t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int main()
{
    //int color = 0xABCDEF;
    void *instance;
    t_data image;
    char	*relative_path = "main.xpm";
    void *img;
    int		img_width ;
	int		img_height;
    

    
    instance = (void *)mlx_init();
    img = mlx_xpm_file_to_image(instance, relative_path, &img_width, &img_height);
    void *mlx = mlx_new_window(instance, 1080,720, "a7a");
    //image.img = mlx_new_image(instance, 1920, 1080);
    //image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    //my_mlx_pixel_put(&image, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(instance,mlx,img, 100, 20);
    mlx_put_image_to_window(instance,mlx,img, 330, 20);
    mlx_put_image_to_window(instance,mlx,img, 530, 20);
    mlx_loop(instance);
}


