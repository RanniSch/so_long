/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:02:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 15:39:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* checks if there are only 1, 0, P, C, E in the map */
void    check_0_1_p_c_e(t_data *data)
{
    int row;
    int column;

    row = 0;
    while(data->map[row])
    {
        column = 0;
        while(data->map[row][column])
        {
            if (!ft_strchr("01PCE", data->map[row][column]))
            {
                free_struct(data);
                error_msg("Only 01PCE chars are allowed!");
                exit(EXIT_FAILURE);
            }
            column++;
        }
        row++;
    }
}

/* checks if there are only '1' in first, last row and column */
void    check_walls(t_data *data)
{
    int row;
    int column;

    row = -1;
    column = -1;
    while(++column < data->columns)
    {
        if((data->map[0][column] != '1') || (data->map[data->rows - 1][column] != '1'))
        {
            free_struct(data);
            error_msg("Horizontal walls have a leak!");
            exit(EXIT_FAILURE);
        }
    }
    while(++row < data->rows)
    {
        if((data->map[row][0] != '1') || (data->map[row][data->columns-1] != '1'))
        {
            free_struct(data);
            error_msg("Vertical walls have a leak!");
            exit(EXIT_FAILURE);
        }
    }
}

/* counts amount of collectibles, players and exits */
void    count_p_c_e(t_data *data)
{
    int row;
    int column;

    row = -1;
    while(data->map[++row])
    {
        column = -1;
        while(data->map[row][++column])
        {
            if(data->map[row][column] == 'P')
            {
                data->player++;
                data->player_row_pos = row;
                data->player_col_pos = column;
            }
            else if(data->map[row][column] == 'C')
                data->collectible++;
            else if(data->map[row][column] == 'E')
                data->exit++;
        }
    }
}

/* checks if there is min one collectible, one player and one exit */
void    check_p_c_e(t_data *data)
{
    count_p_c_e(data);
    if (data->player != 1 || data->exit != 1)
    {
        free_struct(data);
        error_msg("Map must have one player and one exit!");
        exit(EXIT_FAILURE);
    }
    if (data->collectible < 1)
    {
        free_struct(data);
        error_msg("Map needs to have at least one collectible!");
        exit(EXIT_FAILURE);
    }
}

/* For every possible path player can go (including "C" and "E") in marked '0' turns to '1' */
void    mark_path(t_data *data, int row, int column, int **marked)
{
    if ((row < 0 || row >= data->rows) && (column < 0 || column >= data->columns))
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

/* Checks the whole map again but only counts exit and collectible if at the same position in marked is a '1'.
Then compares this amount with the original amount of fkt count_p_c_e(data) */
int check_path(t_data *data, int **marked)
{
    int row;
    int column;
    int ex;
    int col;

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

/* mallocs a 2D structure called marked which has same dimensions as map, but only filled with '0' */
int ispath(t_data *data)
{
    int **marked;
    int valid;
    int i;

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

/* runs above functions in the following order */
void    check_the_map(t_data *data)
{
    check_0_1_p_c_e(data);
    check_walls(data);
    check_p_c_e(data);
    if (ispath(data) != 1)
    {
        free_struct(data);
        exit(EXIT_FAILURE);
    }
}
