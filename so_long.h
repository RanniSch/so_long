/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/25 16:34:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft/libft.h"

// open function
# include <fcntl.h>
// write
# include <unistd.h>

# ifndef SIZE
#  define SIZE 32
# endif

typedef struct s_data
{
	char    **map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_xpm;
	void	*floor_xpm;
	void	*cherry_xpm;
	void	*map_exit_xpm;
	void	*player_front_xpm;
	int             rows;
	int             columns;
	int             player;
	int             collectible;
	int             exit;
	int				player_row_pos;
	int				player_col_pos;
	int				img_wh;
	//void	*img;
	//char	*addr;
	//int		bits_per_pixel;
	//int		line_length;
	//int		endian;
}                       t_data;

void	error_msg(char *msg);

void	ft_init_vars(t_data *data);

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

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//void    ft_init_graphics(t_data *data);
void	load_images(t_data *data);
void	ft_put_img(t_data *data, void *img, int row, int column);
void	init_map(t_data *data);
//void	init_map(t_data *data, int columns, int rows);
void    ft_init_graphics(t_data *data);
//void    ft_init_graphics(t_data *data, int columns, int rows);

int		main(int argc, char **argv);

#endif