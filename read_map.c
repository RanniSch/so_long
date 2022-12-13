/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:45:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/13 08:29:55 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>          // für printf, muss noch raus

int open_file(t_data *data, char **argv)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        free_struct(data);
        //missing something here    
    }
    return(fd);
}

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
        printf("File is empty\n");  // write fkt
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

void    error_square(t_data *data)
{
    if (data->columns == data->rows)
    {
        printf("Map should be rectangular!\n"); // muss noch in write fkt
        free_struct(data); // free struct?
        exit(EXIT_FAILURE);   // davor noch free(line); free(data)
    }
}

void    error_columns(t_data *data, int fd, int i)
{
    char    *line;

    while (i++ < (data->rows) - 1)
    {
        line = get_next_line(fd);
        if (data->columns != ft_strlen(line) - 1)  // alle lines bis auf die letzte haben ein "\n"
        {
            printf("Each line should have same length!\n"); // muss noch in write fkt
            free(line);
            close(fd);
            free_struct(data); // free struct?
            exit(EXIT_FAILURE);   // davor noch free(line); free(data)
        }
        free(line);
    }
    line = get_next_line(fd);
    if (data->columns != ft_strlen(line))
        {
            printf("Each line should have same length!\n"); // muss noch in write fkt
            free(line);
            close(fd);
            free_struct(data); // free struct?
            exit(EXIT_FAILURE);   // davor noch free(line); free(data)
        }
    free(line);
}

void 	allocate_map_memory(t_data *data, int fd)
{
	data->map = ft_calloc(data->rows + 1, sizeof(char *));  // why "+ 1"? without segmentation fault, but why?
	if (!data->map)
	{
		free_struct(data);      // free data?
        close(fd);
		printf("Couldn't malloc data->map\n"); // write fkt
		exit(EXIT_FAILURE);
	}
}

void    read_the_map(t_data *data, char **argv)
{
    int     fd;
    char    *line;
    int     i;

    i = 0;
    count_col_rows(data, argv);
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
