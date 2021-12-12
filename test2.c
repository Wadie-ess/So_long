#include "mlx.h"
int main()
{

    void *mlx = mlx_init();
    void *window_mlx = mlx_new_window(mlx, 1080, 720, "a7a");
    void *image = mlx_new_image(mlx, 1920, 1080);
    mlx_pixel_put(mlx, window_mlx, 5, 5, 0x00FF0000);

    int pixel_bits;
    int line_bytes;
    int endian;
    char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
    int color = 0xABCDEF;

    if (pixel_bits != 32)
        color = mlx_get_color_value(mlx, color);

    for (int y = 0; y < 360; ++y)
        for (int x = 0; x < 640; ++x)
        {
            int pixel = (y * line_bytes) + (x * 4);

            if (endian == 1) // Most significant (Alpha) byte first
            {
                buffer[pixel + 0] = (color >> 24);
                buffer[pixel + 1] = (color >> 16) & 0xFF;
                buffer[pixel + 2] = (color >> 8) & 0xFF;
                buffer[pixel + 3] = (color)&0xFF;
            }
            else if (endian == 0) // Least significant (Blue) byte first
            {
                buffer[pixel + 0] = (color)&0xFF;
                buffer[pixel + 1] = (color >> 8) & 0xFF;
                buffer[pixel + 2] = (color >> 16) & 0xFF;
                buffer[pixel + 3] = (color >> 24);
            }
        }

    mlx_put_image_to_window(mlx, window_mlx, image, 0, 0);

    mlx_loop(mlx);
}