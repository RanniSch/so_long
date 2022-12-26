/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:20:01 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 16:21:02 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* checks if map is a square */
void	error_square(t_data *data)
{
	if (data->columns == data->rows)
	{
		error_msg("Map should be rectangular!");
		free_struct(data);
		exit(EXIT_FAILURE);
	}
}

/* checks if each line of the map has the same length */
void	error_columns(t_data *data, int fd, int i)
{
	char	*line;

	while (i++ < (data->rows) - 1)
	{
		line = get_next_line(fd);
		if (data->columns != ft_strlen(line) - 1)
		{
			error_msg("Each line should have same length!");
			free(line);
			close(fd);
			free_struct(data);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	line = get_next_line(fd);
	if (data->columns != ft_strlen(line))
	{
		error_msg("Each line should have same length!");
		free(line);
		close(fd);
		free_struct(data);
		exit(EXIT_FAILURE);
	}
	free(line);
}
