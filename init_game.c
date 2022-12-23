/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:50:02 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/23 18:33:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_mlx(t_data *data)
{    
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
    {
        free_struct(data);
        free(data);             // how can I put this in the upper function
        error_msg("Couldn't find mlx pointer!");
        exit(EXIT_FAILURE);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->columns * IMG_WIDTH, data->rows * IMG_HEIGHT, "so_long");
    if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
        free_struct(data);
        free(data);
		error_msg("Couldn't create the Window!");
        exit(EXIT_FAILURE);
	}
    mlx_loop(data->mlx_ptr);  // ggf. woanders hin
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		error_msg("Couldn't find a sprite!");
	return (sprite);
}

void    init_sprites(t_data *data)
{
	void	*mlx;

	mlx = data->mlx_ptr;
	data->wall = ft_new_sprite(mlx, WALL_XPM);
	data->floor = ft_new_sprite(mlx, FLOOR_XPM);
	data->cherry = ft_new_sprite(mlx, CHERRY_XPM);
	data->player_front = ft_new_sprite(mlx, PLAYER_FRONT_XPM);
	data->player_left = ft_new_sprite(mlx, PLAYER_LEFT_XPM);
	data->player_right = ft_new_sprite(mlx, PLAYER_RIGHT_XPM);
	data->player_back = ft_new_sprite(mlx, PLAYER_BACK_XPM);
	data->map_exit = ft_new_sprite(mlx, EXIT_XPM);
}
