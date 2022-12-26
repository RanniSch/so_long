/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:51 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 17:24:17 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <mlx.h>

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
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win;
	void	*wall_xpm;
	void	*floor_xpm;
	void	*cherry_xpm;
	void	*map_exit_xpm;
	void	*gran_xpm;
	char	last_pos;
	int		rows;
	int		columns;
	int		player;
	int		collectible;
	int		exit;
	int		player_row_pos;
	int		player_col_pos;
	int		img_wh;
	int		steps;
	int		collected;
}			t_data;

/* ========= messages.c: write in terminal ================ */
void		error_msg(char *msg);
void		message(char *msg);
void		game_score(int game_steps, int cherry_collected, int cherry_all);

/* ========= main.c: sets variables to "0" or NULL ======== */
void		ft_init_vars(t_data *data);

/* ======= main.c: first map checks & free function ======= */
void		dot_ber_check(char **argv);
void		argc_check(int argc, char **argv);
void		free_struct(t_data *data);
int			main(int argc, char **argv);

/* === read_map.c: opens map, counts & allocates memory === */
int			open_file(t_data *data, char **argv);
void		count_col_rows(t_data *data, char **argv);
void		allocate_map_memory(t_data *data, int fd);
void		read_the_map(t_data *data, char **argv);

/* ======== read_map_2.c: checks map for errors =========== */
void		error_square(t_data *data);
void		error_columns(t_data *data, int fd, int i);

/* ======== check_map.c: checks map for errors ============ */
void		check_0_1_p_c_e(t_data *data);
void		check_walls(t_data *data);
void		count_p_c_e(t_data *data);
void		check_p_c_e(t_data *data);
void		check_the_map(t_data *data);

/* ======== check_map_2.c: checks map for valid path ====== */
void		mark_path(t_data *data, int row, int column, int **marked);
int			check_path(t_data *data, int **marked);
int			ispath(t_data *data);

/* == init_graphics.c: loads imgs & connects to variable == */
void		load_images(t_data *data);
void		ft_put_img(t_data *data, void *img, int row, int column);
void		init_map(t_data *data);
void		ft_init_graphics(t_data *data);

/* ========= moves.c: granny walks with w, a, s, d ======== */
void		change_position(t_data *data, int row, int column);
void		move_wiz(t_data *data, int row, int column);
int			ft_key_hook(int keycode, t_data *data);

/* ======= end_game.c: playful ending of game ============= */
void		end_screen(t_data *data);
void		pause_five_sec(void);
int			free_destroy(t_data *data);
void		is_exit(t_data *data, int row, int column);

#endif