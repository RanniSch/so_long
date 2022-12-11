/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:24:18 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/11 18:35:09 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen_unsg(s1) - 1;
	while (*(s1 + i) != 0 && ft_strchr(set, s1[i]))
		start = (i++) + 1;
	if (start >= ft_strlen_unsg(s1))
		return ((char *)ft_calloc(sizeof(char), 1));
	i = ft_strlen_unsg(s1) - 1;
	while (i != 0 && *(s1 + i) != 0 && ft_strchr(set, s1[i]))
		end = (i--) - 1;
	return (ft_substr(s1, start, end - start + 1));
}
