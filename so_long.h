/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/23 18:39:54 by rschlott         ###   ########.fr       */
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

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 			'E'

# define WALL_XPM			"./imgs/sprites/wall.xpm"
# define FLOOR_XPM			"./imgs/sprites/floor.xpm"
# define CHERRY_XPM			"./imgs/sprites/cherry.xpm"
# define PLAYER_FRONT_XPM	"./imgs/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM	"./imgs/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM	"./imgs/sprites/player/right.xpm"
# define PLAYER_BACK_XPM	"./imgs/sprites/player/back.xpm"
# define EXIT_XPM			"./imgs/sprites/exit.xpm"

typedef struct s_image
{
	void	*xpm_ptr;
	int				x;
	int				y;
}						t_image;

typedef struct s_data
{
	char    **map;
	void	*mlx_ptr;
	void	*win_ptr;
	int             rows;
	int             columns;
	int             player;
	int             collectible;
	int             exit;
	int				player_row_pos;
	int				player_col_pos;
	t_image			wall;
	t_image			floor;
	t_image			cherry;
	t_image			map_exit;
	t_image			player_front;
	t_image			player_back;
	t_image			player_left;
	t_image			player_right;
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

void	init_mlx(t_data *data);
void    init_sprites(t_data *data);
t_image	ft_new_sprite(void *mlx, char *path);

int		main(int argc, char **argv);

#endif