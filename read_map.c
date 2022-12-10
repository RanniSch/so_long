/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:45:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/10 08:46:15 by rschlott         ###   ########.fr       */
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

void    read_the_map(t_data *data, char **argv)
{
    int fd;

    fd = open_file(data, argv);
    printf("%d\n", fd);
}
