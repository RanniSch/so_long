/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:45:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 16:20:34 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* opens the given map file. */
int	open_file(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free_struct(data);
		error_msg("Couldn't open the file!");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/* counts rows and columns of the given map */
void	count_col_rows(t_data *data, char **argv)
{
	char	*line;
	int		fd;

	fd = open_file(data, argv);
	line = get_next_line(fd);
	if (line)
		data->columns = ft_strlen(line) - 1;
	else
	{
		free(data);
		error_msg("File is empty!");
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->rows++;
	}
	free(line);
	close(fd);
}

/* allocates the memory for the 2D map pointer */
void	allocate_map_memory(t_data *data, int fd)
{
	data->map = ft_calloc(data->rows + 1, sizeof(char *));
	if (!data->map)
	{
		free_struct(data);
		close(fd);
		error_msg("Couldn't malloc data->map");
		exit(EXIT_FAILURE);
	}
}

/* runs above functions in the following order */
void	read_the_map(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	count_col_rows(data, argv);
	error_square(data);
	fd = open_file(data, argv);
	error_columns(data, fd, i);
	close(fd);
	allocate_map_memory(data, fd);
	fd = open_file(data, argv);
	line = get_next_line(fd);
	while (line)
	{
		data->map[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}
