# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 12:16:29 by rschlott          #+#    #+#              #
#    Updated: 2022/12/05 15:04:03 by rschlott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME			:= so_long

# ========= compilation ==============
CC				:= gcc
NAME			:= so_long
CFLAGS			:= -Wall -Wextra -Werror
#CFLAGS			:= -Wall -Wextra -Werror -L/usr/include -Lminilibx_Linux.a -O3 -c $< -o $@
#LIBFLAGS		:= libmlx_Linux.a
RM				:= rm -f

HEADER			:= so_long.h
SRCS			:= main.c

OBJS			:= ${SRCS:.c=.o}

# ============== rules ================
all:			${NAME}

$(NAME):		${OBJS}
				${CC} -o $(NAME) ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#				${CC} -o $(NAME) ${CFLAGS} -lXext -lX11 -lm -lz

clean:
				$(RM) $(OBJS)

fclean:			clean
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