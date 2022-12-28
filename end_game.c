/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:13:26 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/28 16:39:30 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* At end of game each image turns to a foor */
void	end_screen(t_data *data)
{
	int	row;
	int	column;

	row = -1;
	while (++row < data->rows)
	{
		column = -1;
		while (++column < data->columns)
			ft_put_img(data, data->floor_xpm, row, column);
	}
}

/* leaves the end screen for a bit before exiting */
void	pause_five_sec(void)
{
	unsigned int	h;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	h = 9000000;
	i = 9000000;
	j = 9000000;
	k = 9000000;
	while (h > 0)
	{
		while (i > 0)
		{
			while (j > 0)
			{
				while (k > 0)
					k--;
				j--;
			}
			i--;
		}
		h--;
	}
}

/* destroys all images, ends loop, destroys window & display */
int	free_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall_xpm);
	mlx_destroy_image(data->mlx_ptr, data->floor_xpm);
	mlx_destroy_image(data->mlx_ptr, data->cherry_xpm);
	mlx_destroy_image(data->mlx_ptr, data->map_exit_xpm);
	mlx_destroy_image(data->mlx_ptr, data->gran_xpm);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_struct(data);
	exit(EXIT_FAILURE);
}

/* lets granny pass through exit after collecting all cherries */
void	is_exit(t_data *data, int row, int column)
{
	if (data->collected != data->collectible)
	{
		message("Granny needs to collect all cherries before she can leave!");
	}
	else
	{
		change_position(data, row, column);
		message("Granny WINS!!!");
		end_screen(data);
		pause_five_sec();
		free_destroy(data);
	}
}
