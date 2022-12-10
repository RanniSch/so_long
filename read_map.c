/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:45:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/10 09:03:31 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

void    count_rows(t_data *data, char *line)
{
    if (line)
        data->columns = ft_strlen(line) - 1;
    else
    {
        free(data);
        //missing something here
    }
    printf("%d\n", data->columns);
}

void    read_the_map(t_data *data, char **argv)
{
    int     fd;
    char    *line;

    fd = open_file(data, argv);
    printf("%d\n", fd);
    line = get_next_line(fd);
    count_rows(data, line);
}
