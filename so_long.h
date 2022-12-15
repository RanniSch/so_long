/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/15 11:03:00 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
#include "./libft/libft.h"

// for open function
#include <fcntl.h>
// for write
#include <unistd.h>

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

void	error_msg(char *msg);

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
void	mark_path(t_data *data, int row, int column, int **marked);
int		check_path(t_data *data, int **marked);
int		ispath(t_data *data);
void    check_the_map(t_data *data);

int		main(int argc, char **argv);

#endif