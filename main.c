/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:24:48 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 14:22:23 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* checks if given map file has correct format */
void	dot_ber_check(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]) - 1;
	if (argv[1][i - 3] == '.' && argv[1][i - 2] == 'b' && argv[1][i - 1] == 'e' && argv[1][i] == 'r')
		return ;
	else
	{
		error_msg("Map format should be .ber");
		exit(EXIT_FAILURE);
	}
}

/* checks if there are only two arguments (executable + path map)*/
void	argc_check(int argc, char **argv)
{
	if (argc != 2)
	{
		error_msg("Try: ./so_long [path map]");
		exit(EXIT_FAILURE);
	}
	dot_ber_check(argv);
}

/* sets all variables to zero before used */
void	ft_init_vars(t_data *data)
{
	//data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->wall_xpm = NULL;
	data->floor_xpm = NULL;
	data->cherry_xpm = NULL;
    data->map_exit_xpm = NULL;
    data->gran_xpm = NULL;
    //data->gran[4] = NULL;
    //data->player_left_xpm = NULL;
    //data->player_right_xpm = NULL;
    //data->rows = 0;
	//data->columns = 0;
	//data->collectible = 0;
	//data->player = 0;
	//data->exit = 0;
	//data->player_row_pos = 0;
    //data->player_col_pos = 0;
    //data->img_wh = 0;
    data->steps = 0;
    data->collected = 0;
}

/* frees each entry of the 2D map if it exists */
void    free_struct(t_data *data)
{
    int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->rows)
		{
			free(data->map[i]);
			i++;
            //printf("i %d rows %d\n", i, data->rows);
		}
		free(data->map);
	}
	free(data);
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
        error_msg("Couldn't malloc structure");
		exit(EXIT_FAILURE);
    }
    ft_init_vars(data);
    read_the_map(data, argv);
    check_the_map(data);
    printf("columns %d\n", data->columns);
    printf("rows %d\n", data->rows);
    printf("player row %d\n", data->player_row_pos);
    printf("player col %d\n", data->player_col_pos);
    ft_init_graphics(data);
    //free_struct(data);   // do I need this????
}
