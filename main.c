/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:24:48 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/11 19:16:01 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>          // für printf, muss noch raus

void	dot_ber_check(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]) - 1;
	if (argv[1][i - 3] == '.' && argv[1][i - 2] == 'b' && argv[1][i - 1] == 'e' && argv[1][i] == 'r')
		return ;
	else
	{
		printf("Map format should be .ber\n"); // write fkt
		exit(EXIT_FAILURE);
	}
}

void	argc_check(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error, try: ./so_long [path map]\n");   // write fkt
		exit(EXIT_FAILURE);
	}
	dot_ber_check(argv);
}

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

    argc_check(argc, argv);
    data = ft_calloc(1, sizeof(t_data));
    if (!data)
    {
        printf("Couldn't malloc structure\n");  // write fkt
		exit(EXIT_FAILURE);
    }
    read_the_map(data, argv);
    //check_map(data);
    free_struct(data);   // do I need this????
    free(data); // kann man das noch besser verbauen?
}
