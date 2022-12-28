/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:45:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/28 16:34:26 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Converts an xpm file to a new image instance.
loads the images and defined pointer points to given image */
void	load_images(t_data *data)
{
	data->wall_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/wall.xpm", &data->img_wh, &data->img_wh);
	data->floor_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/floor.xpm", &data->img_wh, &data->img_wh);
	data->cherry_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/cherry.xpm", &data->img_wh, &data->img_wh);
	data->map_exit_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/exit.xpm", &data->img_wh, &data->img_wh);
	data->gran_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/player/front.xpm", &data->img_wh, &data->img_wh);
}

/* Puts an image to the given window instance at location (x,y) */
void	ft_put_img(t_data *data, void *img, int row, int column)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, SIZE * column, \
			SIZE * row);
}

/* goes through the whole map and asigns letter to certain variable(image) */
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
				ft_put_img(data, data->gran_xpm, row, column);
		}
	}
}

/* mlx_init() = Initializes the MLX library. mlx_new_window initializes a 
window which will stay open (CTRL + C to close in terminal). Returns a 
pointer to the window we have created. We give height, width and a title. 
mlx_hook = alters behaviour; 2 = KeyPress, 1L<<0 = KeyPressMask;
17 = DestroyNotify 1L<<2 = ButtonPressMask. 
mlx_loop = Loops over the given MLX pointer. Each hook that was registered 
prior to this will be called accordingly by order of registration. */
void	ft_init_graphics(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free_struct(data);
		error_msg("Couldn't find mlx pointer!");
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->columns * SIZE, \
			data->rows * SIZE, "Granny_on_a_mission");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		free_struct(data);
		error_msg("Couldn't create the Window!");
		exit(EXIT_FAILURE);
	}
	data->last_pos = '0';
	load_images(data);
	init_map(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, ft_key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 2, free_destroy, data);
	mlx_loop(data->mlx_ptr);
}
