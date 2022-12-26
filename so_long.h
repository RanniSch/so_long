/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 14:34:09 by rschlott         ###   ########.fr       */
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
#  define ESC_KEY 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_A 97
# endif

typedef struct s_data
{
	char    **map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win;
	void	*wall_xpm;
	void	*floor_xpm;
	void	*cherry_xpm;
	void	*map_exit_xpm;
	void	*gran_xpm;
	//void	*gran_left;
	//void	*gran[1];
	char	last_pos;
	int             rows;
	int             columns;
	int             player;
	int             collectible;
	int             exit;
	int				player_row_pos;
	int				player_col_pos;
	int				img_wh;
	int				steps;
	int				collected;
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
void    ft_init_graphics(t_data *data);

int		free_destroy(t_data *data);
void    pause_five_sec(void);
void    is_exit(t_data *data, int row, int column);
void	change_position(t_data *data, int row, int column);
void	move_wiz(t_data *data, int row, int column);
int		ft_key_hook(int keycode, t_data *data);

int		main(int argc, char **argv);

#endif