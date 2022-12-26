/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:44:46 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 15:27:21 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    end_screen(t_data *data)
{
    int row;
    int column;

    row = -1;
    while (++row < data->rows)
    {
        column = - 1;
        while (++column < data->columns)
            ft_put_img(data, data->floor_xpm, row, column);
    }
}

void    pause_five_sec(void)
{
    unsigned int   h;
    unsigned int   i;
    unsigned int   j;
    unsigned int   k;

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

int free_destroy(t_data *data)
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
    //free(data->win_ptr);
	free_struct(data);
	exit(EXIT_FAILURE);
}

void    is_exit(t_data *data, int row, int column)
{
    if (data->collected != data->collectible)
    {
        printf("Granny needs to collect all cherries before she can leave!\n");  // noch ändern!
    }
    else
    {
        change_position(data, row, column);
        printf("Granny WINS!!!\n");
        end_screen(data);
        pause_five_sec();
        free_destroy(data);
    }
}

void	change_position(t_data *data, int row, int column)
{
	if (data->last_pos == '0')
		ft_put_img(data, data->floor_xpm, data->player_row_pos, data->player_col_pos);
	else if (data->last_pos == 'E')
		ft_put_img(data, data->floor_xpm, data->player_row_pos, data->player_col_pos);
	data->map[data->player_row_pos][data->player_col_pos] = data->last_pos;
	ft_put_img(data, data->gran_xpm, row, column);
	data->last_pos = data->map[row][column];
	data->player_row_pos = row;
	data->player_col_pos = column;
	data->steps++;
	printf("steps: %i\tCherries: %i/%i\n", data->steps, data->collected, data->collectible); // noch umschreiben!!!!!
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

/*void	key_hook2(int keycode, t_data *data)
{
	if (keycode == KEY_D)
	{
		if (game->direction != 'R')
		{
			game->wiz_img = game->wiz[0];
			ft_put_img(game, game->wiz_img, game->player[0], game->player[1]);
			game->direction = 'R';
		}
		else
			move_wiz(game, game->player[0], game->player[1] + 1);
	}
	else if (keycode == KEY_A)
	{
		if (game->direction != 'L')
		{
			game->wiz_img = game->wiz[1];
			ft_put_img(game, game->wiz_img, game->player[0], game->player[1]);
			game->direction = 'L';
		}
		else
			move_wiz(game, game->player[0], game->player[1] - 1);
	}
}*/

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		free_destroy(data);
	//else if (keycode == KEY_D || keycode == KEY_A)
	//	key_hook2(keycode, data);
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
