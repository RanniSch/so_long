/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/13 08:56:28 by rschlott         ###   ########.fr       */
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
	int				player_row_pos;
	int				player_col_pos;
}                       t_data;

void	dot_ber_check(char **argv);
void	argc_check(int argc, char **argv);
int		open_file(t_data *data, char **argv);
void    count_col_rows(t_data *data, char **argv);
void    error_square(t_data *data);
void    error_columns(t_data *data, int fd, int i);
void 	allocate_map_memory(t_data *data, int fd);
void    read_the_map(t_data *data, char **argv);
void    ft_free(char **str);
void    free_struct(t_data *data);

void    check_0_1_p_c_e(t_data *data);
void    check_walls(t_data *data);
void    count_p_c_e(t_data *data);
void    check_p_c_e(t_data *data);
void    check_the_map(t_data *data);

#endif