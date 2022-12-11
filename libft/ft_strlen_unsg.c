/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:33:39 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/11 18:30:00 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlen_unsg(const char *s)
{
	int	count;

	count = 0;
	while (*(s + count) != '\0')
		count++;
	return (count);
}
