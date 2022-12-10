/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/09 20:41:55 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
#include "./libft/libft.h"

// for open function
#include <fcntl.h>

typedef struct s_data
{
	char    **map;
	int             rows;
	int             columns;
	int             player;
	int             collectible;
	int             exit;
}                       t_data;

void    read_the_map(t_data *data, char **argv);
int		open_file(t_data *data, char **argv);
void    ft_free(char **str);
void    free_struct(t_data *data);

#endif