/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:54:12 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 15:59:40 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* For every possible path player can go (including "C" and "E")
in marked '0' turns to '1' */
void	mark_path(t_data *data, int row, int column, int **marked)
{
	if ((row < 0 || row >= data->rows) && (column < 0 \
			|| column >= data->columns))
	{
		return ;
	}
	if (data->map[row][column] != '1' && marked[row][column] != 1)
	{
		marked[row][column] = 1;
		mark_path(data, row, column + 1, marked);
		mark_path(data, row, column - 1, marked);
		mark_path(data, row + 1, column, marked);
		mark_path(data, row - 1, column, marked);
	}
}

/* Checks the whole map again but only counts exit and collectible
if at the same position in marked is a '1'.
Then compares this amount with the original amount of fkt count_p_c_e(data) */
int	check_path(t_data *data, int **marked)
{
	int	row;
	int	column;
	int	ex;
	int	col;

	row = -1;
	ex = 0;
	col = 0;
	while (data->map[++row])
	{
		column = -1;
		while (data->map[row][++column])
		{
			if ((data->map[row][column] == 'E') && (marked[row][column]))
				ex++;
			if ((data->map[row][column] == 'C') && (marked[row][column]))
				col++;
		}
	}
	if ((ex + col) == (data->collectible + 1))
		return (1);
	error_msg("Check map paths for collectibles and exit!");
	return (0);
}

/* mallocs a 2D structure called marked which has same dimensions as map,
	but only filled with '0' */
int	ispath(t_data *data)
{
	int	**marked;
	int	valid;
	int	i;

	i = 0;
	valid = 1;
	marked = (int **)ft_calloc(data->rows, sizeof(int *));
	while (i < data->rows)
	{
		marked[i] = (int *)ft_calloc(data->columns, sizeof(int));
		i++;
	}
	mark_path(data, data->player_row_pos, data->player_col_pos, marked);
	valid = check_path(data, marked);
	while (--i >= 0)
		free(marked[i]);
	free(marked);
	return (valid);
}
