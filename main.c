/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:24:48 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/09 20:53:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    str = NULL;
}

void    free_struct(t_data *data)
{
    if (data->map)
    {
        ft_free(data->map);
    }
}

/* Compile so_long: make; ./so_long [path map]
argc == 2; argv is the map and get_next_line takes infos out of map
Erstes argv ist Program name, second argv is path as string variable which
goes to my map; I hand path to open function; opens it and returns the fd;
with that I can use the get_next_line */
int main(int argc, char **argv)
{
    t_data  *data;

    (void) argc;
    data = ft_calloc(1, sizeof(t_data));
    //if (!data)
    //{
    //    
    //}
    read_the_map(data, argv);
    //check_map(data);
    free_struct(data);
}
