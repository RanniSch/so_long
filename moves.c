/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:44:46 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 17:23:44 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_position(t_data *data, int row, int column)
{
	if (data->last_pos == '0')
		ft_put_img(data, data->floor_xpm, data->player_row_pos, \
				data->player_col_pos);
	else if (data->last_pos == 'E')
		ft_put_img(data, data->floor_xpm, data->player_row_pos, \
				data->player_col_pos);
	data->map[data->player_row_pos][data->player_col_pos] = data->last_pos;
	ft_put_img(data, data->gran_xpm, row, column);
	data->last_pos = data->map[row][column];
	data->player_row_pos = row;
	data->player_col_pos = column;
	data->steps++;
	game_score(data->steps, data->collected, data->collectible);
}

void	move_wiz(t_data *data, int row, int column)
{
	if (data->map[row][column] == '1')
		return ;
	else if (data->map[row][column] == '0' || data->map[row][column] == 'C')
	{
		if (data->map[row][column] == 'C')
		{
			data->map[row][column] = '0';
			data->collected++;
		}
		change_position(data, row, column);
	}
	else if (data->map[row][column] == 'E')
		is_exit(data, row, column);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		free_destroy(data);
	else if (keycode == KEY_D)
		move_wiz(data, data->player_row_pos, data->player_col_pos + 1);
	else if (keycode == KEY_A)
		move_wiz(data, data->player_row_pos, data->player_col_pos - 1);
	else if (keycode == KEY_W)
		move_wiz(data, data->player_row_pos - 1, data->player_col_pos);
	else if (keycode == KEY_S)
		move_wiz(data, data->player_row_pos + 1, data->player_col_pos);
	return (0);
}
