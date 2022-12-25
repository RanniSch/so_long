/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:45:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/25 17:37:12 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* opens the given map file. */
int open_file(t_data *data, char **argv)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        free_struct(data);
        error_msg("Couldn't open the file!");
		exit(EXIT_FAILURE);    
    }
    return(fd);
}

/* counts rows and columns of the given map */
void    count_col_rows(t_data *data, char **argv)
{
    char    *line;
    int     fd;

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

/* checks if map is a square */
void    error_square(t_data *data)
{
    if (data->columns == data->rows)
    {
        error_msg("Map should be rectangular!");
        free_struct(data); // free struct?
        free(data);
        exit(EXIT_FAILURE);   // davor noch free(line); free(data)
    }
}

/* checks if each line of the map has the same length */
void    error_columns(t_data *data, int fd, int i)
{
    char    *line;

    while (i++ < (data->rows) - 1)
    {
        line = get_next_line(fd);
        if (data->columns != ft_strlen(line) - 1)  // alle lines bis auf die letzte haben ein "\n"
        {
            error_msg("Each line should have same length!");
            free(line);
            close(fd);
            free_struct(data); // free struct?
            free(data);
            exit(EXIT_FAILURE);   // davor noch free(line); free(data)
        }
        free(line);
    }
    line = get_next_line(fd);
    if (data->columns != ft_strlen(line))
        {
            error_msg("Each line should have same length!");
            free(line);
            close(fd);
            free_struct(data); // free struct?
            exit(EXIT_FAILURE);   // davor noch free(line); free(data)
        }
    free(line);
}

/* allocates the memory for the 2D map pointer */
void 	allocate_map_memory(t_data *data, int fd)
{
	data->map = ft_calloc(data->rows + 1, sizeof(char *));  // why "+ 1"? without segmentation fault, but why?
	if (!data->map)
	{
		free_struct(data);      // free data?
        close(fd);
		error_msg("Couldn't malloc data->map");
		exit(EXIT_FAILURE);
	}
}

/* runs above functions in the following order */
void    read_the_map(t_data *data, char **argv)
{
    int     fd;
    char    *line;
    int     i;

    i = 0;
    count_col_rows(data, argv);
    //printf("columns %d\n", data->columns);
    //printf("rows %d\n", data->rows);
    error_square(data);
    fd = open_file(data, argv);
    error_columns(data, fd, i);
    close (fd);
    allocate_map_memory(data, fd);
    fd = open_file(data, argv);
    line = get_next_line(fd);
    while(line)
    {
        data->map[i] = ft_strtrim(line, "\n");      // in dieser Funktion wird an verschiedenen Stellen memory allociert
        free(line);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    close(fd);
}
