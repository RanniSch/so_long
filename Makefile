# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 12:16:29 by rschlott          #+#    #+#              #
#    Updated: 2022/12/11 19:02:42 by rschlott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========= compilation ==============
NAME			= so_long
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

HEADER			= so_long.h

SRCS			= main.c read_map.c check_map.c

OBJS			= ${SRCS:.c=.o}

LIBFT			= ./libft/libft.a

# ============== rules ================
all:			${NAME}

$(NAME):		${OBJS}
				$(MAKE) -C libft
				${CC} -o $(NAME) ${CFLAGS} ${OBJS} $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#				${CC} -o $(NAME) ${CFLAGS} -lXext -lX11 -lm -lz

clean:
				$(MAKE) clean -C libft
				$(RM) $(OBJS)

fclean:			clean
				$(MAKE) fclean -C libft
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re


#NAME := so_long

#CC := gcc

#CFLAGS := -Wall -Wextra -Werror -Iheaders/

#SOURCE := main.c
#LIBRARY := -Lminilibx-linux -lmlx
#MINILIBX := minilibx-linux/

#all:
#	make -C $(MINILIBX)
#	$(CC) $(CFLAGS) $(SOURCE) $(LIBRARY) -o $(NAME)

#clean:

#fclean: clean
#		make clean -C $(MINILIBX)
#		rm -rf $(NAME)

#re: fclean all