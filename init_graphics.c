/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:07:15 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/25 12:19:38 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* initializes a window which will stay open (CTRL + C to close in terminal).
Done by mlx_new_window function, which will return a pointer to the window we
have created. We can give the window height, width and a title. 
We then will have to call mlx_loop to initiate the window rendering.*/
void    ft_init_graphics(t_data *data)
{
    t_data    img;
    int x = 10;
    int y = 10;

    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "Hello World!");
    img.img = mlx_new_image(data->mlx_ptr, 1929, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (x < 150 && y < 150)
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
        my_mlx_pixel_put(&img, x + 10, y + 20, 0x0000FF00);
        my_mlx_pixel_put(&img, x * 2, 200, 0x00FFFF00);
        my_mlx_pixel_put(&img, x * 2, 100, 0x00FFFF00);
        my_mlx_pixel_put(&img, 50, y * 2, 0x00FFFF00);
        my_mlx_pixel_put(&img, 200, y * 2, 0x00FFFF00);
        x++;
        y++;
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.img, 0, 0);
	mlx_loop(data->mlx_ptr);
}
