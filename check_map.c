/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:02:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/13 08:59:39 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>          // für printf, muss noch raus

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
                free(data);             // how can I put this in the upper function
                printf("Only 01PCE chars are allowed!\n"); // write fkt
                exit(EXIT_FAILURE);
            }
            column++;
        }
        row++;
    }
}

void    check_walls(t_data *data)
{
    int row;
    int column;

    row = -1;
    column = -1;
    while(data->map[0][++column])
    {
        if((data->map[0][column] != '1') || (data->map[data->rows - 1][column] != '1'))
        {
            free_struct(data);
            free(data);             // how can I put this in the upper function
            printf("Horizontal walls have a leak!\n");   // write fkt
            exit(EXIT_FAILURE);
        }
    }
    while(data->map[++row])
    {
        if((data->map[row][0] != '1') || (data->map[row][data->columns-1] != '1'))
        {
            free_struct(data);
            free(data);             // how can I put this in the upper function
            printf("Vertical walls have a leak!\n");    // write fkt
            exit(EXIT_FAILURE);
        }
    }
}

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

void    check_p_c_e(t_data *data)
{
    count_p_c_e(data);
    if (data->player != 1 || data->exit != 1)
    {
        free_struct(data);
        free(data);     // oben mit rein bauen?
        printf("Map can only have 1 player and one exit!\n"); // write fkt
        exit(EXIT_FAILURE);
    }
    if (data->collectible < 1)
    {
        free_struct(data);
        free(data);
        printf("Map needs to have at least one collectible!\n"); // write fkt
        exit(EXIT_FAILURE);
    }
}

void    check_the_map(t_data *data)
{
    check_0_1_p_c_e(data);
    check_walls(data);
    check_p_c_e(data);
}
