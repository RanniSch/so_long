/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:24:48 by rschlott          #+#    #+#             */
/*   Updated: 2022/12/05 15:08:53 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
    void    *mlx;
    //void    *mlx_win;

    mlx = mlx_init();
    mlx_new_window(mlx, 1920, 1080, "Hello World!");
    mlx_loop(mlx);
}
