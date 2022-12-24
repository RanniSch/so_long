/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:54:39 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/24 13:46:40 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_sprite(t_data *data, t_image sprite, int row, int column)
{
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, sprite.xpm_ptr, column * sprite.x, row * sprite.y);
}

void	ft_render_player(t_data *data, int y, int x)
{
	if (data->player_sprite == FRONT)
		ft_render_sprite (data, data->player_front, y, x);
	if (data->player_sprite == LEFT)
		ft_render_sprite (data, data->player_left, y, x);
	if (data->player_sprite == RIGHT)
		ft_render_sprite (data, data->player_right, y, x);
	if (data->player_sprite == BACK)
		ft_render_sprite (data, data->player_back, y, x);
}

void	ft_identify_sprite(t_data *data, int y, int x)
{	
	char	parameter;

	parameter = data->map[y][x];
	if (parameter == WALL)
		ft_render_sprite (data, data->wall, y, x);
	else if (parameter == FLOOR)
		ft_render_sprite (data, data->floor, y, x);
	else if (parameter == CHERRY)
		ft_render_sprite (data, data->cherry, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (data->collectible == 0)     // das muss noch gezählt werden!
			ft_render_sprite (data, data->map_exit, y, x);
	}
	else if (parameter == PLAYER)
		ft_render_player (data, y, x);
}

int	ft_render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			ft_identify_sprite(data, y, x);
			x++;
		}
		y++;
	}
	//ft_print_movements(data);
	return (0);
}