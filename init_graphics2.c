/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:45:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/25 17:12:06 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_data *data)
{
	data->wall_xpm = mlx_xpm_file_to_image(data->mlx_ptr, "./imgs/sprites/wall.xpm", &data->img_wh, &data->img_wh);
	data->floor_xpm = mlx_xpm_file_to_image(data->mlx_ptr, "./imgs/sprites/floor.xpm", &data->img_wh, &data->img_wh);
	data->cherry_xpm = mlx_xpm_file_to_image(data->mlx_ptr, "./imgs/sprites/cherry.xpm", &data->img_wh, &data->img_wh);
	data->map_exit_xpm = mlx_xpm_file_to_image(data->mlx_ptr, "./imgs/sprites/exit.xpm", &data->img_wh, &data->img_wh);
	data->player_front_xpm = mlx_xpm_file_to_image(data->mlx_ptr, "./imgs/sprites/player/front.xpm", &data->img_wh, &data->img_wh);
}

void	ft_put_img(t_data *data, void *img, int row, int column)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, SIZE * column, SIZE * row);
}

void	init_map(t_data *data)
{
	int	row;
	int	column;

	row = -1;
	while (++row < data->rows)
	{
		column = -1;
		while (++column < data->columns)
		{
			if (data->map[row][column] == '1')
				ft_put_img(data, data->wall_xpm, row, column);
			else if (data->map[row][column] == '0')
				ft_put_img(data, data->floor_xpm, row, column);
			else if (data->map[row][column] == 'C')
				ft_put_img(data, data->cherry_xpm, row, column);
			else if (data->map[row][column] == 'E')
				ft_put_img(data, data->map_exit_xpm, row, column);
			else if (data->map[row][column] == 'P')
				ft_put_img(data, data->player_front_xpm, row, column);
		}
	}
}

/* initializes a window which will stay open (CTRL + C to close in terminal).
Done by mlx_new_window function, which will return a pointer to the window we
have created. We can give the window height, width and a title. 
We then will have to call mlx_loop to initiate the window rendering.*/
void    ft_init_graphics(t_data *data)
{
	data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->columns * SIZE, data->rows * SIZE, "grandma_cherry");
    load_images(data);
    init_map(data);
	mlx_loop(data->mlx_ptr);
}
