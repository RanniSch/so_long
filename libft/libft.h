/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:52:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/11 18:42:08 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ========================== GNL ============================ */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

int     ft_strlen_gnl(const char *c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlcat_gnl(char *dst, const char *s2, size_t len);
char	*get_next_line(int fd);

/* =========================== libft ========================== */
unsigned int    ft_strlen_unsg(const char *c);
int     ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);

#endif