/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 08:23:11 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/25 11:00:05 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_data *data)
{
	data->wall_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/wall.xpm", &data->img_wh, &data->img_wh);
	data->floor_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/floor.xpm", &data->img_wh, &data->img_wh);
	data->cherry_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/cherry.xpm", &data->img_wh, &data->img_wh);
	data->exit_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/exit.xpm", &data->img_wh, &data->img_wh);
    data->player_front_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/player/front.xpm", &data->img_wh, &data->img_wh);
	data->player_back_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/player/back.xpm", &data->img_wh, &data->img_wh);
	data->player_left_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/player/left.xpm", &data->img_wh, &data->img_wh);
    data->player_right_xpm = mlx_xpm_file_to_image(data->mlx_ptr, \
			"./imgs/sprites/player/right.xpm", &data->img_wh, &data->img_wh);
	/*if (game->player[1] <= (game->cols / 2))
	{
		game->wiz_img = game->wiz[0];
		game->direction = 'R';
	}
	else if (game->player[1] > (game->cols / 2))
	{
		game->wiz_img = game->wiz[1];
		game->direction = 'L';
	}*/
}

void	ft_put_img(t_data *data, void *img, int row, int column)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			img, column * SIZE, row * SIZE);
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
			else if (data->map[row][column] == 'P')
				ft_put_img(data, data->player_front_xpm, row, column);
			else if (data->map[row][column] == 'E')
				ft_put_img(data, data->exit_xpm, row, column);
		}
	}
}

void	launch_graphics(t_data *data)
{
	data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
    {
        free_struct(data);
        free(data);             // how can I put this in the upper function
        error_msg("Couldn't find mlx pointer!");
        exit(EXIT_FAILURE);
    }
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->columns * SIZE, data->rows * SIZE, "grandma_cherry");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
        free_struct(data);
        free(data);
		error_msg("Couldn't create the Window!");
        exit(EXIT_FAILURE);
	}
    //data->last_pos = '0';
	load_images(data);
	init_map(data);
	//ft_printf("Steps: %i\tHerbs: %i/%i\n", game->steps, game->herbs, game->collected);
	//mlx_hook(game->win, 2, 1L << 0, ft_key_hook, game);
	//mlx_hook(game->win, 17, 1L << 2, free_destroy, game);
	mlx_loop(data->mlx_ptr);
}
