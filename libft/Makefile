# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 19:02:21 by rschlott          #+#    #+#              #
#    Updated: 2022/12/11 18:42:34 by rschlott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS	=	./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			ft_calloc.c	\
			ft_bzero.c	\
			ft_strlen_unsg.c	\
			ft_strlen.c	\
			ft_strchr.c	\
			ft_substr.c	\
			ft_strtrim.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re