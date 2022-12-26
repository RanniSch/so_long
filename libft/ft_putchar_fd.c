/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:32:34 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 17:30:08 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Outputs the character ’c’ to the given file
descriptor. */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
