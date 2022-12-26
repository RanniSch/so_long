# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 12:16:29 by rschlott          #+#    #+#              #
#    Updated: 2022/12/26 11:11:54 by rschlott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========= compilation ==============
#NAME			= so_long
#CC				= gcc
#CFLAGS			= -Wall -Wextra -Werror
#RM				= rm -f

#HEADER			= so_long.h

#SRCS			= main.c read_map.c check_map.c error_message.c init_game.c

#OBJS			= ${SRCS:.c=.o}

#LIBFT			= ./libft/libft.a

# ============== rules ================
#all:			${NAME}

#$(NAME):		${OBJS}
#				$(MAKE) -C libft
#				${CC} -o $(NAME) ${CFLAGS} ${OBJS} $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#				${CC} -o $(NAME) ${CFLAGS} -lXext -lX11 -lm -lz

#clean:
#				$(MAKE) clean -C libft
#				$(RM) $(OBJS)

#fclean:			clean
#				$(MAKE) fclean -C libft
#				$(RM) $(NAME)

#re:				fclean all

#.PHONY:			all clean fclean re

NAME		:= so_long

CC			:= gcc -g

CFLAGS		:= -Werror -Wextra -Wall -g -fsanitize=address

RM			:= rm -f

HEADER		:= so_long.h

MLX_DIR= ./minilibx-linux/

MLX = ./minilibx-linux/libmlx.a

SRCS		:= main.c read_map.c check_map.c error_message.c init_graphics2.c moves.c

OBJS		:= ${SRCS:.c=.o}

LIBFT 		:= ./libft/libft.a

.PHONY:		all clean fclean re

all:		${NAME}

%.o: %.c	$(LIBFT)
			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c $< -o $@

$(LIBFT):
			make all -C ./libft

$(MLX):
			make -C $(MLX_DIR)


$(NAME):	$(LIBFT) $(MLX) $(OBJS)
			$(CC) $(OBJS) $(LIBFT) $(MLX) -L/usr/X11/lib -lXext -lX11 -o $(NAME)

re:			fclean all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

#NAME		:= so_long

#CC			:= gcc -g

#CFLAGS		:= -Werror -Wextra -Wall -g -fsanitize=address

#RM			:= rm -f

#HEADER		:= so_long.h

#MLX_DIR= ./minilibx-linux/

#MLX = ./minilibx-linux/libmlx.a

#SRCS		:= main.c read_map.c check_map.c error_message.c init_game.c

#OBJS		:= ${SRCS:.c=.o}

#LIBFT 		:= ./libft/libft.a

#.PHONY:		all clean fclean re

#all:		${NAME}

#%.o: %.c	$(LIBFT)
#			$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c $< -o $@

#$(LIBFT):
#			make all -C ./libft

#$(MLX):
#			make -C $(MLX_DIR)


#$(NAME):	$(LIBFT) $(MLX) $(OBJS)
#			$(CC) $(OBJS) $(LIBFT) $(MLX) -L/usr/X11/lib -lXext -lX11 -o $(NAME)
#			make clean


#re:			fclean all

#clean:
#			$(RM) $(OBJS)

#fclean:		clean
#			$(RM) $(NAME)