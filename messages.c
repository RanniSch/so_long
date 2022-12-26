/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:00:27 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/26 17:23:57 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
}

void	message(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void	game_score(int game_steps, int cherry_collected, int cherry_all)
{
	write(2, "Steps: ", 7);
	ft_putnbr_fd(game_steps, 2);
	write(2, "    Cherries: ", 14);
	ft_putnbr_fd(cherry_collected, 2);
	write(2, "/", 1);
	ft_putnbr_fd(cherry_all, 2);
	write(2, "\n", 1);
}
